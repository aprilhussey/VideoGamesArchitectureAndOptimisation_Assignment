// Header Files
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "Player.h"
#include "Game.h"

Bullet::Bullet(float scaleX, float scaleY, float originX, float originY, float posX, float posY, sf::Texture &inputTexture, sf::Clock *deltaClock)
{
	sprite = sf::Sprite(inputTexture);
	sprite.setScale(scaleX, scaleY);
	sprite.setOrigin(originX, originY);
	sprite.setPosition(posX, posY);
	this->deltaClock = deltaClock;
}


Bullet::~Bullet(void)
{
}

bool Bullet::operator ==(const Bullet &bullet)
{
	// If velocity and position are equal then they are in this case the same bullet
	return this->velocity == bullet.velocity && this->sprite.getPosition() == bullet.sprite.getPosition();
}

void Bullet::shoot(sf::RenderWindow &appWindow, sf::Sprite &bulletSprite)
{
	float speed = 4900.f;
	velocity = sf::Vector2f(0, -speed);
}

void Bullet::processBullet()
{
	auto currentPos = sprite.getPosition();
	auto newPos = sf::Vector2f(currentPos.x + (velocity.x * deltaClock->getElapsedTime().asSeconds()), currentPos.y + (velocity.y * deltaClock->getElapsedTime().asSeconds()));
	sprite.setPosition(newPos);
}