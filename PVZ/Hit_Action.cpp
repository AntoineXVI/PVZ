#include "Hit_Action.h"
#include "Entity.h"

Hit_Action::Hit_Action()
{

}

void Hit_Action::Start(Entity* entity)
{

}

void Hit_Action::Update(Entity* entity)
{
	entity->TakeDamage();
}

void Hit_Action::End(Entity* entity)
{

}
