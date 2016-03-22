/*
 * Ball.cpp
 *
 *  Created on: 20 de feb. de 2016
 *      Author: vargas
 */

#include "Ball.h"

Ball::Ball(int pPosX, int pPosY,int pNumber) {
	_posX = pPosX;
	_posY = pPosY;
	_number = pNumber;

}

void Ball::setPos(int pPosX, int pPosY) {
	_posX = pPosX;
	_posY = pPosY;
}
void Ball::setSize(int pSize) {
	_size = pSize;
}

