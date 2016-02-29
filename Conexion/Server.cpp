/*
 * Server.cpp

 *
 *  Created on: 21 de feb. de 2016
 *      Author: adrian
 */
#include"Server.h"
#include "GameLogic.h"
#include"ThreadServer.h"

using namespace std;

Server::Server() {
	// TODO Auto-generated constructor stub
	GameLogic::Instance(); //se instancia la clase GameLogic
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
	//Se inicia el ciclo para que este escuhando por el puerto
	while (1) {
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		cliente = cliente + 1;
		if (newsockfd < 0) {
			perror("ERROR aceptando conexion");
			exit(1);
		}

		pid = fork();

		if (pid < 0) {
			perror("ERROR on fork");
			exit(1);
		}

		if (pid == 0) {
			ThreadServer thread;
			cout << "Nueva conexion " << cliente << endl;
			cout << newsockfd << endl;
			close(sockfd);
			thread.Thread(newsockfd, cliente);
			exit(0);
		} else {
			close(newsockfd);
		}
	}

}
int main() {
	Server server; //se llama a server
}

