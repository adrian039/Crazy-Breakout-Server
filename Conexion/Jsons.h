/*
 * Jsons.h
 *
 *  Created on: 25 de feb. de 2016
 *      Author: adrian
 */

#ifndef JSONS_H_
#define JSONS_H_
#include "jsoncpp/json.h"
#include <string>
#include <iostream>

using namespace std;

class Jsons {
public:
	Jsons();
	string parseJson(char*,int);
	Json::Value addToJson(Json::Value, string, string);
};

#endif /* JSONS_H_ */
