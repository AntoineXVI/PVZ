#include "Move_Action.h"

Move_Action::Move_Action()
{
}

void Move_Action::Start(Entity* entity)
{
	
}

void Move_Action::Update(Entity* entity)
{
	entity->Move();
}

void Move_Action::End(Entity* entity)
{

}
