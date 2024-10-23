#include "Plant.hpp"
//Plant::Plant()
//{
//}

Plant::Plant(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count) : Entity(mPosition, mBehaviour)
{
	mPosition = position;
	mBehaviour = plant_behaviour;
	mAmmoCount = ammo_count;
	mMaxAmmo = ammo_count;
	mState = Context::State::IDLE;

	sf::CircleShape shape(10.f);
	mShape = shape;
	mColor = sf::Color(100, 250, 50);
	mShape.setFillColor(mColor);
	mShape.setPosition(position);
}

Plant::~Plant()
{
}

int Plant::getAmmoCount() const
{
	return 0;
}

void Plant::refillMagazine()
{
}

bool Plant::shoot()
{
	return false;
}
