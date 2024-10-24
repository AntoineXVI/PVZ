#include "Transition.hpp"
#include "Entity.h"
void Transition::setTargetState(Context::State target_state)
{
    mTargetState = target_state;
}

void Transition::addCondition(Condition* condition)
{
    mConditions.push_back(condition);
}


void Transition::Try(Entity* entity)

{
    int true_tests = 0;
    for (const auto &c : mConditions)
    {
        true_tests += c->Test(entity);
    }
    if (true_tests != 0 && true_tests == mConditions.size())
    {
        entity->setState(mTargetState);
    }
}
