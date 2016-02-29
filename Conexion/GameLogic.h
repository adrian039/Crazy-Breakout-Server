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

using namespace std;

class GameLogic {
public:
	void addUser(int, string, int);
	void addScoreUser(string, int);
	static GameLogic* Instance();
private:
	GameLogic() {
	}
	;
	GameLogic(GameLogic const&) {
	}
	;             // copy constructor is private
	GameLogic& operator=(GameLogic const&) {
	}
	;
	static GameLogic* m_pInstance;
	//LinkedList1<Json::Value> *_logUsers=new LinkedList1<Json::Value>(NULL);

};

#endif /* GAMELOGIC_H_ */
