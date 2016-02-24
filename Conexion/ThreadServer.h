/*
 * ThreadServer.h
 *
 *  Created on: 21 de feb. de 2016
 *      Author: adrian
 */

#ifndef THREADSERVER_H_
#define THREADSERVER_H_
#include<string>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
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

using namespace std;

class ThreadServer {
public:
	ThreadServer();
	void Thread(int, int);
	void Write(string, int);

};

#endif /* THREADSERVER_H_ */
