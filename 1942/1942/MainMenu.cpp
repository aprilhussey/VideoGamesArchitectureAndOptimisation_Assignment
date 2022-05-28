// Header Files
#include <iostream>
#include <SFML/Graphics.hpp>

#include "MainMenu.h"
#include "Game.h"

// Complier Directives
//using namespace std;

MainMenu::MainMenu(sf::Clock *deltaClock)
{
	this->deltaClock = deltaClock;
}


MainMenu::~MainMenu(void)
{
}

void MainMenu::run(sf::RenderWindow& appWindow, sf::Event& event)
{
	appWindow.setFramerateLimit(30);

	// Local variables
		// Main Menu Background
	sf::Vector2f mainMenuBackgroundScale(1.f, 1.f);
	sf::Vector2f mainMenuBackgroundPos(0, 0);

		// Blocktopia Font
	sf::Font blocktopiaFont;
	if (!blocktopiaFont.loadFromFile("Assets/Blocktopia.ttf"))
	{
		std::cout << "Error: Loading font file for font has failed." << "\n";
		system("pause");
	}
		
		// Press Enter to Start
	sf::Text pressToStart;
	pressToStart.setFont(blocktopiaFont);
	pressToStart.setFillColor(sf::Color::White);
	pressToStart.setStyle(sf::Text::Regular);
	pressToStart.setString("P R E S S  E N T E R\n    T O  S T A R T");
	pressToStart.setCharacterSize(30);
	pressToStart.setPosition(181.5, 440.f);

	bool incrementing = true;

		// Duration to control animation speed
	int currentColor = 0;
	//float duration = float();

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

	//THE MAIN MENU LOOP
	while (appWindow.isOpen())
	{
		// How much time since last loop?
		float dt = deltaClock->restart().asSeconds();
		//std::cout << "dt = " << dt << "\n"; 

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
					Game game(deltaClock);
					game.run(appWindow, event);
				}
			}
		}
		// Animation duration per frame (0.1f) reached
		if (dt > 0.01f)
		{
			//Restart calculation of the duration
			dt = 0;

			//Loop through the animation colors
			if (currentColor == 0)
			{
				incrementing = true;
			}
			else if (currentColor == 255)
			{
				incrementing = false;
			}
			if (incrementing)
			{
				currentColor += 5;
			}
			else
			{
				currentColor -= 5;
			}
			pressToStart.setFillColor(sf::Color(currentColor, currentColor, currentColor));
		}
		appWindow.clear();
		appWindow.draw(mainMenuBackgroundSprite);
		appWindow.draw(pressToStart);
		appWindow.display();
	}
}
