#include "Plant.hpp"
#include "Transition.hpp"
#include "Shoot_Condition.h"
#include "Shoot_Action.h"
#include "Shoot_Action.h"
#include "Behaviour.hpp"
#include "Playground.h"
#include "Zombie.h"
//Plant::Plant()
//{
//}

Plant::Plant(sf::Vector2f position, Behaviour* plant_behaviour) : Entity(mPosition, mBehaviour)
{
	mPosition = position;
	mBehaviour = plant_behaviour;
	mAmmoCount = 1;
	mMaxAmmo = 1;
	mState = Context::State::IDLE;
	mLife = 3;

	sf::CircleShape shape(10.f);
	mShape = shape;
	mColor = sf::Color(100, 250, 50);
	mShape.setFillColor(mColor);
	mShape.setPosition(position);

	//deplacer dans playground::constructor
	// 

}


void Plant::Move()
{
}

bool Plant::Collide()
{
	auto colliderZ = Playground::getInstance()->getZombies();
	for (int i = 0; i < colliderZ.size(); i++) {
		if (Playground::getInstance()->checkCollision(this, colliderZ[i])) {
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



void Plant::refillMagazine()
{
}

bool Plant::shoot()
{
	return false;
}


Plant::~Plant()
{
}