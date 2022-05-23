// Header Files
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Game.h"

// Complier Directives
//using namespace std;

// Global variables
float velocity = 4900.f;

Player::Player(float scaleX, float scaleY, float originX, float originY, float posX, float posY, sf::Texture &inputTexture, sf::Clock *deltaClock) : Plane(scaleX, scaleY, originX, originY, posX, posY, inputTexture, deltaClock)
{
}


Player::~Player(void)
{
}

void Player::moveLeft()
{
	sf::Vector2f pos = sprite.getPosition();
	pos.x = pos.x - velocity * deltaClock->getElapsedTime().asSeconds();
	if (pos.x < width / 2)
	{
		pos.x = width / 2;
		sprite.setPosition(pos.x, pos.y);
	}
	else
	{
		sprite.setPosition(pos.x, pos.y);
	}
}

void Player::moveRight()
{
	sf::Vector2f pos = sprite.getPosition();
	pos.x = pos.x + velocity * deltaClock->getElapsedTime().asSeconds();
	if (pos.x > 600 - (width / 2))
	{
		pos.x = 600 - (width / 2);
		sprite.setPosition(pos.x, pos.y);
	}
	else
	{
		sprite.setPosition(pos.x, pos.y);
	}
}

void Player::moveForward()
{
	sf::Vector2f pos = sprite.getPosition();
	pos.y = pos.y - velocity * deltaClock->getElapsedTime().asSeconds();
	if (pos.y < (height / 2))
	{
		pos.y = (height / 2);
		sprite.setPosition(pos.x, pos.y);
	}
	else
	{
		sprite.setPosition(pos.x, pos.y);
	}
}

void Player::moveBackward()
{
	sf::Vector2f pos = sprite.getPosition();
	pos.y = pos.y + velocity * deltaClock->getElapsedTime().asSeconds();
	if (pos.y > 680 - (height / 2))
	{
		pos.y = 680 - (height / 2);
		sprite.setPosition(pos.x, pos.y);
	}
	else
	{
		sprite.setPosition(pos.x, pos.y);
	}
}