// Header Files
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Player.h"

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
	sf::Texture playerTexture;

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
	Player player(1.f, 1.f, 32.f, 32.f, 320.f, 700.f, playerTexture);

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
			}
		}
		appWindow.clear();
		appWindow.draw(gameBackgroundSprite);
		appWindow.draw(player.sprite);
		appWindow.display();
	}
}
