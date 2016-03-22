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
	void initProtocol(string, int, int);
	void send(int, Json::Value);
	void sendAll(Json::Value,int,bool);
	void deletePlayer(int pNumber);
	Protocol() {
		list = new LinkedList1<string>(NULL);
		listBricks= new LinkedList1<Json::Value>(NULL);
	}
	;
private:

	Protocol(Protocol const&) {
		list = new LinkedList1<string>(NULL);
	}
	;
	void initGame(int);
	void newBall(int);
	void deleteBall(int,Json::Value);
	void newBar(int);
	void addPoints(int, Json::Value);
	void changeDir(int,Json::Value);
	void addPlayer(Json::Value, int);
	void addBrick(Json::Value);
    void createBlocks(Json::Value,int);
	void deleteBrick(Json::Value,int);
	static Protocol* _instance;
	void manage(std::string, Json::Value, int);
	LinkedList1<string> *list;
	LinkedList1<Json::Value> *listBricks;

};

#endif /* PROTOCOL_H_ */
