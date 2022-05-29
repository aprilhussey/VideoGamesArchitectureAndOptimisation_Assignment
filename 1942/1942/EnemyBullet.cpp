// Header Files
#include <iostream>
#include <SFML/Graphics.hpp>

#include "EnemyBullet.h"
#include "Game.h"

// Global variables

EnemyBullet::EnemyBullet(float scaleX, float scaleY, float originX, float originY, float posX, float posY, sf::Texture &inputTexture, sf::Clock *deltaClock)
{
	sprite = sf::Sprite(inputTexture);
	sprite.setScale(scaleX, scaleY);
	sprite.setOrigin(originX, originY);
	sprite.setPosition(posX, posY);
	this->deltaClock = deltaClock;
}

EnemyBullet::~EnemyBullet(void)
{
}

void EnemyBullet::shoot(sf::RenderWindow &appWindow, sf::Sprite &bulletSprite)
{
	float speed = 4900.f;
	velocity = sf::Vector2f(0, speed);
}

void EnemyBullet::processBullet()
{
	auto currentPos = sprite.getPosition();
	auto newPos = sf::Vector2f(currentPos.x + (velocity.x * deltaClock->getElapsedTime().asSeconds()), currentPos.y + (velocity.y * deltaClock->getElapsedTime().asSeconds()));
	sprite.setPosition(newPos);
}

bool EnemyBullet::operator == (const EnemyBullet &bullet)
{
	// If velocity and position are equal then they are in this case the same bullet
	return this->velocity == bullet.velocity && this->sprite.getPosition() == bullet.sprite.getPosition();
}