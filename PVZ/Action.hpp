#pragma once
#include <SFML/Graphics.hpp>
#include "Context.hpp"
class Plant;

class Action
{
    Context::State state;
    std::map<Context::State, Action*> mActions;
public:
    Action();
    virtual void Start(Plant* Plant) = 0;
    virtual void Update(Plant* Plant) = 0;
    virtual void End(Plant* Plant) = 0;
    virtual ~Action();
};
