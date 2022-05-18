// Header Files
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "Player.h"
#include "Game.h"

// Complier Directives
//using namespace std;

// Global variables

Bullet::Bullet(float scaleX, float scaleY, float originX, float originY, float posX, float posY, sf::Texture &inputTexture)
{
	sprite = sf::Sprite(inputTexture);
	sprite.setScale(scaleX, scaleY);
	sprite.setOrigin(originX, originY);
	sprite.setPosition(posX, posY);
}


Bullet::~Bullet(void)
{
}

void Bullet::shoot(sf::RenderWindow &appWindow, sf::Sprite &bulletSprite)
{
	float speed = 0.25;
	velocity = sf::Vector2f(0, -speed);
	
	/*
	std::vector<sf::Vector2f> pos;
	sf::Vector2f bulletSpritePos = bulletSprite.getPosition();
	sf::Vector2f direction(bulletSpritePos.x, -5);

	pos.push_back(sf::Vector2f(bulletSpritePos));
	appWindow.draw(bulletSprite);

	if (bulletSpritePos.y >= -5)
	{
		bulletSpritePos.y = bulletSpritePos.y - 5;
		bulletSprite.setPosition(bulletSpritePos.x, bulletSpritePos.y);
		appWindow.draw(bulletSprite);
	}
	*/
	/*sf::Vector2f bulletSpritePos = bulletSprite.getPosition();
	sf::Vector2i up(bulletSpritePos.x, -5);

	float distanceX = up.x - bulletSpritePos.x;
	float distanceY = (up.y - bulletSpritePos.y) * -1;
	float angleRad = atan2(distanceX, distanceY);

	sf::Vector2f direction(cos(angleRad), sin(angleRad));
	velocity = direction * speed;*/
}

void Bullet::processBullet()
{
	auto currentPos = sprite.getPosition();
	auto newPos = sf::Vector2f(currentPos.x + velocity.x, currentPos.y + velocity.y);
	sprite.setPosition(newPos);
}