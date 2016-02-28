/*
 * GameLogic.cpp
 *
 *  Created on: 27 de feb. de 2016
 *      Author: adrian
 */

#include "GameLogic.h"
#include "Server.h"

GameLogic* GameLogic::_pInstance=NULL;

GameLogic* GameLogic::Instance(){
	if(!_pInstance)
		_pInstance= new GameLogic;

	return _pInstance;

}
void GameLogic::addUser(int pSocket, string pUserName, int pScore){
	Jsons createJ;
	Json::Value newUser;
	newUser["socket"]=pSocket;
	newUser["userName"]=pUserName;
	newUser["score"]=pScore;
	this->_logUsers->push_back(newUser);
	this->addScoreUser(pUserName, 235);
}

void GameLogic::addScoreUser(string pUsername, int pScore){
	int usersLenght=this->_logUsers->getLenght();
	for(int i=0; i<usersLenght; i++){
		Json::Value user=(Json::Value)this->_logUsers->getData(i);
		string userName=user["userName"].asString();
		if(userName.compare(pUsername)==0){
			this->_logUsers->deleteNode(i);
			int score=user["score"].asInt();
			user["score"]=score+pScore;
			this->_logUsers->push_back(user);
			break;
		}
	}
	this->_logUsers->display();
	cout<<this->_logUsers->getLenght();

}


