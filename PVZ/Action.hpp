#pragma once
#include <SFML/Graphics.hpp>
#include "Context.hpp"
#include "Entity.h"
class Plant;


class Action
{
    Context::State state;
    std::map<Context::State, Action*> mActions;

public:
    Action();
    virtual void Start(Entity* Entity) = 0;
    virtual void Update(Entity* Entity) = 0;
    virtual void End(Entity* Entity) = 0;
    virtual ~Action();
};