#pragma once

// Header Files
#include "Enemy.h"
#include "Plane.h"

class Enemy: public Plane
{
public:
	Enemy(float scaleX, float scaleY, float originX, float originY, float posX, float posY, float velocity, sf::Texture &inputTexture, sf::Clock *deltaClock);
	~Enemy(void);

	void moveHorizontally();
	bool movingLeft;
};