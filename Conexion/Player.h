/*
 * Player.h
 *
 *  Created on: 20 de feb. de 2016
 *      Author: vargas
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>


using namespace std;

class Player {
public:
     Player(string, int);
	 string getUsername(){return _username;}
	 int getSessionNumber(){return _sessionNumber;}
	 int getPoints(){return _points;}
     void setUsername(string);
     void setSessionNumber(int);
     void SetPoints(int);
     void setPlayerNum(int);
private:
	string _username;
	int _sessionNumber;
	int _points;
	int _playerNumber;

};

#endif /* PLAYER_H_ */
