/*
 * GameBar.h
 *
 *  Created on: 20 de feb. de 2016
 *      Author: vargas
 */

#ifndef GAMEBAR_H_
#define GAMEBAR_H_

class Game_Bar {
public:
	Game_Bar(int,int,int,int);
	int getWidth(){return _width;}
	int getHeigth(){return _height;}
	int getPosX(){return _posX;}
	int getPosY(){return _posY;}

private:
	int _width;
	int _height;
	int _posX;
	int _posY;

};

#endif /* GAMEBAR_H_ */
