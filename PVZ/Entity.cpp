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

void Entity::setPosition(sf::Vector2f Position)
{
	mPosition = Position;
}

void Entity::setState(Context::State NewState)
{
	mState = NewState;
}

Context::State Entity::getState() const
{
	return Context::State();
}

void Entity::Update()
{
	if (mState == Context::State::MOVE)
	{
		mPosition.x -= 0.01;

		mShape.setPosition(mPosition);
	}
	if (mState == Context::State::DIE)
	{
		mShape.setFillColor(sf::Color::Transparent);

	}
}
