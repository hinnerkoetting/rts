#include "village.h"
#include "party.h"
#include "ingame.h"
#include <vector>
int Party::number = 0;

void Party::addVillage(Village* vil) {
	this->villages.push_back(vil);
	vil->setBelongTo(this->id);
}


void Party::draw() {
	for (std::vector<Village*>::iterator i = this->villages.begin(); i != this->villages.end(); i++) {
		std::vector<Village*>::value_type tmp = *i;
		tmp->draw();
	}

}

Village* Party::getVillage(int party, int village) {
	Party* p = Ingame::getParty(party);
	if (p != 0) {
		if ((unsigned)village < p->villages.size()) 
			return p->villages.at(village);
	}
	return 0;
}