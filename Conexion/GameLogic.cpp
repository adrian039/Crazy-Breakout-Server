/*
 * GameLogic.cpp
 *
 *  Created on: 27 de feb. de 2016
 *      Author: adrian
 */

#include "GameLogic.h"
#include "Server.h"
#include "LinkedList1.cpp"
#include "IConstants.h"
#include <iostream>
#include <stdlib.h>
#include "GameBar.h"
using namespace std;

GameLogic* GameLogic::m_pInstance = NULL;

GameLogic* GameLogic::Instance() {
	if (!m_pInstance) {   // Only allow one instance of class to be generated.
		m_pInstance = new GameLogic();
		std::cout << "reconstruccion"<<std::endl;
	}
	return m_pInstance;
}
Json::Value GameLogic::initGame(){
	Json::Value json;
	if(!gameInit){
		 json[IConstants::getInstance()->K_Function] =
				 IConstants::getInstance()->f_initGame;
		 json[IConstants::getInstance()->K_heigth] =
				 game_Heigth;
		 json[IConstants::getInstance()->K_width] =
				 game_Width;
		 json[IConstants::getInstance()->K_speed] =
					 speed;
		 json[IConstants::getInstance()->K_timeLimit] =
					 time;
		 gameInit = true;

	}
	return json;
}
Json::Value GameLogic::newBall(){
	Json::Value json;
		 json[IConstants::getInstance()->K_Function] =
				 IConstants::getInstance()->f_newBall;
		 int pos_x = getBallX();
		 json[IConstants::getInstance()->K_posX] =
				 pos_x;
		 json[IConstants::getInstance()->K_posY] =
				newBall_Y;
		 json[IConstants::getInstance()->K_listNumber] =
		 				ballsList->getLenght();

		 Ball ball(pos_x,newBall_Y);
		 ballsList->push_back(ball);
	     return json;
}

Json::Value GameLogic::newBar(){
	Json::Value json;
		 json[IConstants::getInstance()->K_Function] =
				 IConstants::getInstance()->f_newBar;
		 int pos_x = getBarX();
		 json[IConstants::getInstance()->K_posX] =
				 pos_x;
		 json[IConstants::getInstance()->K_posY] =
				newBar_Y;
		 json[IConstants::getInstance()->K_listNumber] =
		 				barsList->getLenght();
		 Game_Bar bar(pos_x,newBar_Y);
		 barsList->push_back(bar);

	     return json;
}

int GameLogic::getBallX(){
   if(newBall_X<750){
	   newBall_X = newBall_X+50;
   }
   else{
	   newBall_X = 30;
   }
   return newBall_X;
}

int GameLogic::getBarX(){
   if(newBar_X<750){
	   newBar_X = newBar_X+50;
   }
   else{
	   newBar_X = 30;
   }
   return newBar_X;
}



void GameLogic::addUser(int pSocket, string pUserName) {
      Player player(pUserName, pSocket);
      playersList->push_back(player);
      std::cout<< "player "<<pUserName<<" added"<< std::endl;
      playersList->displayPlayers();
}




