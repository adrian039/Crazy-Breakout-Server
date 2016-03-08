/*
 * Server.h
 *
 *  Created on: 21 de feb. de 2016
 *      Author: adrian
 */

#ifndef SERVER_H_
#define SERVER_H_

#include<stdio.h>
#include<stdlib.h>
#include<sstream>
#include<string>
#include<netdb.h>
#include<netinet/in.h>
#include<string.h>
#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include"LinkedList1.h"


using namespace std;
//Se crea la variable estatica de tipo LinkedList1 para almacenar los usuarios


class Server {
public:


	static Server* getInstance();
	void Thread();
	Server(){
		};
private:

	static Server* _instance;


	//extern List<Json::Value> *_logUsers=new List<Json::Value>(NULL);

};

#endif /* SERVER_H_ */
