// Header Files
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Game.h"

// Complier Directives
//using namespace std;

// Global variables

Player::Player(float scaleX, float scaleY, float originX, float originY, float posX, float posY, sf::Texture &inputTexture) : Plane(scaleX, scaleY, originX, originY, posX, posY, inputTexture)
{
}


Player::~Player(void)
{
}

void Player::moveLeft()
{
	sf::Vector2f pos = sprite.getPosition();
	pos.x = pos.x - 5.f;
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
	pos.x = pos.x + 5.f;
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
	pos.y = pos.y - 5.f;
	if (pos.y < (height / 2) - 11)
	{
		pos.y = (height / 2) - 11;	// The 11 is needed here to make the player move to the edge.
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
	pos.y = pos.y + 5.f;
	if (pos.y > 680 - (height / 2) + 11)
	{
		pos.y = 680 - (height / 2) + 11;	// The 11 is needed here to make the player move to the edge.
		sprite.setPosition(pos.x, pos.y);
	}
	else
	{
		sprite.setPosition(pos.x, pos.y);
	}
}