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

Protocol* Protocol::getInstance(){
   if(!_instance){
	   _instance = new Protocol();

   }
   return _instance;
   }
void Protocol::initProtocol(string pData, int pClient){
	Json::Value json = Json_Code_Decode::getInstance()->getJson(pData);
    string function= Json_Code_Decode::getInstance()->getString(json, IConstants::getInstance()->K_Function);
    manage(function,json, pClient);
}

void Protocol::manage(std::string pFunction, Json::Value pJson,int pSocket){
	if(pFunction.compare(IConstants::getInstance()->f_initGame)==0){
		this->initGame(pSocket);
}
	else if(pFunction.compare(IConstants::getInstance()->f_newPlayer)==0){
		this->addPlayer(pJson, pSocket);
	}
	else if(pFunction.compare(IConstants::getInstance()->f_newBall)==0){
        this->newBall(pSocket);
	}
	else if(pFunction.compare(IConstants::getInstance()->f_newBar)==0){
        this->newBar(pSocket);
	}

}

void Protocol::initGame(int pClient){
	 Json::Value json;
     json = GameLogic::Instance()->initGame();
     std::cout<<"juego iniciado"<<std::endl;
     send(pClient, json);

}
void Protocol::send(int pSocket, Json::Value pJson){
    ThreadServer thread ;
    Json::FastWriter fastWriter;
    std::string output = fastWriter.write(pJson);
    thread.writeMsg(pSocket,output);
}

void Protocol::addPlayer(Json::Value pJson, int pSocket){
	string username = Json_Code_Decode::getInstance()->getString(pJson, IConstants::getInstance()->K_username);
	GameLogic::Instance()->addUser(pSocket, username);
}
void Protocol::newBall( int pSocket){
	Json::Value json;
    json =GameLogic::Instance()->newBall();
    send(pSocket, json);

}
void Protocol::newBar( int pSocket){
	Json::Value json;
    json =GameLogic::Instance()->newBar();
    send(pSocket, json);
}



