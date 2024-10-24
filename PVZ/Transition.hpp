#pragma once

#include "Context.hpp"
#include "Condition.hpp"

#include <vector>

class Entity;

class Transition
{
protected:
    Context::State mTargetState;
    std::vector<Condition*> mConditions;

public:
    void Try(Entity* Plant);
    void setTargetState(Context::State target_state);
    void addCondition(Condition* condition);
};
