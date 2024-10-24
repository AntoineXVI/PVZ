#include "Shoot_Condition.h"

#include "Entity.h"
#include "Playground.h"

bool Shoot_Condition::Test(Entity* entity)
{
	auto plant_pos = entity->getPosition();
	auto enemies = Playground::getInstance()->getZombies();
	return false;
}

Shoot_Condition::~Shoot_Condition()
{

}
