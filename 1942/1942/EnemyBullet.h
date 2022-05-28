#pragma once

// Header Files
#include "Game.h"
#include "EnemyBullet.h"

class EnemyBullet
{
public:
	sf::Sprite sprite;
	sf::Vector2f velocity;
	sf::Clock *deltaClock;

	EnemyBullet::EnemyBullet(float scaleX, float scaleY, float originX, float originY, float posX, float posY, sf::Texture &inputTexture, sf::Clock *deltaClock);
	~EnemyBullet(void);

	void shoot(sf::RenderWindow &appWindow, sf::Sprite &bulletSprite);
	void processBullet();
};