/*
 * IConstants.cpp
 *
 *  Created on: 1 de mar. de 2016
 *      Author: vargas
 */

#include "IConstants.h"
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
IConstants* IConstants::_instance = NULL;


IConstants::~IConstants() {
	// TODO Auto-generated destructor stub
}
IConstants* IConstants::getInstance(){
	   if(_instance==NULL){
		   _instance = new IConstants();
	   }
	   return _instance;
	   }


