#include "Die_Action.h"
#include "Entity.h"
#include "Playground.h"

Die_Action::Die_Action()
{
}

void Die_Action::Start(Entity* entity)
{
}

void Die_Action::Update(Entity* entity)
{
	//entity->mColor = sf::Color(100, 100, 10);
	//delete &entity;
	entity->GetShape().setFillColor(sf::Color::Black);
}

void Die_Action::End(Entity* entity)

{
}
