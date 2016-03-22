/*
 * Protocol.cpp
 *
 *  Created on: 1 de mar. de 2016
 *      Author: vargas
 */

#include "Protocol.h"
#include<stdio.h>
#include<stdlib.h>
#include <string>
#include <iostream>
#include "IConstants.h"
#include "JsonCodeDecode.h"
#include "GameLogic.h"

Protocol* Protocol::_instance = NULL;

Protocol* Protocol::getInstance() {
	if (!_instance) {
		_instance = new Protocol();

	}
	return _instance;
}
void Protocol::initProtocol(string pData, int pClient, int idClient) {
	Json::Value json = Json_Code_Decode::getInstance()->getJson(pData);
	string function = Json_Code_Decode::getInstance()->getString(json,
			IConstants::getInstance()->K_Function);
	manage(function, json, pClient);

}

void Protocol::manage(std::string pFunction, Json::Value pJson, int pSocket) {
	if (pFunction.compare(IConstants::getInstance()->f_initGame) == 0) {
		this->initGame(pSocket);
	} else if (pFunction.compare(IConstants::getInstance()->f_newPlayer) == 0) {
		this->addPlayer(pJson, pSocket);
	} else if (pFunction.compare(IConstants::getInstance()->f_newBall) == 0) {
		this->newBall(pSocket);
	} else if (pFunction.compare(IConstants::getInstance()->f_deleteBall) == 0) {
			this->deleteBall(pSocket,pJson);
	}else if (pFunction.compare(IConstants::getInstance()->f_newBar) == 0) {
		this->newBar(pSocket);
	} else if (pFunction.compare(IConstants::getInstance()->f_newBlocks) == 0) {
		this->createBlocks(pJson,pSocket);
	} else if (pFunction.compare(IConstants::getInstance()->f_deleteBlock) == 0) {
		this->deleteBrick(pJson,pSocket);
	}else if (pFunction.compare(IConstants::getInstance()->f_changeDir) == 0) {
		this->changeDir(pSocket,pJson);
	}else if (pFunction.compare(IConstants::getInstance()->f_addPoints) == 0) {
		this->addPoints(pSocket,pJson);
	}

}
void Protocol::deleteBall(int pSocket,Json::Value pJson){
   Json::Value json;
   int number = Json_Code_Decode::getInstance()->getInt(pJson, IConstants::getInstance()->K_listNumber);
   json = GameLogic::Instance()->deleteBall(pSocket, number);
   sendAll(json,pSocket,false);
}
void Protocol::createBlocks(Json::Value pJson, int pSocket){
	GameLogic::Instance()->createBlocks(pSocket);
}

void Protocol::changeDir(int pSocket, Json::Value pJson){
	Json::Value json;
	double dir = Json_Code_Decode::getInstance()->getDouble(pJson, IConstants::getInstance()->K_Direction);
	int number = Json_Code_Decode::getInstance()->getInt(pJson, IConstants::getInstance()->K_listNumber);
	int pX = Json_Code_Decode::getInstance()->getInt(pJson, IConstants::getInstance()->K_posX);
	int pY = Json_Code_Decode::getInstance()->getInt(pJson, IConstants::getInstance()->K_posY);
	json = GameLogic::Instance()->changeDir(number,dir,pX,pY);
	sendAll(json, pSocket,true);
}

void Protocol::addPoints(int pSocket,Json::Value pJson){
	Json::Value json;
	int points=Json_Code_Decode::getInstance()->getInt(json, IConstants::getInstance()->K_points);
	GameLogic::Instance()->addPoints(pSocket, 10);


}
void Protocol::initGame(int pClient) {
	Json::Value json;
		json = GameLogic::Instance()->initGame();
		std::cout << "juego iniciado" << std::endl;
		send(pClient, json);

}
void Protocol::deleteBrick(Json::Value jsonObj, int pSocket) {
	std::cout<<"entra al protocolo"<<std::endl;
	int brick = Json_Code_Decode::getInstance()->getInt(jsonObj, IConstants::getInstance()->K_listNumber);
	Json::Value json;
	std::cout<<"entra al protocolo 2"<<std::endl;
	json = GameLogic::Instance()->deleteBlock(brick);
	cout<<"dhd";
	sendAll(json,pSocket,true);


}
void Protocol::addBrick(Json::Value data) {
	string brick = Json_Code_Decode::getInstance()->getString(data, "brick");
	Json::Value var = Json_Code_Decode::getInstance()->getJson(brick);
	listBricks->push_back(var);

}
void Protocol::send(int pSocket, Json::Value pJson) {
	ThreadServer thread;
	Json::FastWriter fastWriter;
	std::string output = fastWriter.write(pJson);
	thread.writeMsg(pSocket, output);
}

void Protocol::sendAll(Json::Value pJson,int pSocket, bool pDecide){
	std::cout<<"enviando a todos"<<std::endl;
	if(pDecide==true){
	for (int i = 0; i < GameLogic::Instance()->playersList->getLenght(); i++) {
		        if(GameLogic::Instance()->playersList->getData(i).getPlayerNumber()!=pSocket){
		        	send(GameLogic::Instance()->playersList->getData(i).getPlayerNumber(),
		        							pJson);
		        	std::cout<<"enviado a "<<pSocket<<std::endl;
		        }
			}
	}
	else{
	for (int i = 0; i < GameLogic::Instance()->playersList->getLenght(); i++) {
		send(GameLogic::Instance()->playersList->getData(i).getPlayerNumber(),
				pJson);
		std::cout<< GameLogic::Instance()->playersList->getData(i).getPlayerNumber()<< " socket"<<std::endl;
	}
}
}
void Protocol::deletePlayer(int pNumber){
    GameLogic::Instance()->deletePlayer(pNumber);
}


void Protocol::addPlayer(Json::Value pJson, int pSocket) {
	string username = Json_Code_Decode::getInstance()->getString(pJson,
			IConstants::getInstance()->K_username);
	GameLogic::Instance()->addUser(pSocket, username);
}
void Protocol::newBall(int pSocket) {
	Json::Value json;
	json = GameLogic::Instance()->newBall();
	sendAll(json,pSocket, false);

}
void Protocol::newBar(int pSocket) {
	Json::Value json;
	json = GameLogic::Instance()->newBar();
	send(pSocket, json);
}

