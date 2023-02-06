#include "Entity.h"
Entity::~Entity() {
	for (auto c : currCmps_) {
		delete c;
	}
}