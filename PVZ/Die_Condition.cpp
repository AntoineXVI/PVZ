#include "Die_Condition.h"
#include "Entity.h"
#include "Playground.h"
Die_Condition::Die_Condition()
{
}

bool Die_Condition::Test(Entity* entity)
{
	auto projectiles = Playground::getInstance()->getPlant();
	auto zombies = Playground::getInstance()->getZombies();
	//Playground::getInstance()->checkCollision(projectiles, zombies);

	return false;
}

Die_Condition::~Die_Condition()
{
}