/*
 * JsonCodeDecode.h
 *
 *  Created on: 4 de mar. de 2016
 *      Author: vargas
 */

#ifndef JSONCODEDECODE_H_
#define JSONCODEDECODE_H_
#include <string>
#include <iostream>
#include "jsoncpp/json.h"

using namespace std;
class Json_Code_Decode {
public:
	static Json_Code_Decode* getInstance();
	void getJsonData(string, string);
	int getInt(Json::Value, string);
	char* getChar(Json::Value, string);
	string getString(Json::Value, string);
	Json::Value getJson(string);
	bool isJson(string);
	void includeString(string, Json::Value, string);
	void includeInt(int, Json::Value, string);
private:
	Json_Code_Decode() {
	}
	;
	static Json_Code_Decode* _instance;

};

#endif /* JSONCODEDECODE_H_ */
