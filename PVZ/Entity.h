#pragma once
#include <SFML/Graphics.hpp>
#include "Context.hpp"
class Behaviour;

class Entity
{
public:
    Entity(sf::Vector2f position, Behaviour* behaviour);
    sf::CircleShape GetShape();
    virtual ~Entity();

    sf::Color getColor() const;
    sf::Vector2f getPosition() const;

    void setState(Context::State);
    Context::State getState() const;

    void Update();
protected:
    sf::CircleShape mShape;
    sf::Color mColor;

    sf::Vector2f mPosition;
    std::string mName;
    Context::State mState;
    Behaviour* mBehaviour;
};

