/*
 * Server.cpp

 *
 *  Created on: 21 de feb. de 2016
 *      Author: adrian
 */

//#include"Server.h"
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

int server_start_listen();
int server_establish_connection(int server_fd);
void mainloop(int server_fd);

const char * PORT = "8080";
const int MAXLEN = 1024;
const int MAXFD = 1000;
const int BACKLOG = 5;
int client = 0;

volatile fd_set the_state;

pthread_mutex_t mutex_state = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t boardmutex = PTHREAD_MUTEX_INITIALIZER;

void *Read1(void *threadData1);
struct threadData {
	int socket;
	int cliente;
};

int main() {
	cout << "Servidor Iniciado...." << endl;
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
	int server_fd;
	int ret;
	int yes = 1;
	memset(&hostinfo, 0, sizeof(hostinfo));

	hostinfo.ai_family = AF_UNSPEC;
	hostinfo.ai_socktype = SOCK_STREAM;
	hostinfo.ai_flags = AI_PASSIVE;
	getaddrinfo(NULL, PORT, &hostinfo, &res);
	server_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	ret = setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
	ret = bind(server_fd, res->ai_addr, res->ai_addrlen);
	if (ret != 0) {
		cout << "error :" << strerror(errno) << endl;
		return -1;
	}
	ret = listen(server_fd, BACKLOG);
	return server_fd;

}

int server_establish_connection(int server_fd) {
	char ipstr[INET6_ADDRSTRLEN];
	int port;
	int new_sd;
	struct sockaddr_storage remote_info;
	socklen_t addr_size;

	addr_size = sizeof(addr_size);
	new_sd = accept(server_fd, (struct sockaddr *) &remote_info, &addr_size);
	client++;
	getpeername(new_sd, (struct sockaddr*) &remote_info, &addr_size);
	if (remote_info.ss_family == AF_INET) {
		struct sockaddr_in *s = (struct sockaddr_in *) &remote_info;
		port = ntohs(s->sin_port);
		inet_ntop(AF_INET, &s->sin_addr, ipstr, sizeof ipstr);
	} else {
		struct sockaddr_in6 *s = (struct sockaddr_in6 *) &remote_info;
		port = ntohs(s->sin6_port);
		inet_ntop(AF_INET6, &s->sin6_addr, ipstr, sizeof ipstr);
	}

	std::cout << "Cliente conectado " << client << " puerto: " << port << endl;

	return new_sd;

}

void mainloop(int server_fd) {
	pthread_t threads[MAXFD];
	FD_ZERO(&the_state);
	while (1) {
		int rfd;
		rfd = server_establish_connection(server_fd);
		if (rfd >= 0) {
			pthread_mutex_lock(&mutex_state);
			FD_SET(rfd, &the_state);
			pthread_mutex_unlock(&mutex_state);
			struct threadData td = { rfd, client };
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
		string data(buffer1);
		if (n < 0) {
			perror("ERROR leyendo el socket");
			exit(1);
		} else if (data.compare("") == 0) {
			cout << "El Cliente " << my_data->cliente << " se ha DESCONECTADO" << endl;
			close(my_data->socket);
			break;
		} else {
			cout << "Mensaje de cliente " << my_data->cliente << ":" << buffer1
					<< endl;
			Protocol::getInstance()->initProtocol(data, my_data->socket);
		}
	}
	return 0;

}

