#include "Projectile.h"
#include "Playground.h"
#include "Plant.hpp"
#include "Zombie.h"

Projectile::Projectile(sf::Vector2f position, Behaviour* plant_behaviour) : Entity(mPosition, mBehaviour)
{
	mSpeed = 1.5f;
	mLife = 1;
	mPosition = position;
	mBehaviour = plant_behaviour;
	mState = Context::State::MOVE;

	sf::CircleShape shape(5.f);
	mShape = shape;
	mColor = sf::Color(250, 250, 250);
	mShape.setFillColor(mColor);
	mShape.setPosition(position);
}

void Projectile::Move()
{
	sf::Vector2f Position;
	Position.x = getPosition().x + (1 * mSpeed);
	Position.y = getPosition().y;
	setPosition(Position);
}

bool Projectile::Collide()
{
	auto colliderPl = Playground::getInstance()->getPlant();
	for (int i = 0; i < colliderPl.size(); i++) {
		if (Playground::getInstance()->checkCollision(this, colliderPl[i])) {
			return true;
		}
	}
	auto colliderZ = Playground::getInstance()->getZombies();
	for (int i = 0; i < colliderZ.size(); i++) {
		if (Playground::getInstance()->checkCollision(this, colliderZ[i])) {
			return true;
		}
	}
	return false;
}

Projectile::~Projectile()
{
}
