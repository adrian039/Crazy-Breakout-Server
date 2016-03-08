/*
 * Ball.cpp
 *
 *  Created on: 20 de feb. de 2016
 *      Author: vargas
 */

#include "Ball.h"

Ball::Ball( int pPosX, int pPosY) {
	_posX = pPosX;
	_posY = pPosY;

}

void Ball::setPos(int pPosX, int pPosY){
	_posX= pPosX;
	_posY = pPosY;
}
void Ball::setSize(int pSize){
	_size = pSize;
}



