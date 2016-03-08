/*
 * ThreadServer.h
 *
 *  Created on: 21 de feb. de 2016
 *      Author: adrian
 */

#ifndef THREADSERVER_H_
#define THREADSERVER_H_

using namespace std;

class ThreadServer {
public:
	ThreadServer();
	void Thread(int, int, ThreadServer);
	void writeMsg(int, string);
	string Read(int);

};

#endif /* THREADSERVER_H_ */
