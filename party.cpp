#include "village.h"
#include "party.h"
int Party::number = 0;

void Party::addVillage(Village* vil) {
	this->villages.push_back(vil);
	vil->setBelongTo(this->id);
}
