/*
 * Jsons.cpp
 *
 *  Created on: 25 de feb. de 2016
 *      Author: adrian
 */

#include "Jsons.h"
#include "GameLogic.h"

Jsons::Jsons() {
	// TODO Auto-generated constructor stub

}

string Jsons::parseJson(char* json, int socket) {
	Json::Value root;
	Json::Reader reader;
	reader.parse(json, root);
	string key = root["key"].asString();
	//Inician las condiciones que conforman la logica del juego
	if (key.compare("addUser") == 0) {
		string usern = root["userName"].asString();
		int score = root["score"].asInt();
		GameLogic::Instance()->addUser(socket, usern, score);
	}
	/*Json::Value prueb;
	 prueb["tipo"]="prueba";
	 //cout<<tipo;
	 //createJson(prueb,"dato1", "Adrian");
	 return "a";*/
	return "a";
}

Json::Value Jsons::addToJson(Json::Value funct, string ArrayKey,
		string ArrayData) {
	int size;
	funct[ArrayKey] = ArrayData;
	//cout<<ArrayKeys[3]<<endl;
	/*for(int i=0; i<=size; i++){
	 json1[ArrayKeys[i]]=ArrayData[i];
	 }*/
	cout << funct;
	return funct;
}
