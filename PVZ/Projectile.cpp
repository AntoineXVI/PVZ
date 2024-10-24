#include "Projectile.h"

Projectile::Projectile(sf::Vector2f position, Behaviour* plant_behaviour) : Entity(mPosition, mBehaviour)
{
	mPosition = position;
	mBehaviour = plant_behaviour;
	mState = Context::State::MOVE;

	sf::CircleShape shape(100.f);
	mShape = shape;
	mColor = sf::Color(100, 250, 50);
	mShape.setFillColor(mColor);
	mShape.setPosition(position);
}

Projectile::~Projectile()
{
}
