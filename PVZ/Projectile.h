#pragma once
#include "Entity.h"
class Projectile : public Entity
{
public:
	Projectile(sf::Vector2f position,Behaviour* plant_behaviour);
	void Move() override;
	bool Collide() override;
	~Projectile();
};

