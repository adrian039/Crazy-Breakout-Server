/*
 * Jsons.cpp
 *
 *  Created on: 25 de feb. de 2016
 *      Author: adrian
 */

#include "Jsons.h"

Jsons::Jsons() {
	// TODO Auto-generated constructor stub

}

string Jsons::parse(char* json){
	Json::Value root;
	Json::Reader reader;
	reader.parse(json,root);
	const Json::Value tipo=root["tipo"];
	cout<<tipo;
	return "a";
}

string Jsons::create(string funct, string ArrayKeys[], string ArrayData[]){
	int size;
	size=ArrayKeys->length();
	for(int i; i<=size; i++){

	}
	return "a";

}
