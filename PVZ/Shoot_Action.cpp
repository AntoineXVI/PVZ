#include "Shoot_Action.h"
#include "Plant.hpp"
#include "Projectile.h"
#include "Playground.h"

Shoot_Action::Shoot_Action():Action()
{

}

void Shoot_Action::Start(Entity* Plant)
{
	
}

void Shoot_Action::Update(Entity* Plant)
{
	Behaviour* behaviour = new Behaviour();
	sf::Vector2f pos(Plant->getPosition().x + 50, Plant->getPosition().y);
	Projectile* proj = new Projectile(pos,behaviour);
	Playground::getInstance()->addProjectiles(proj);
}

void Shoot_Action::End(Entity* Plant)
{
}

Shoot_Action::~Shoot_Action()
{
}
