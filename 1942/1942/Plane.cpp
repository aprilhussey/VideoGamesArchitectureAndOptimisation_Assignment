// Header Files
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Plane.h"
//#include "Game.h"

// Complier Directives
//using namespace std;

// Global variables

Plane::Plane(float scaleX, float scaleY, float originX, float originY, float posX, float posY, float velocity, sf::Texture &inputTexture, sf::Clock *deltaClock)
{
	sprite = sf::Sprite(inputTexture);
	sprite.setScale(scaleX, scaleY);
	sprite.setOrigin(originX, originY);
	sprite.setPosition(posX, posY);
	this->velocity = velocity;
	width = sprite.getGlobalBounds().width;
	height = sprite.getGlobalBounds().height;
	this->deltaClock = deltaClock;
}


Plane::~Plane(void)
{
}
