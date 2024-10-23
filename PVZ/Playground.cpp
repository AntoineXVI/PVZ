#include "Playground.h"
#include "Behaviour.hpp"
#include "Plant.hpp"

#include "Zombie.h"
#include "Transition.hpp"
#include "Shoot_Condition.h"
#include "Shoot_Action.h"
namespace
{
    static Playground * sInstance = nullptr;
};

Playground::Playground() 
{
    Behaviour* behaviour = new Behaviour();

    Transition* shoot_Transition = new Transition();
    shoot_Transition->addCondition(new Shoot_Condition());
    shoot_Transition->setTargetState(Context::State::SHOOT);

    Action* shoot_Action = new Shoot_Action();

    behaviour->AddAction(Context::State::SHOOT, shoot_Action);


    mPlants.push_back(new Plant(sf::Vector2f(10.f,50.f), behaviour,5));
    mPlants.push_back(new Plant(sf::Vector2f(10.f, 150.f), behaviour, 5));
    mPlants.push_back(new Plant(sf::Vector2f(10.f, 250.f), behaviour, 5));
    mPlants.push_back(new Plant(sf::Vector2f(10.f, 350.f), behaviour, 5));
}

void Playground::checkCollision(std::vector<Projectile*>& mProjectiles, std::vector<Zombie*>& mEnemies)
{

}



Playground* Playground::instantiate()
{
    if(!sInstance)
    {
        sInstance = new Playground();
        return sInstance;
    }
    return nullptr;
}

Playground* Playground::getInstance()
{
    return sInstance;
}

const std::vector<Zombie*>& Playground::getZombies() const
{
    // TODO: insérer une instruction return ici
    return mZombies;
}


Playground::~Playground()
{

}

void Playground::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < mPlants.size(); i++) {
        window.draw(mPlants[i]->GetShape());
    }
    for (int i = 0; i < mZombies.size(); i++) {
        window.draw(mZombies[i]->GetShape());
    }

}

void Playground::update()
{

}

void Playground::handleUserInput(sf::Event& event, sf::RenderWindow& window)
{
    Behaviour* ZombieBehaviour = new Behaviour(); 
    if ((event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left))
    {
        sf::Vector2i MousePosition = sf::Mouse::getPosition(window);
        float MouseFinalPosition = 0.f;

        if (MousePosition.y < 100.f)
        {
            MouseFinalPosition = 50.f;
        }
        else if (MousePosition.y < 200.f)
        {
            MouseFinalPosition = 150.f;
        }
        else if (MousePosition.y < 300.f)
        {
            MouseFinalPosition = 250.f;
        }
        else
        {
            MouseFinalPosition = 350.f;
        }
        mZombies.push_back(new Zombie(sf::Vector2f(MousePosition.x, MouseFinalPosition), ZombieBehaviour));
    }
}
