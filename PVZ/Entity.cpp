#include "Entity.h"
#include "Behaviour.hpp"

Entity::Entity(sf::Vector2f position, Behaviour* behaviour)
{
	mPosition = position;
	mBehaviour = behaviour;
}

sf::CircleShape Entity::GetShape()
{
	return mShape;
}



sf::Color Entity::getColor() const
{
	return mColor;
}

sf::Vector2f Entity::getPosition() const
{
	return mPosition;
}

void Entity::setPosition(sf::Vector2f Position)
{
	mPosition = Position;
	mShape.setPosition(mPosition);
}


void Entity::setState(Context::State NewState)
{
	mState = NewState;

}

Context::State Entity::getState() const
{
	return mState;
}

void Entity::TakeDamage()
{
	mLife--;
}

int Entity::GetLife()
{
	return mLife;
}

void Entity::Update()
{

	//if (mState == Context::State::MOVE)
	//{
	//	mPosition.x -= 1;

	//	mShape.setPosition(mPosition);
	//}
	//if (mState == Context::State::DIE)
	//{
	//	mShape.setFillColor(sf::Color::Transparent);

	//}

	mBehaviour->Update(this);

}

int Entity::getAmmoCount() const
{
	return mAmmoCount;
}

void Entity::Shoot()
{
	mAmmoCount--;
}

Entity::~Entity()
{

}