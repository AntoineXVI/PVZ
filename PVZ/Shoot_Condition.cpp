#include "Shoot_Condition.h"
#include "Zombie.h"
#include "Entity.h"
#include "Playground.h"


Shoot_Condition::Shoot_Condition()
{
}

bool Shoot_Condition::Test(Entity* entity)
{
  auto plant_pos = entity->getPosition();
	std::vector<Zombie*> zombies = Playground::getInstance()->getZombies();
	for (int i = 0; i < zombies.size(); i++) {
		if (Plant->getPosition().y == zombies[i]->getPosition().y) {
			return true;
		}
	}
	return false;
}

Shoot_Condition::~Shoot_Condition()
{

}
