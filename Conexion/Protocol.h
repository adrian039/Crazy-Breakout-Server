/*
 * Protocol.h
 *
 *  Created on: 1 de mar. de 2016
 *      Author: vargas
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_
#include "jsoncpp/json.h"
#include <string>
#include <iostream>
#include "LinkedList1.cpp"
#include "ThreadServer.h"
using namespace std;
class Protocol {
public:
	static Protocol* getInstance();
	void initProtocol(string, int);
private:
	Protocol() {
		list = new LinkedList1<string>(NULL);
	}
	;
	Protocol(Protocol const&) {
		list = new LinkedList1<string>(NULL);
	}
	;
	void initGame(int);
	void newBall(int);
	void newBar(int);
	void addPlayer(Json::Value, int);
	void send(int, Json::Value);
	static Protocol* _instance;
	void manage(std::string, Json::Value, int);
	LinkedList1<string> *list;

};

#endif /* PROTOCOL_H_ */
