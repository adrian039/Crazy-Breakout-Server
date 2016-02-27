/*
 * Server.h
 *
 *  Created on: 21 de feb. de 2016
 *      Author: adrian
 */

#ifndef SERVER_H_
#define SERVER_H_

using namespace std;

class Server {
public:
	Server();
	int sockfd, newsockfd, portno, pid, cliente = 0;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	int n;
	socklen_t clilen;
};

#endif /* SERVER_H_ */
