#pragma once

// Header Files
#include "Player.h"
#include "Plane.h"

class Player: public Plane
{
public:
	Player(float scaleX, float scaleY, float originX, float originY, float posX, float posY, sf::Texture &inputTexture, sf::Clock *deltaClock);
	~Player(void);

	void moveLeft();
	void moveRight();
	void moveForward();
	void moveBackward();
};

