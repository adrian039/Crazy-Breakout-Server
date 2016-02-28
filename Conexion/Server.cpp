/*
 * Server.cpp

 *
 *  Created on: 21 de feb. de 2016
 *      Author: adrian
 */
#include"Server.h"
#include "GameLogic.h"


using namespace std;


Server::Server() {
	// TODO Auto-generated constructor stub

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("ERROR opening socket");
		exit(1);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = 8080;

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		perror("ERROR on binding");
		exit(1);
	}

	listen(sockfd, 5);
	clilen = sizeof(cli_addr);
	cout << "Servidor Iniciado..." << endl;

}
int main() {
	Server server;
	GameLogic::Instance();
	ThreadServer thread;
	while (1) {
		server.newsockfd = accept(server.sockfd,
				(struct sockaddr *) &server.cli_addr, &server.clilen);
		server.cliente = server.cliente + 1;
		if (server.newsockfd < 0) {
			perror("ERROR aceptando conexion");
			exit(1);
		}

		server.pid = fork();

		if (server.pid < 0) {
			perror("ERROR on fork");
			exit(1);
		}

		if (server.pid == 0) {

			cout << "Nueva conexion " << server.cliente << endl;
			close(server.sockfd);
			thread.Thread(server.newsockfd, server.cliente);
			exit(0);
		} else {
			close(server.newsockfd);
		}
	}
}

