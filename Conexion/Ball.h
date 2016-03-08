/*
 * Ball.h
 *
 *  Created on: 20 de feb. de 2016
 *      Author: vargas
 */

#ifndef BALL_H_
#define BALL_H_

class Ball {
public:
	Ball(int, int, int);
	void moreSpeed();
	int getPosX() {
		return _posX;
	}
	int getPosY() {
		return _posY;
	}
	int getSize() {
		return _size;
	}
	int getSpeed() {
		return _speed;
	}
	void setPos(int, int);
	void setSize(int);

private:

	int _posX;
	int _posY;
	int _size;
	int _speed;

};

#endif /* BALL_H_ */
