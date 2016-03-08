/*
 * Server.cpp

 *
 *  Created on: 21 de feb. de 2016
 *      Author: adrian
 */

//#include"Server.h"
#include "GameLogic.h"
#include"ThreadServer.h"
#include"Server.h"

#include <iostream>
#include <cstring> 	// used for memset.
#include <arpa/inet.h> 	// for inet_ntop function
#include <netdb.h>
#include <sys/socket.h>
#include <pthread.h>
#include <vector>
#include <list>
#include <iterator>
#include <sstream>
#include "Protocol.h"

#include <errno.h>

using namespace std;

//server functions
int server_start_listen();
int server_establish_connection(int server_fd);
void mainloop(int server_fd);

//server constants
const char * PORT = "8080"; // port numbers 1-1024 are probably reserved by your OS
const int MAXLEN = 1024;   // Max lenhgt of a message.
const int MAXFD = 1000; // Maximum file descriptors to use. Equals maximum clients.
const int BACKLOG = 5; // Number of connections that can wait in que before they be accept()ted
int client = 0;

// This needs to be declared volatile because it can be altered by an other thread. Meaning the compiler cannot
// optimise the code, because it's declared that not only the program can change this variable, but also external
// programs. In this case, a thread.
volatile fd_set the_state;

pthread_mutex_t mutex_state = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t boardmutex = PTHREAD_MUTEX_INITIALIZER; // mutex locker for the chessboard vector.

void *Read1(void *threadData1);
struct threadData {
	int socket;
	int cliente;
};

int main() {

	cout << "Servidor Iniciado...." << endl; // don not forgfet endl, or it won't display.
	int server_fd = server_start_listen();
	if (server_fd == -1) {
		cout << "An error occured. Closing program.";
		return 1;
	}
	mainloop(server_fd);
	return 0;
}

int server_start_listen() {

	struct addrinfo hostinfo, *res;
	int server_fd; // the fd the server listens on
	int ret;
	int yes = 1;

// first, load up address structs with getaddrinfo():

	memset(&hostinfo, 0, sizeof(hostinfo));

	hostinfo.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
	hostinfo.ai_socktype = SOCK_STREAM;
	hostinfo.ai_flags = AI_PASSIVE;     // fill in my IP for me

	getaddrinfo(NULL, PORT, &hostinfo, &res);

	server_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	//if(server_fd < 0) throw some error;

	//prevent "Error Address already in use"
	ret = setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
	// if(ret < 0) throw some error;

	ret = bind(server_fd, res->ai_addr, res->ai_addrlen);

	if (ret != 0) {
		cout << "error :" << strerror(errno) << endl;
		return -1;
	}

	ret = listen(server_fd, BACKLOG);
	//if(ret < 0) throw some error;

	return server_fd;

}

int server_establish_connection(int server_fd)
// This function will establish a connection between the server and the
// client. It will be executed for every new client that connects to the server.
// This functions returns the socket filedescriptor for reading the clients data
// or an error if it failed.
		{
	char ipstr[INET6_ADDRSTRLEN];
	int port;

	int new_sd;
	struct sockaddr_storage remote_info;
	socklen_t addr_size;

	addr_size = sizeof(addr_size);
	new_sd = accept(server_fd, (struct sockaddr *) &remote_info, &addr_size);
	client++;
	//if (fd < 0) throw some error here;

	getpeername(new_sd, (struct sockaddr*) &remote_info, &addr_size);

	// deal with both IPv4 and IPv6:
	if (remote_info.ss_family == AF_INET) {
		struct sockaddr_in *s = (struct sockaddr_in *) &remote_info;
		port = ntohs(s->sin_port);
		inet_ntop(AF_INET, &s->sin_addr, ipstr, sizeof ipstr);
	} else { // AF_INET6
		struct sockaddr_in6 *s = (struct sockaddr_in6 *) &remote_info;
		port = ntohs(s->sin6_port);
		inet_ntop(AF_INET6, &s->sin6_addr, ipstr, sizeof ipstr);
	}

	std::cout << "Cliente conectado " << client << " puerto: " << port
			<< endl;

	return new_sd;

}

void mainloop(int server_fd)

// This loop will wait for a client to connect. When the client connects, it creates a
// new thread for the client and starts waiting again for a new client.
		{
	pthread_t threads[MAXFD];
	FD_ZERO(&the_state);
	while (1) {
		int rfd;
		rfd = server_establish_connection(server_fd);
		ThreadServer server;
		if (rfd >= 0) {
			pthread_mutex_lock(&mutex_state); // Make sure no 2 threads can create a fd simultanious.
			FD_SET(rfd, &the_state);  // Add a file descriptor to the FD-set.
			pthread_mutex_unlock(&mutex_state); // End the mutex lock
			struct threadData td = { rfd, client };
			// now create a thread for this client to intercept all incomming data from it.
			pthread_create(&threads[rfd], NULL, Read1, (void *) &td);
		}
	}
}

void *Read1(void *threadData1) {
	struct threadData *my_data;
	my_data = (struct threadData *) threadData1;
	while (1) {
		int n;
		char buffer1[256];
		bzero(buffer1, 256);
		n = read(my_data->socket, buffer1, 255);
		if (n < 0) {
			perror("ERROR leyendo el socket");
			exit(1);
		}
		cout << "Mensaje de cliente " << my_data->cliente << ":" << buffer1
				<< endl;
		string data(buffer1);
		Protocol::getInstance()->initProtocol(data,my_data->socket);
		//Se llama a la funcion parseJson para poder leer el json obtenido del puerto


	}

}























