#include "Shoot_Condition.h"

#include "Plant.hpp"
#include "Playground.h"

Shoot_Condition::Shoot_Condition()
{
}

bool Shoot_Condition::Test(Plant* plant)
{
	auto plant_pos = plant->getPosition();
	auto enemies = Playground::getInstance()->getZombies();

	return false;
}

Shoot_Condition::~Shoot_Condition()
{
}
