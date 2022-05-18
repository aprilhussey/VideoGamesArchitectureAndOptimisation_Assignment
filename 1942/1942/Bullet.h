#pragma once

// Header Files
#include "Game.h"
#include "Player.h"

class Bullet
{
public:
	sf::Sprite sprite;
	sf::Vector2f velocity;

	Bullet::Bullet(float scaleX, float scaleY, float originX, float originY, float posX, float posY, sf::Texture &inputTexture);
	~Bullet(void);

	void shoot(sf::RenderWindow &appWindow, sf::Sprite &bulletSprite);
	void processBullet();
};

