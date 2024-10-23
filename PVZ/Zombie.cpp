#include "Zombie.h"


Zombie::Zombie(sf::Vector2f position, Behaviour* zombie_behaviour) : Entity(mPosition, mBehaviour)
{
	mPosition = position;
	mBehaviour = zombie_behaviour;
	mState = Context::State::MOVE;

	sf::CircleShape shape(10.f);
	mShape = shape;
	mColor = sf::Color(250, 0, 0);
	mShape.setFillColor(mColor);
	mShape.setPosition(position);
}

Zombie::~Zombie()
{

}
