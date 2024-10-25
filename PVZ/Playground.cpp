#include "Playground.h"
#include "Behaviour.hpp"
#include "Plant.hpp"

#include "Zombie.h"
#include "Projectile.h"
#include "Transition.hpp"
#include "Condition.hpp"
#include "Shoot_Condition.h"
#include "Shoot_Action.h"
#include "Hit_Condition.h"
#include "Hit_Action.h"
#include "Move_Condition.h"
#include "Move_Action.h"
#include "Die_Condition.h"
#include "Die_Action.h"
namespace
{
    static Playground * sInstance = nullptr;
};

Playground::Playground() 
{
    //plant
    Behaviour* behaviour = new Behaviour(); 

    Transition* shoot_Transition = new Transition();
    shoot_Transition->setTargetState(Context::State::SHOOT);
    shoot_Transition->addCondition(new Shoot_Condition());


    Action* shoot_Action = new Shoot_Action();

    behaviour->AddAction(Context::State::SHOOT, shoot_Action);
    behaviour->AddTransition(Context::State::IDLE, shoot_Transition);


    mPlants.push_back(new Plant(sf::Vector2f(10.f,50.f), behaviour));
    mPlants.push_back(new Plant(sf::Vector2f(10.f, 150.f), behaviour));
    mPlants.push_back(new Plant(sf::Vector2f(10.f, 250.f), behaviour));
    mPlants.push_back(new Plant(sf::Vector2f(10.f, 350.f), behaviour));

    //zombie

    ZombieBehaviour = new Behaviour();


    Transition* move_Transition = new Transition();
    move_Transition->setTargetState(Context::State::MOVE);
    move_Transition->addCondition(new Move_Condition());

    Action* move_Action = new Move_Action();

    ZombieBehaviour->AddAction(Context::State::MOVE, move_Action);
    ZombieBehaviour->AddTransition(Context::State::MOVE, move_Transition);

    //proj

    mProjectilesBehaviour = new Behaviour();

    mProjectilesBehaviour->AddAction(Context::State::MOVE, move_Action);
    mProjectilesBehaviour->AddTransition(Context::State::MOVE, move_Transition);


    //hit
    Transition* hit_Transition = new Transition();
    hit_Transition->setTargetState(Context::State::HIT);
    hit_Transition->addCondition(new Hit_Condition());

    Action* hit_Action = new Hit_Action();

    behaviour->AddAction(Context::State::HIT, hit_Action);
    behaviour->AddTransition(Context::State::IDLE, hit_Transition);
    behaviour->AddTransition(Context::State::SHOOT, hit_Transition);

    mProjectilesBehaviour->AddAction(Context::State::HIT, hit_Action);
    mProjectilesBehaviour->AddTransition(Context::State::MOVE, hit_Transition);

    ZombieBehaviour->AddAction(Context::State::HIT, hit_Action);
    ZombieBehaviour->AddTransition(Context::State::MOVE, hit_Transition);
    
    //die

    Transition* die_Transition = new Transition();
    die_Transition->setTargetState(Context::State::DIE);
    die_Transition->addCondition(new Die_Condition());

    Action* die_Action = new Die_Action();

    behaviour->AddAction(Context::State::DIE, die_Action);
    behaviour->AddTransition(Context::State::IDLE, die_Transition);
    behaviour->AddTransition(Context::State::SHOOT, die_Transition);
    behaviour->AddTransition(Context::State::HIT, die_Transition);

    mProjectilesBehaviour->AddAction(Context::State::DIE, die_Action);
    mProjectilesBehaviour->AddTransition(Context::State::MOVE, die_Transition);
    mProjectilesBehaviour->AddTransition(Context::State::HIT, die_Transition);

    ZombieBehaviour->AddAction(Context::State::DIE, die_Action);
    ZombieBehaviour->AddTransition(Context::State::MOVE, die_Transition);
    ZombieBehaviour->AddTransition(Context::State::HIT, die_Transition);

}



bool Playground::checkCollision(Entity* in, Entity* out) {


    sf::FloatRect inBounds = in->GetShape().getGlobalBounds();

    sf::FloatRect outBounds = out->GetShape().getGlobalBounds();

    // Vérifie si la plante est touché par un zombie
    if (inBounds.intersects(outBounds))
    {
        return true;
        //collision
        //plants[i]->setState(Context::State::HIT);
        //mEnemies[j]->setState(Context::State::DIE);
    }

    return false;
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
    return mZombies;
}


const std::vector<Projectile*>& Playground::getProjectile() const
{
    return mProjectiles;
}

const std::vector<Plant*>& Playground::getPlant() const
{
    return mPlants;
}





void Playground::addProjectiles(sf::Vector2f pos)
{
    Projectile* proj = new Projectile(pos, mProjectilesBehaviour);
    mProjectiles.push_back(proj);
}

void Playground::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < mPlants.size(); i++) {
        window.draw(mPlants[i]->GetShape());
    }
    for (int i = 0; i < mZombies.size(); i++) {
        window.draw(mZombies[i]->GetShape());
    }
     
    for (int i = 0; i < mProjectiles.size(); i++) {
        window.draw(mProjectiles[i]->GetShape());
    }
    
}

void Playground::update()
{
    for (int i = 0; i < mPlants.size(); i++) {
        mPlants[i]->Update();
    }
    for (int i = 0; i < mZombies.size(); i++) {
        mZombies[i]->Update();
    }
    for (int i = 0; i < mProjectiles.size(); i++) {
        mProjectiles[i]->Update();
    }

}

void Playground::handleUserInput(sf::Event& event, sf::RenderWindow& window)
{
    if ((event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left))
    {
        sf::Vector2i MousePosition = sf::Mouse::getPosition(window);
        sf::Vector2i MouseFinalPosition = MousePosition;

        if (MousePosition.y < 100.f) //alignement avec plante
        {
            MouseFinalPosition.y = 50.f;
        }
        else if (MousePosition.y < 200.f)
        {
            MouseFinalPosition.y = 150.f;
        }
        else if (MousePosition.y < 300.f)
        {
            MouseFinalPosition.y = 250.f;
        }
        else
        {
            MouseFinalPosition.y = 350.f;
        }
        if (MousePosition.x < 100.f) //pour ne pas apparaitre trop pres de la plante
        {
            MouseFinalPosition.x = 100.f;
        }
        mZombies.push_back(new Zombie(sf::Vector2f(MouseFinalPosition.x, MouseFinalPosition.y), ZombieBehaviour));
    }
}
Playground::~Playground()
{

}
