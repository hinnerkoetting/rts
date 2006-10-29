/////////////////////////////////////////////////////////////////
//
//					
//					building.h
//					
//					
//
////////////////////////////////////////////////////////////////

#include "game_object.h"
#include "unit.h"
#include "vector"

class Building : public GameObject {
	protected:
		Building() {}
		std::vector<Unit*> unitsInBuilding;
	public:
		int getNrUnits() { return unitsInBuilding.size(); }
		void addUnit(Unit* u) { unitsInBuilding.push_back(u); }
		Unit* popUnit();

};