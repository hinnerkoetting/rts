#include "building.h"

Unit* Building::popUnit() {
	int i = getNrUnits();
	if (i > 0) {
		Unit* u = unitsInBuilding.at(i-1);
		unitsInBuilding.pop_back();
		return u;
	}
	return 0;
}