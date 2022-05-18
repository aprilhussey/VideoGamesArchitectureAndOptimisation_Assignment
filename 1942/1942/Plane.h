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

	Plane(float scaleX, float scaleY, float originX, float originY, float posX, float posY, sf::Texture &inputTexture);

	~Plane(void);
};

