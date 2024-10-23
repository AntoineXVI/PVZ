#include "Move_Action.h"

Move_Action::Move_Action()
{

}

void Move_Action::Start(Entity* entity)
{
	speed = 1.f;
}

void Move_Action::Update(Entity* entity)
{
	sf::Vector2f Position;
	Position.x = entity->getPosition().x - (1 * speed);
	Position.y = entity->getPosition().y;
	entity->setPosition(Position);
}

void Move_Action::End(Entity* entity)
{

}
