#pragma once

// Header Files
#include "Plane.h"
//#include "Game.h"

class Plane
{
public:
	sf::Sprite sprite;
	float width;
	float height;
	sf::Clock *deltaClock;
	float velocity;

	Plane(float scaleX, float scaleY, float originX, float originY, float posX, float posY, float velocity, sf::Texture &inputTexture, sf::Clock *deltaClock);

	~Plane(void);
};

