#include "Shoot_Action.h"
#include "Plant.hpp"
#include "Projectile.h"

Shoot_Action::Shoot_Action()
{
}

void Shoot_Action::Start(Plant* Plant)
{
	//Projectile* proj = new Projectile();
	sf::CircleShape shape(10.f);
	shape.setPosition(sf::Vector2f(Plant->getPosition().x+50, Plant->getPosition().y));
}

void Shoot_Action::Update(Plant* Plant)
{
}

void Shoot_Action::End(Plant* Plant)
{
}

Shoot_Action::~Shoot_Action()
{
}
