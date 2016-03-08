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
	Json::Value newBall();
	Json::Value newBar();
	int getBallX();
	int getBarX();
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
		newBar_X = 0;
		newBall_X = 0;
		newBar_Y = 480;
		newBall_Y = 400;

 	}
	;
	int game_Heigth;
	int game_Width ;
	int time ;
	int speed ;
	int newBar_X;
	int newBar_Y;
	int newBall_X;
	int newBall_Y;

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
