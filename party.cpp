#include "village.h"
#include "party.h"
#include "gameViewAndControl.h"
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



void Party::calc() {
	for (std::vector<Village*>::iterator i = this->villages.begin(); i != villages.end(); i++) {
		std::vector<Village*>::value_type tmp = *i;
		tmp->calc();
	}
}