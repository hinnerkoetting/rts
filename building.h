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
		std::vector<Unit*> unitsInBuilding;

		Building() {						
			
		};

		~Building(){
			//delete unitsInBuilding;
			//unitsInBuilding=NULL;
		};

		
	public:
		int getNrUnits() { return unitsInBuilding.size(); }
		void addUnit(Unit* u) { unitsInBuilding.push_back(u); }
		Unit* popUnit();

};