// Header Files
#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Win.h"
#include "Lose.h"
#include "EnemyBullet.h"

// Complier Directives
//using namespace std;

Game::Game(sf::Clock *deltaClock)
{
	this->deltaClock = deltaClock;
}


Game::~Game(void)
{
}

int Game::getRandomNum()
{
	std::random_device rd;	// Creates a random device called rd
	std::uniform_int_distribution<int> distribution(1, 1000);	// Generates number in the range 1 - 1000
	int randomNum = distribution(rd);
	//std::cout << randomNum << "\n";

	return randomNum;
}

void Game::run(sf::RenderWindow& appWindow, sf::Event& event)
{
	// Local variables
		// Game Background
	sf::Vector2f gameBackgroundScale(1.f, 1.f);
	sf::Vector2f gameBackgroundPos(0, 0);

		// Player
	sf::Vector2f playerScale(1.f, 1.f);
	sf::Vector2f playerOrigin(91.f/2, 57.f/2);
	sf::Vector2f playerPos(300.f, 580.f);
	sf::Texture playerTexture;

		// Player Bullet
	sf::Vector2f playerBulletScale(1.f, 1.f);
	sf::Vector2f playerBulletOrigin(45.f/2, 7.f/2);
	sf::Vector2f playerBulletPos;
	sf::Texture playerBulletTexture;

	bool shooting = false;

		// Enemy
	sf::Vector2f enemyScale(1.f, 1.f);
	sf::Vector2f enemyOrigin(91.f/2, 57.f/2);
	sf::Vector2f enemyPos(300.f, 200.f);
	sf::Texture enemyTexture;

		// Enemy Bullet
	sf::Vector2f enemyBulletScale(1.f, 1.f);
	sf::Vector2f enemyBulletOrigin(45.f/2, 7.f/2);
	sf::Vector2f enemyBulletPos;
	sf::Texture enemyBulletTexture;

	bool enemyKilled = false;
	bool playerKilled = false;

	////////// ////////// ////////// ////////// //////////

	// Load graphics
		// Game Background
	sf::Texture gameBackgroundTexture;
	if (!gameBackgroundTexture.loadFromFile("Assets/1942_Game Background.png"))
	{
		std::cout << "Error: Loading image file for gameBackgroundTexture has failed." << "\n";
		system("pause");
	}
	sf::Sprite gameBackgroundSprite(gameBackgroundTexture);
	gameBackgroundSprite.setScale(gameBackgroundScale);
	gameBackgroundSprite.setPosition(gameBackgroundPos);

		// Player
	if (!playerTexture.loadFromFile("Assets/1942_Player.png"))
	{
		std::cout << "Error: Loading image file for playerTexture has failed." << "\n";
		system("pause");
	}
	Player player(playerScale.x, playerScale.y, playerOrigin.x, playerOrigin.y, playerPos.x, playerPos.y, 4900.0f, playerTexture, deltaClock);

		// Player Bullet
	if (!playerBulletTexture.loadFromFile("Assets/1942_Player Bullet.png"))
	{
		std::cout << "Error: Loading image file for playerBulletTexture has failed." << "\n";
		system("pause");
	}

	std::vector<Bullet> bulletsOnScreen;

		// Enemy
	if (!enemyTexture.loadFromFile("Assets/1942_Enemy.png"))
	{
		std::cout << "Error: Loading image file for enemyTexture has failed." << "\n";
		system("pause");
	}
	Enemy enemy(enemyScale.x, enemyScale.y, enemyOrigin.x, enemyOrigin.y, enemyPos.x, enemyPos.y, 3500.0f, enemyTexture, deltaClock);
	
		// Enemy Bullet
	if (!enemyBulletTexture.loadFromFile("Assets/1942_Enemy Bullet.png"))
	{
		std::cout << "Error: Loading image file for enemyBulletTexture has failed." << "\n";
		system("pause");
	}

	std::vector<EnemyBullet> enemyBulletsOnScreen;

	////////// ////////// ////////// ////////// //////////

	// THE GAME LOOP
	while (appWindow.isOpen())
	{
		// How much time since last loop?
		float dt = deltaClock->restart().asSeconds();
		std::cout << "dt = " << dt << "\n"; 

		enemy.moveHorizontally();

		int randomNumber = getRandomNum();
		if (randomNumber <= 15)
		{
			enemyBulletPos = enemy.sprite.getPosition();
			EnemyBullet enemyBullet(enemyBulletScale.x, enemyBulletScale.y, enemyBulletOrigin.x, enemyBulletOrigin.y, enemyBulletPos.x, enemyBulletPos.y, enemyBulletTexture, deltaClock);
			enemyBullet.sprite.setRotation(180);
			enemyBullet.shoot(appWindow, enemyBullet.sprite);
			enemyBulletsOnScreen.emplace_back(enemyBullet);
		}

		while (appWindow.pollEvent(event))
		{
			// Update state based on events
			if (event.type == sf::Event::Closed)
			{
				appWindow.close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				//std::cout << event.key.code << "\n";
				////////// ////////// ////////// ////////// //////////
				if (event.key.code == 36)	// If <ESC> is pressed, pause the game. Currently exits.
				{
					//std::cout << "The <ESC> key was pressed" << "\n";
					appWindow.close();
				}
				if (event.key.code == 71)	// If <LEFT ARROW> is pressed, move forward.
				{
					//std::cout << "The <LEFT ARROW> key was pressed" << "\n";
					player.moveLeft();
				}
				if (event.key.code == 72)	// If <RIGHT ARROW> is pressed, move forward.
				{
					//std::cout << "The <RIGHT ARROW> key was pressed" << "\n";
					player.moveRight();
				}
				if (event.key.code == 73)	// If <UP ARROW> is pressed, move forward.
				{
					//::cout << "The <UP ARROW> key was pressed" << "\n";
					player.moveForward();
				}
				if (event.key.code == 74)	// If <DOWN ARROW> is pressed, move backward.
				{
					//std::cout << "The <DOWN ARROW> key was pressed" << "\n";
					player.moveBackward();
				}
				////////// ////////// ////////// ////////// //////////
				if (event.key.code == 18)	// If <S> is pressed, shoot bullets.
				{
					//std::cout << "The <S> key was pressed" << "\n";
					playerBulletPos = player.sprite.getPosition();
					Bullet playerBullet(playerBulletScale.x, playerBulletScale.y, playerBulletOrigin.x, playerBulletOrigin.y, playerBulletPos.x, playerBulletPos.y, playerBulletTexture, deltaClock);
					playerBullet.shoot(appWindow, playerBullet.sprite);
					bulletsOnScreen.emplace_back(playerBullet);
				}
			}
		}

		//////////////////////////////////////////////////////////
		// Process all items for this tick before drawing the frame

		// Process bullets
		for (auto &bullet : bulletsOnScreen)
		{
			bullet.processBullet();
			if (bullet.sprite.getGlobalBounds().intersects(enemy.sprite.getGlobalBounds()))
			{
				std::cout << "Bullet collision with enemy" << "\n";
				enemyKilled = true;
			}
		}

		for (auto &enemybullet : enemyBulletsOnScreen)
		{
			enemybullet.processBullet();
			if (player.sprite.getGlobalBounds().intersects(enemybullet.sprite.getGlobalBounds()))
			{
				std::cout << "Bullet collision with player" << "\n";
				playerKilled = true;
			}
		}

		// Process player collision with enemy
		if (player.sprite.getGlobalBounds().intersects(enemy.sprite.getGlobalBounds()))
		{
			std::cout << "Player collision with enemy" << "\n";
			playerKilled = true;
		}

		/////////////////////////////////////////////////////////
		// Draw the frame

		appWindow.clear();
		appWindow.draw(gameBackgroundSprite);

		for (auto &bullet : bulletsOnScreen)
		{
			appWindow.draw(bullet.sprite);
		}

		for (auto &enemybullet : enemyBulletsOnScreen)
		{
			appWindow.draw(enemybullet.sprite);
		}

		if (!playerKilled)	// If the player is not killed, draw it
		{
			appWindow.draw(player.sprite);
		}
		else
		{
			appWindow.clear();
			Lose lose(deltaClock);
			lose.run(appWindow, event);
		}

		if (!enemyKilled)	// If the enemy is not killed, draw it
		{
			appWindow.draw(enemy.sprite);
		}
		else
		{
			appWindow.clear();
			Win win(deltaClock);
			win.run(appWindow, event);
		}
		appWindow.display();
	}
}