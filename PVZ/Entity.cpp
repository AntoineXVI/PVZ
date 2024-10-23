#include "Entity.h"

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
	return sf::Color();
}

sf::Vector2f Entity::getPosition() const
{
	return sf::Vector2f();
}

void Entity::setState(Context::State)
{
}

Context::State Entity::getState() const
{
	return Context::State();
}

void Entity::Update()
{
}
