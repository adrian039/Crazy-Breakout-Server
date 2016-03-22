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
	Blocks(int, int, int, int, int);
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
	int getNumber(){
	  return _number;
	}
private:
	int _width;
	int _height;
	int _posX;
	int _posY;
	int _number;

};

#endif /* BLOCKS_H_ */
