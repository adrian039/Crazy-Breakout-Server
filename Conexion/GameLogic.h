/*
 * GameLogic.h
 *
 *  Created on: 27 de feb. de 2016
 *      Author: adrian
 */

#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_
#include <iostream>
#include"LinkedList1.h"
#include "jsoncpp/json.h"
#include "GameBar.h"
#include "Player.h"
#include "Blocks.h"
#include "Ball.h"

using namespace std;

class GameLogic {
public:
	Json::Value initGame();
	void addUser(int, string);
	void addScoreUser(string, int);
	static GameLogic* Instance();

private:
	GameLogic() {
		ballsList = new LinkedList1<Ball>(NULL);
		blocksList = new LinkedList1<Blocks>(NULL);
		barsList = new LinkedList1<Game_Bar>(NULL);
		playersList = new LinkedList1<Player>(NULL);
		game_Heigth= 500;
		game_Width = 800;
		time = 120;
		speed = 35;
		gameInit = false;
	}
	;
	int game_Heigth;
	int game_Width ;
	int time ;
	int speed ;

	void createBricks();
	static GameLogic* m_pInstance;
	LinkedList1<Ball> *ballsList;
	LinkedList1<Blocks> *blocksList;
	LinkedList1<Game_Bar> *barsList;
	LinkedList1<Player> *playersList;
	bool gameInit;
	//LinkedList1<Json::Value> *_logUsers=new LinkedList1<Json::Value>(NULL);

};

#endif /* GAMELOGIC_H_ */
