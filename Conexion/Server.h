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
#include"ThreadServer.h"



using namespace std;

class Server {
public:
	Server();
	int sockfd, newsockfd, portno, pid, cliente = 0;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	socklen_t clilen;

};

#endif /* SERVER_H_ */
