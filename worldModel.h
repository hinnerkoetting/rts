/////////////////////////////////////////////////////////////////
//
//					worldModel.h
//					contains the central world components
//					
//
/////////////////////////////////////////////////////////////////


#ifndef WORLDMODEL_H_DEF
#define WORLDMODEL_H_DEF


/**
 * contains the map and other central elements of the world
 * especially the parties
 * the parties link to other entities and units in the world
 *
 * additionally functions for initializing and destroying the world model are included
 * at the moment the ingame.cpp still implements the functions
 */

#include "field.h"
#include "party.h"
#include <vector>

namespace worldModel{
	extern Field fields[MAX_FIELDS_X][MAX_FIELDS_Y];
	extern std::vector<Party> partys;
	void initGame();
	void DestroyWorld();

	//später wieder auf calc umbenenen
	void partyCalc(int i); //KI 
	//void unitMovement(int dummy);

}

#endif