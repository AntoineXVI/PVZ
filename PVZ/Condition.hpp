#pragma once

class Entity;

class Condition 
{
public:
    Condition();
    ~Condition();
    virtual bool Test(Entity* entity) = 0;
};
