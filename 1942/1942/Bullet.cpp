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
	//float speed = 0.13;
	
	sf::Vector2f bulletSpritePos = bulletSprite.getPosition();
	while (bulletSpritePos.y >= 0)
	{
		bulletSprite.move(0, -5);
		appWindow.draw(bulletSprite);
		appWindow.display();
		bulletSpritePos.y = bulletSpritePos.y - 5;
	}
}
