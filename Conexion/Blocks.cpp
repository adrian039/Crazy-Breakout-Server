/*
 * Blocks.cpp
 *
 *  Created on: 20 de feb. de 2016
 *      Author: vargas
 */

#include "Blocks.h"

Blocks::Blocks(int pPosX, int pPosY, int pWidth, int pHeight, int pLevel,
		int pContactH, int pContactW) {
	_level = pLevel;
	_height = pHeight;
	_width = pWidth;
	_posY = pPosY;
	_posX = pPosX;
	_contactHeight = pContactH;
	_contactWidth = pContactW;



}

