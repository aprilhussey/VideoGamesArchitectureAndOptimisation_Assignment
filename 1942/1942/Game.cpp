// Header Files
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Player.h"
#include "Bullet.h"

// Complier Directives
//using namespace std;

// Global variables


Game::Game(void)
{
}


Game::~Game(void)
{
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
	Player player(playerScale.x, playerScale.y, playerOrigin.x, playerOrigin.y, playerPos.x, playerPos.y, playerTexture);

		// Player Bullet
	if (!playerBulletTexture.loadFromFile("Assets/1942_Player Bullet.png"))
	{
		std::cout << "Error: Loading image file for playerBulletTexture has failed." << "\n";
		system("pause");
	}

	std::vector<Bullet> bulletsOnScreen;

	////////// ////////// ////////// ////////// //////////

	// THE GAME LOOP
	while (appWindow.isOpen())
	{
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
				if (event.key.code == 36)	// If <ESC> is pressed, pause the game.
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
					Bullet playerBullet(playerBulletScale.x, playerBulletScale.y, playerBulletOrigin.x, playerBulletOrigin.y, playerBulletPos.x, playerBulletPos.y, playerBulletTexture);
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
		}

		/////////////////////////////////////////////////////////
		// Draw the frame

		appWindow.clear();
		appWindow.draw(gameBackgroundSprite);
		for (auto &bullet : bulletsOnScreen)
		{
			appWindow.draw(bullet.sprite);
		}
		appWindow.draw(player.sprite);
		appWindow.display();
	}
}
