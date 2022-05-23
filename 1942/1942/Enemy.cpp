// Header Files
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Enemy.h"
#include "Game.h"

// Complier Directives
//using namespace std;

Enemy::Enemy(float scaleX, float scaleY, float originX, float originY, float posX, float posY, float velocity, sf::Texture &inputTexture, sf::Clock *deltaClock) : Plane(scaleX, scaleY, originX, originY, posX, posY, velocity, inputTexture, deltaClock)
{
	movingLeft = true;
	sprite.setRotation(180);
}

Enemy::~Enemy(void)
{
}

void Enemy::moveHorizontally()
{
	sf::Vector2f pos = sprite.getPosition();

	if (pos.x < width / 2)	// If pos.x is outside the left of the game window, move in the opposite direction
	{
		movingLeft = false;
	}
	else if (pos.x > 600 - (width / 2))	// If pos.x is outside the right of the game window, move in the opposite direction
	{
		movingLeft = true;
	}

	if (movingLeft)
	{
		pos.x = pos.x - velocity * deltaClock->getElapsedTime().asSeconds();
	}
	else
	{
		pos.x = pos.x + velocity * deltaClock->getElapsedTime().asSeconds();
	}

	sprite.setPosition(pos.x, pos.y);
}