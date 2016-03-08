/*
 * JsonCodeDecode.cpp
 *
 *  Created on: 4 de mar. de 2016
 *      Author: vargas
 */

#include "JsonCodeDecode.h"
#include <iostream>

Json_Code_Decode* Json_Code_Decode::_instance = NULL;
Json_Code_Decode* Json_Code_Decode::getInstance() {
	if (!_instance) {
		_instance = new Json_Code_Decode;
	}
	return _instance;
}
Json::Value Json_Code_Decode::getJson(string pJson) {
	if (isJson(pJson)) {
		Json::Value root;
		Json::Reader reader;
		reader.parse(pJson, root);
		return root;
	} else {
		return 0;
	}
}

bool Json_Code_Decode::isJson(string pJson) {
	Json::Value root;
	Json::Reader reader;
	bool done = reader.parse(pJson, root);
	std::cout << "parse = " << done << std::endl;
	return done;
}

string Json_Code_Decode::getString(Json::Value pJson, string pKey) {
	string key1 = pJson[pKey].asString();
	return key1;
}

void Json_Code_Decode::includeString(string pData, Json::Value pJson,
		string pKey) {
	pJson[pKey] = pData;
}

void Json_Code_Decode::includeInt(int pData, Json::Value pJson, string pKey) {
	pJson[pKey] = pData;
}

int Json_Code_Decode::getInt(Json::Value pJson, string pKey) {
	int key1 = pJson[pKey].asInt();
	return key1;
}

