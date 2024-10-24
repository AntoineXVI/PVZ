#include "Behaviour.hpp"
#include "Idle_Action.h"
#include "Action.hpp"
#include "Plant.hpp"
#include "Transition.hpp"

Behaviour::Behaviour()
{
}

Behaviour::~Behaviour()
{
    for (auto it : mTransitions)
    {
        for (int i = 0; i < it.second.size(); ++i)
        {
            delete it.second[i];
        }
    }

    for (auto it : mActions)
    {
        for (int i = 0; i < it.second.size(); ++i)
        {
            delete it.second[i];
        }
    }
}

void Behaviour::AddTransition(Context::State key, Transition* value)
{
    mTransitions[key].push_back(value);
}

void Behaviour::AddAction(Context::State key, Action* value)
{
    mActions[key].push_back(value);
}

void Behaviour::Start(Entity* entity)
{
    for (const auto & a : mActions[entity->getState()])
    {
        a->Start(entity);
    }
}

void Behaviour::Update(Entity* entity)
{
    for (const auto & a : mActions[entity->getState()])
    {
        a->Update(entity);
    }

    for (const auto & a : mTransitions[entity->getState()])
    {
        a->Try(entity);
    }
}

void Behaviour::End(Entity* entity)
{
    for (const auto & a : mActions[entity->getState()])
    {
        a->End(entity);
    }
}

