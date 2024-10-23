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
<<<<<<< HEAD
    virtual ~Action();
    virtual void Start(Plant * Plant) = 0;
    virtual void Update(Plant * Plant) = 0;
    virtual void End(Plant * Plant) = 0;
};
=======
    virtual void Start(Plant* Plant) = 0;
    virtual void Update(Plant* Plant) = 0;
    virtual void End(Plant* Plant) = 0;
    virtual ~Action();
};
>>>>>>> d840a5a326028cdbff159ccaa78cf4ce78cc4fd8
