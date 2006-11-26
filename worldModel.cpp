/////////////////////////////////////////////////////////////////
//
//					worldModel.cpp
//					contains the central world components
//					
//
/////////////////////////////////////////////////////////////////


#include "gl/glut.h"
#include "worldModel.h"
#include "party.h"

void worldModel::partyCalc(int i){
for (std::vector<Party>::iterator i = worldModel::partys.begin(); i != worldModel::partys.end(); i++) {
		std::vector<Party>::value_type tmp = *i;
		tmp.calc();
	}
	glutTimerFunc(1000,worldModel::partyCalc,10);
}

/*
void worldModel::unitMovement(int dummy){
for (std::vector<Party>::iterator i = worldModel::partys.begin(); i != worldModel::partys.end(); i++) {
		std::vector<Party>::value_type tmp = *i;
		tmp.unitMovement();
	}
	
}
*/