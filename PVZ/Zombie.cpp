#include "Zombie.h"
#include "Plant.hpp"
#include "Projectile.h"
#include "Playground.h"


Zombie::Zombie(sf::Vector2f position, Behaviour* zombie_behaviour) : Entity(mPosition, mBehaviour)
{
	mSpeed = 1.f;
	mLife = 1;
	mPosition = position;
	mBehaviour = zombie_behaviour;
	mState = Context::State::MOVE;

	sf::CircleShape shape(10.f);
	mShape = shape;
	mColor = sf::Color(250, 0, 0);
	mShape.setFillColor(mColor);
	mShape.setPosition(position);
}

void Zombie::Move()
{
	sf::Vector2f Position;
	Position.x = getPosition().x - (1 * mSpeed);
	Position.y = getPosition().y;
	setPosition(Position);
}

bool Zombie::Collide()
{
	auto colliderPl = Playground::getInstance()->getPlant();
	for (int i = 0; i < colliderPl.size(); i++) {
		if (Playground::getInstance()->checkCollision(this, colliderPl[i])) {
			return true;
		}
	}
	auto colliderP = Playground::getInstance()->getProjectile();
	for (int i = 0; i < colliderP.size(); i++) {
		if (Playground::getInstance()->checkCollision(this, colliderP[i])) {
			return true;
		}
	}
	return false;
}

Zombie::~Zombie()
{

}
