/*
 * GameLogic.cpp
 *
 *  Created on: 27 de feb. de 2016
 *      Author: adrian
 */

#include "GameLogic.h"
#include "Server.h"
#include "LinkedList1.cpp"

//extern LinkedList1<Json::Value> *_logUsers; // Se hace referencia a la variable estatica creada en Server.h
GameLogic* GameLogic::m_pInstance = NULL;

GameLogic* GameLogic::Instance() {
	if (!m_pInstance) {   // Only allow one instance of class to be generated.
		m_pInstance = new GameLogic;
	}
	return m_pInstance;
}

void GameLogic::addUser(int pSocket, string pUserName, int pScore) {
	//_logUsers->display();
	Json::Value newUser;
	newUser["socket"] = pSocket;
	newUser["userName"] = pUserName;
	newUser["score"] = pScore;
	_logUsers->push_back(newUser);
	GameLogic::Instance()->addScoreUser(pUserName, 235); //se llama esta funcion par aprobar add score (no es necesaria)
}

void GameLogic::addScoreUser(string pUsername, int pScore) {
	int usersLenght = _logUsers->getLenght();
	for (int i = 0; i < usersLenght; i++) {
		Json::Value user = (Json::Value) _logUsers->getData(i);
		string userName = user["userName"].asString();
		if (userName.compare(pUsername) == 0) {
			_logUsers->deleteNode(i);
			int score = user["score"].asInt();
			user["score"] = score + pScore;
			_logUsers->push_back(user);
			break;
		}
	}
	_logUsers->display();   //muestra los elementos de la lista
	cout << _logUsers->getLenght() << endl;   //imprime el tamaño de la lista
	cout << &_logUsers << endl; //Imprime la direccion de memoria de la lista

}

