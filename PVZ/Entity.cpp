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
