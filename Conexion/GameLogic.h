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
	Json::Value initSecondGame(int);
	Json::Value newBall();
	Json::Value newBar();
	Json::Value changeDir(int,double,int,int);
	void deletePlayer(int);
	Json::Value deleteBall(int,int);
	LinkedList1<Player> *playersList;
	int getBallX();
	int getBarX();
	void createBlocks(int);
	void addPoints(int, int);
	Json::Value deleteBlock(int);
	Json::Value createBlock(int,int,int,int,int,int);
	Json::Value showBlock(Blocks);
	void addUser(int, string);
	void addScoreUser(string, int);
	static GameLogic* Instance();

private:
	GameLogic() {
		ballsList = new LinkedList1<Ball>(NULL);
		blocksList = new LinkedList1<Blocks>(NULL);
		barsList = new LinkedList1<Game_Bar>(NULL);
		playersList = new LinkedList1<Player>(NULL);
		game_Heigth = 500;
		game_Width = 800;
		time = 10;
		speed = 60;
		gameInit = false;
		newBar_X = 0;
		newBall_X = 0;
		newBar_Y = 480;
		newBall_Y = 400;
		_init = false;
		blockCounter = 0;
		_direction = 140.8176312893687;


	}
	;
	int game_Heigth;
	int game_Width;
	int time;
	int speed;
	int blockCounter;
	int newBar_X;
	int newBar_Y;
	int newBall_X;
	int newBall_Y;
	bool _init;
	int _direction;

	void createBricks();
	static GameLogic* m_pInstance;
	LinkedList1<Ball> *ballsList;
	LinkedList1<Blocks> *blocksList;
	LinkedList1<Game_Bar> *barsList;
	bool gameInit;
	//LinkedList1<Json::Value> *_logUsers=new LinkedList1<Json::Value>(NULL);

};

#endif /* GAMELOGIC_H_ */
