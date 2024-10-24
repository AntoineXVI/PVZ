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

Entity::~Entity()
{
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
}

void Entity::setState(Context::State state)
{
	mState = state;
}

Context::State Entity::getState() const
{
	return mState;
}

void Entity::Update()
{
	mBehaviour->Update(this);
}
