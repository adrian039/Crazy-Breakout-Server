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

using namespace std;
using namespace boost;

void writeMsg(int socket, std::string msg);
struct threadData {
	int param1;
	int param2;
};

ThreadServer::ThreadServer() {
	// TODO Auto-generated constructor stub

}

void *Read(void *threadData1) {
	struct threadData *my_data;
	my_data = (struct threadData *) threadData1;
	while (1) {
		int n;
		char buffer1[256];
		bzero(buffer1, 256);
		n = read(my_data->param1, buffer1, 255);
		if (n < 0) {
			perror("ERROR leyendo el socket");
			exit(1);
		}
		cout << "Mensaje de cliente " << my_data->param2 << ":" << buffer1
				<< endl;
		Jsons json1;
		//Se llama a la funcion parseJson para poder leer el json obtenido del puerto
		json1.parseJson(buffer1, my_data->param1);
		writeMsg(my_data->param1, "hola\n");
	}

}
void ThreadServer::Thread(int sock, int client) {
	//Se crea el hilo para read, con el numero de socket y el numero de cliente

	struct threadData td = { sock, client };
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_t tid;
	pthread_create(&tid, &attr, Read, (void *) &td);
	pthread_join(tid, NULL);

}

void writeMsg(int socket, std::string msg) {
	std::string var;
	cout << "\nServidor: ";
	cin >> var;
	var = var + "\n";
	write(socket, var.data(), var.length());
	//write(socket, "\n", 2);
}

