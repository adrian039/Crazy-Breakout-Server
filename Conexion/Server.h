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
#include "Jsons.h"


using namespace std;
static LinkedList1<Json::Value> *_logUsers=new LinkedList1<Json::Value>(NULL);

class Server {
public:
	Server();
	int sockfd, newsockfd, portno, pid, cliente = 0;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	socklen_t clilen;

	//extern List<Json::Value> *_logUsers=new List<Json::Value>(NULL);

};

#endif /* SERVER_H_ */
