/*
 * ThreadServer.h
 *
 *  Created on: 21 de feb. de 2016
 *      Author: adrian
 */

#ifndef THREADSERVER_H_
#define THREADSERVER_H_

#include"Jsons.h"

using namespace std;

class ThreadServer {
public:
	ThreadServer();
	void Thread(int, int);
	void Write(string, int);

};

#endif /* THREADSERVER_H_ */
