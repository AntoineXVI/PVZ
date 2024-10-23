#pragma once

#include "Context.hpp"
#include <map>
#include <vector>
//#include "Action.hpp"
class Action;
class Plant;
class Transition;

class Behaviour
{
    std::map<Context::State, std::vector<Action*>> mActions;
    std::map<Context::State, std::vector<Transition*>> mTransitions;
public:
    Behaviour();
    ~Behaviour();

    void Start(Plant *Plant);
    void Update(Plant *Plant);
    void End(Plant *Plant);

    void AddAction(Context::State key, Action* value);
    void AddTransition(Context::State key, Transition* value);
};
