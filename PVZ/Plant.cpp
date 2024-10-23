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

void Plant::setState(Context::State)
{
}

Context::State Plant::getState() const
{
	return Context::State();
}

sf::Color Plant::getColor() const
{
	return mColor;
}

sf::Vector2f Plant::getPosition() const
{
	return mPosition;
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

void Plant::Update()
{
}









