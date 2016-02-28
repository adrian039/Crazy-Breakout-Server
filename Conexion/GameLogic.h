/*
 * GameLogic.h
 *
 *  Created on: 27 de feb. de 2016
 *      Author: adrian
 */

#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_
#include "LinkedList.cpp"
#include "Jsons.h"

class GameLogic {
public:
	void addUser(int, string, int);
	void addScoreUser(string, int);
	static GameLogic* Instance();
private:
	GameLogic(){};
	static GameLogic* _pInstance;


private:
	List<Json::Value> *_logUsers= new List<Json::Value>(NULL);
};

#endif /* GAMELOGIC_H_ */
