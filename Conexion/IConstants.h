/*
 * IConstants.h
 *
 *  Created on: 1 de mar. de 2016
 *      Author: vargas
 */

#ifndef ICONSTANTS_H_
#define ICONSTANTS_H_
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
class IConstants {
public:
	static IConstants* getInstance();
	const char* f_initGame = "f_initGame";
	const char* f_newPlayer = "f_newPlayer";
	const char* f_newBall = "f_newBall";
	const char* f_deleteBlock = "f_deleteBlock";
	const char* f_deleteBall = "f_deleteBall";
	const char* f_newBar = "f_newBar";
	const char* f_done = "f_done";
	const char* f_newBlock = "f_newBlock";
	const char* f_newBlocks = "f_newBlocks";
	const char* f_changeDir = "f_changeDir";
	const char* K_username = "K_username";
	const char* K_points = "K_points";
	const char* K_listNumber = "K_listNumber";
	const char* K_Function = "K_Function";
	const char* K_width = "K_width";
	const char* f_refresh = "f_refresh";
	const char* K_Direction= "K_Direction";
	const char* K_Done= "K_Done";
	const char* K_Socket= "K_Socket";
	const char*  f_addPoints = "f_addPoints";
	const char* K_heigth = "K_heigth";
	const char* K_timeLimit = "K_timeLimit";
	const char* K_speed = "K_speed";
	const char* K_posX = "K_posX";
	const char* K_posY = "K_posY";

private:
	IConstants() {
	}
	;
	static IConstants* _instance;
	virtual ~IConstants();
};

#endif /* ICONSTANTS_H_ */
