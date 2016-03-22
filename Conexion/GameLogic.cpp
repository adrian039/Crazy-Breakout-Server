/*
 * GameLogic.cpp
 *
 *  Created on: 27 de feb. de 2016
 *      Author: adrian
 */

#include "GameLogic.h"
#include "Server.h"
#include "IConstants.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include "GameBar.h"
#include "Protocol.h"
using namespace std;

GameLogic* GameLogic::m_pInstance = NULL;

GameLogic* GameLogic::Instance() {
	if (!m_pInstance) {
		m_pInstance = new GameLogic();
		std::cout << "reconstruccion" << std::endl;
	}
	return m_pInstance;
}
Json::Value GameLogic::initGame() {
	Json::Value json;
	if (!gameInit) {
		json[IConstants::getInstance()->K_Function] =
				IConstants::getInstance()->f_initGame;
		json[IConstants::getInstance()->K_heigth] = game_Heigth;
		json[IConstants::getInstance()->K_width] = game_Width;
		json[IConstants::getInstance()->K_speed] = speed;
		json[IConstants::getInstance()->K_timeLimit] = time;
		//gameInit = true;

	}
	return json;
}

Json::Value GameLogic::initSecondGame(int client) {
	Json::Value json;
	if (!gameInit) {
		json[IConstants::getInstance()->K_Function] =
				"f_initSecondGame";
		json[IConstants::getInstance()->K_heigth] = game_Heigth;
		json[IConstants::getInstance()->K_width] = game_Width;
		json[IConstants::getInstance()->K_speed] = speed;
		json[IConstants::getInstance()->K_timeLimit] = time;
		//gameInit = true;

	}
	return json;
}

Json::Value GameLogic::deleteBlock(int pNumber){
	Json::Value json;
	json[IConstants::getInstance()->K_Function] =
			IConstants::getInstance()->f_deleteBlock;
	json[IConstants::getInstance()->K_listNumber] = pNumber;
	std::cout<<"entra al protocolo 3"
			""<<std::endl;
	blocksList->deleteBlock(pNumber);
	std::cout<<blocksList->getLenght()<<std::endl;
	return json;
}

void GameLogic::createBlocks(int pSocket){
	std::cout<<"creando bloques"<<std::endl;
	if(_init==false){
	Json::Value json;
	Protocol protocol;
	int j = 50;
	while(j<250){
	  int i = 50;
	  while(i<750){
    	  json = createBlock(i,j,50,50,50,50);
    	  Protocol::getInstance()->send(pSocket, json);
    	  i =i+50;
      }
	  j = j+50;
    }
	_init = true;
}
	else{
       for(int i=0;i<blocksList->getLenght();i++){
    	   Json::Value json;
    	   json = showBlock(blocksList->getData(i));
    	   std::cout<<"mostrado "<<i<<std::endl;
    	   Protocol::getInstance()->send(pSocket, json);
       }
	}

}

Json::Value GameLogic::showBlock(Blocks block){
	Json::Value json;
	json[IConstants::getInstance()->K_Function] =
				IConstants::getInstance()->f_newBlock;
	json[IConstants::getInstance()->K_posX] = block.getPosX();
	json[IConstants::getInstance()->K_posY] = block.getPosY();
	json[IConstants::getInstance()->K_heigth] = block.getHeigth();
	json[IConstants::getInstance()->K_width] = block.getWidth();
	json[IConstants::getInstance()->K_listNumber] = block.getNumber();
	return json;
}

void GameLogic::deletePlayer(int pSocket){
	playersList->deletePlayer(pSocket);
}

Json::Value GameLogic::deleteBall(int pSocket,int pNumber){
	Json::Value json;
	json[IConstants::getInstance()->K_listNumber] = pNumber;
	json[IConstants::getInstance()->K_Function] = IConstants::getInstance()->f_deleteBall;
	return json;
}

Json::Value GameLogic::changeDir(int pNumber, double pDir, int pX,int pY){
	Json::Value json;
	json[IConstants::getInstance()->K_Function] =
				IConstants::getInstance()->f_changeDir;
	json[IConstants::getInstance()->K_Direction] = pDir;
	json[IConstants::getInstance()->K_listNumber] = pNumber;
	json[IConstants::getInstance()->K_posY] = pY;
	json[IConstants::getInstance()->K_posX] = pX;
	return json;
}

Json::Value GameLogic::createBlock(int pPosX, int pPosY, int pHeight, int pWidth,int ptotalH, int ptotalW){
	Json::Value json;
	json[IConstants::getInstance()->K_Function] =
				IConstants::getInstance()->f_newBlock;
	json[IConstants::getInstance()->K_posX] = pPosX;
	json[IConstants::getInstance()->K_posY] = pPosY;
	json[IConstants::getInstance()->K_heigth] = pHeight;
	json[IConstants::getInstance()->K_width] = pWidth;
	Blocks block(pPosX, pPosY,pWidth, pHeight,blockCounter);
	blockCounter++;
	std::cout << block.getNumber() << std::endl;
	json[IConstants::getInstance()->K_listNumber] = block.getNumber();
	blocksList->push_back(block);
	return json;

}


Json::Value GameLogic::newBall() {
	Json::Value json;
	json[IConstants::getInstance()->K_Function] =
			IConstants::getInstance()->f_newBall;
	int pos_x = getBallX();
	json[IConstants::getInstance()->K_posX] = pos_x;
	json[IConstants::getInstance()->K_posY] = newBall_Y;
	json[IConstants::getInstance()->K_listNumber] = ballsList->getLenght();
	Ball ball(pos_x, newBall_Y,ballsList->getLenght());
	ballsList->push_back(ball);
	return json;
}

void GameLogic::addPoints(int pSocket, int points){
	for(int i=0; i<playersList->getLenght();i++){
		if(playersList->getData(i).getPlayerNumber()==pSocket){
			Player player= playersList->getData(i);
			player.SetPoints(player.getPoints()+points);
			playersList->deleteNode(i);
			playersList->push_back(player);
			break;
		}
	}
	playersList->displayPlayersScore();
}

Json::Value GameLogic::newBar() {
	Json::Value json;
	json[IConstants::getInstance()->K_Function] =
			IConstants::getInstance()->f_newBar;
	int pos_x = getBarX();
	json[IConstants::getInstance()->K_posX] = pos_x;
	json[IConstants::getInstance()->K_posY] = newBar_Y;
	json[IConstants::getInstance()->K_heigth] = 25;
		json[IConstants::getInstance()->K_width] = 50;
	json[IConstants::getInstance()->K_listNumber] = barsList->getLenght();
	Game_Bar bar(pos_x, newBar_Y);
	barsList->push_back(bar);

	return json;
}

int GameLogic::getBallX() {
	if (newBall_X < 750) {
		newBall_X = newBall_X + 50;
	} else {
		newBall_X = 30;
	}
	return newBall_X;
}

int GameLogic::getBarX() {
	if (newBar_X < 750) {
		newBar_X = newBar_X + 50;
	} else {
		newBar_X = 30;
	}
	return newBar_X;
}

void GameLogic::addUser(int pSocket, string pUserName) {
	Player player(pUserName, pSocket);
	playersList->push_back(player);
	std::cout << "player " << pUserName << " added" << std::endl;
	playersList->displayPlayers();


}

