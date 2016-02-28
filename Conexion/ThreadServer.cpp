/*
 * ThreadServer.cpp
 *
 *  Created on: 21 de feb. de 2016
 *      Author: adrian
 */

#include "ThreadServer.h"
#include <string>
#include <iostream>
#include <boost/thread.hpp>



using namespace std;
using namespace boost;

void writeMsg(int socket, std::string msg);
struct threadData { int param1; int param2; };

ThreadServer::ThreadServer() {
	// TODO Auto-generated constructor stub

}

void Read(int socks, int client) {
	//struct threadData *myParams = (struct threadData*)thrData;

		int n;
		char buffer1[256];
		bzero(buffer1, 256);
		n = read(socks, buffer1, 255);
		if (n < 0) {
			perror("ERROR leyendo el socket");
			exit(1);
		}
		cout << "Mensaje de cliente " << client << ":" << buffer1 << endl;
		Jsons json1;
		json1.parseJson(buffer1);
		writeMsg(socks, "hola\n");

}
void ThreadServer::Thread(int sock, int client) {

	thread thread_1(Read, sock, client);
	thread_1.join();

	/*struct threadData data = {sock,client};

	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_t tid;
	pthread_create(&tid,&attr,Read,&data);*/


}

void writeMsg(int socket, std::string msg) {
	std::string var;
	cout << "\nServidor: ";
	cin >> var;
	write(socket, var.data(), var.length());
	//write(socket, "\n", 2);
}

