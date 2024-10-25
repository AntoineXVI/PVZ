#include "Hit_Condition.h"
#include "Entity.h"

Hit_Condition::Hit_Condition()
{
}

bool Hit_Condition::Test(Entity* entity)
{

	return entity->Collide();
}

Hit_Condition::~Hit_Condition()
{
}
