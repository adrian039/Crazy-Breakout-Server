/*
 * Blocks.h
 *
 *  Created on: 20 de feb. de 2016
 *      Author: vargas
 */

#ifndef BLOCKS_H_
#define BLOCKS_H_

class Blocks {
public:
	Blocks(int, int, int, int, int, int, int);
	int getWidth() {
		return _width;
	}
	int getHeigth() {
		return _height;
	}
	int getPosX() {
		return _posX;
	}
	int getPosY() {
		return _posY;
	}
	int getLevel() {
		return _level;
	}
private:
	int _width;
	int _height;
	int _posX;
	int _posY;
	int _level;
	int _contactHeight;
	int _contactWidth;
};

#endif /* BLOCKS_H_ */
