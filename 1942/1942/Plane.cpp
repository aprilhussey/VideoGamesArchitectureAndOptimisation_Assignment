// Header Files
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Plane.h"
//#include "Game.h"

// Complier Directives
//using namespace std;

// Global variables

Plane::Plane(float scaleX, float scaleY, float originX, float originY, float posX, float posY, sf::Texture &inputTexture)
{
	sprite = sf::Sprite(inputTexture);
	sprite.setScale(scaleX, scaleY);
	sprite.setOrigin(originX, originY);
	sprite.setPosition(posX, posY);
	width = sprite.getGlobalBounds().width;
	height = sprite.getGlobalBounds().height;
}


Plane::~Plane(void)
{
}
