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

GameLogic* GameLogic::m_pInstance = NULL;

GameLogic* GameLogic::Instance() {
	if (!m_pInstance) {   // Only allow one instance of class to be generated.
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
		gameInit = true;

	}
	return json;
}

void GameLogic::addUser(int pSocket, string pUserName) {
	Player player(pUserName, pSocket);
	playersList->push_back(player);
	std::cout << "player " << pUserName << " added" << std::endl;
	playersList->displayPlayers();
}

