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

string Jsons::parseJson(char* json){
	Json::Value root;
	Json::Reader reader;
	std::string var;
	var="jaja";
	reader.parse(json,root);
	//cout<<json<<endl;
	const Json::Value tipo=root["tipo"];
	Json::Value prueb;
	prueb["tipo"]="prueba";
	//cout<<tipo;
	createJson(prueb,"dato1", "Adrian");
	return "a";
}

Json::Value Jsons::createJson(Json::Value funct, string ArrayKey, string ArrayData){
	int size;
	funct[ArrayKey]=ArrayData;
	//cout<<ArrayKeys[3]<<endl;
	/*for(int i=0; i<=size; i++){
		json1[ArrayKeys[i]]=ArrayData[i];
	}*/
	cout<<funct;
	return funct;
}
