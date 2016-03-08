/*
 * ThreadServer.cpp
 *
 *  Created on: 21 de feb. de 2016
 *      Author: adrian
 */

#include<stdio.h>
#include<stdlib.h>
#include <string>
#include <iostream>
#include <boost/thread.hpp>
#include "ThreadServer.h"
#include<pthread.h>
#include "Protocol.h"
#include "IConstants.h"

using namespace std;
using namespace boost;

void *Connect(void *threadData1);
string Read(int pParam);
struct threadData {
	int param1;
	int param2;
	ThreadServer param3;
};

ThreadServer::ThreadServer() {
	// TODO Auto-generated constructor stub

}

void *Connect(void *threadData1) {
	struct threadData *my_data;
	my_data = (struct threadData *) threadData1;
	while (1) {
		string inData = Read(my_data->param1);
		cout << "Mensaje de cliente " << my_data->param1 << ":" << inData
				<< endl;
		Protocol::getInstance()->initProtocol(inData, my_data->param1);
	}

}
void ThreadServer::Thread(int sock, int client, ThreadServer pThread) {
	//Se crea el hilo para read, con el numero de socket y el numero de cliente

	struct threadData td = { sock, client, pThread };
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_t tid;
	pthread_create(&tid, &attr, Connect, (void *) &td);
	pthread_join(tid, NULL);

}

void ThreadServer::writeMsg(int socket, std::string msg) {
	msg = msg + "\n";
	write(socket, msg.data(), msg.length());
	cout << msg.data() << endl;
}
string Read(int pParam) {
	int n;
	char buffer1[256];
	bzero(buffer1, 256);
	n = read(pParam, buffer1, 255);
	if (n < 0) {
		perror("ERROR leyendo el socket");
		exit(1);
	}
	string data(buffer1);
	return data;
}

