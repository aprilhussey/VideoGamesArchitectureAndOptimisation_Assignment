// Header Files
#include <iostream>
#include <SFML/Graphics.hpp>

#include "MainMenu.h"
#include "Game.h"

// Complier Directives
//using namespace std;

// Global variables


MainMenu::MainMenu(void)
{
}


MainMenu::~MainMenu(void)
{
}

void MainMenu::run(sf::RenderWindow& appWindow, sf::Event& event)
{
	// Local variables
		// Main Menu Background
	sf::Vector2f mainMenuBackgroundScale(1.f, 1.f);
	sf::Vector2f mainMenuBackgroundPos(0, 0);
		// Press Enter to Start
	sf::Vector2f pressToStartScale(1.f, 1.f);
	sf::Vector2f pressToStartPos(181.5, 440.f);

	// Load graphics
		// Main Menu Background
	sf::Texture mainMenuBackgroundTexture;
	if (!mainMenuBackgroundTexture.loadFromFile("Assets/1942_Main Menu Background.png"))
	{
		std::cout << "Error: Loading image file for mainMenuBackgroundTexture has failed." << "\n";
		system("pause");
	}
	sf::Sprite mainMenuBackgroundSprite(mainMenuBackgroundTexture);
	mainMenuBackgroundSprite.setScale(mainMenuBackgroundScale);
	mainMenuBackgroundSprite.setPosition(mainMenuBackgroundPos);

		// Press Enter to Start
	sf::Texture pressToStartTexture;
	if (!pressToStartTexture.loadFromFile("Assets/1942_Press Enter to Start.png"))
	{
		std::cout << "Error: Loading image file for pressToStartTexture has failed." << "\n";
		system("pause");
	}
	sf::Sprite pressToStartSprite(pressToStartTexture);
	pressToStartSprite.setScale(pressToStartScale);
	pressToStartSprite.setPosition(pressToStartPos);

	//THE MAIN MENU LOOP
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
				std::cout << event.key.code << "\n";
				////////// ////////// ////////// ////////// //////////
				/*if (event.key.code == 36)	// If <ESC> is pressed, pause the game.
				{
					//std::cout << "The <ESC> key was pressed" << "\n";
				}*/
				if (event.key.code == 58)	// If <ENTER> is pressed, start the game.
				{
					//std::cout << "The <ENTER> key was pressed" << "\n";
					Game game;
					game.run(appWindow, event);
				}
			}
		}
		appWindow.clear();
		appWindow.draw(mainMenuBackgroundSprite);
		appWindow.draw(pressToStartSprite);
		appWindow.display();
	}
}
