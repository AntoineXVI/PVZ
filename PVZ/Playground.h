#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<vector>

class Plant;
class Projectile;
class Zombie;


class Playground
{
private:
	std::vector<Plant*> mPlants;
	Playground();
	void checkCollision(
		std::vector<Projectile*>& mProjectiles,
		std::vector<Zombie*>& mEnemies);
public:
	static Playground* instantiate();
	static Playground* getInstance();
	~Playground();
	void draw(sf::RenderWindow& window);
	void update();
	void handleUserInput(sf::Event& event, sf::RenderWindow&
		window);
};