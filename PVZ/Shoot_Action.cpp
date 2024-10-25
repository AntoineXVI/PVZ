#include "Shoot_Action.h"
#include "Plant.hpp"
#include "Projectile.h"
#include "Playground.h"

Shoot_Action::Shoot_Action():Action()
{

}

void Shoot_Action::Start(Entity* entity)
{
	
}

void Shoot_Action::Update(Entity* entity)
{
	for (int i = 0; i < entity->getAmmoCount(); i++) {
		sf::Vector2f pos(entity->getPosition().x + 50, entity->getPosition().y);
		Playground::getInstance()->addProjectiles(pos);
		entity->Shoot();
	}
	
}

void Shoot_Action::End(Entity* entity)
{
}

Shoot_Action::~Shoot_Action()
{
}