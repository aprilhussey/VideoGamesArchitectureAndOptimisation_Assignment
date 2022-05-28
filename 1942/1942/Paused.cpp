//Header Files
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Paused.h"
#include "Game.h"
#include "MainMenu.h"

// Complier Directives
//using namespace std;

// Global variables

Paused::Paused (sf::Clock *deltaClock)
{
	this->deltaClock = deltaClock;
}


Paused::~Paused(void)
{
}

bool Paused::run(sf::RenderWindow& appWindow, sf::Event& event)
{
	appWindow.setFramerateLimit(30);

	// Local variables
		// Paused
	sf::Vector2f pausedScale(1, 1);
	sf::Vector2f pausedPos(0, 0);

		// Blocktopia Font
	sf::Font blocktopiaFont;
	if (!blocktopiaFont.loadFromFile("Assets/Blocktopia.ttf"))
	{
		std::cout << "Error: Loading font file for font has failed." << "\n";
		system("pause");
	}

	bool rsSelected = true;

	bool incrementing = true;

	int currentColor = 0;

	////////// ////////// ////////// ////////// //////////

	// Load graphics
		// Paused
	sf::Texture pausedTexture;
	if (!pausedTexture.loadFromFile("Assets/1942_Paused.png"))
	{
		std::cout << "Error: Loading image file for pausedTexture has failed." << "\n";
		system("pause");
	}
	sf::Sprite pausedSprite(pausedTexture);
	pausedSprite.setScale(pausedScale);
	pausedSprite.setPosition(pausedPos);

		// Resume TXT
	sf::Text resumeTXT;
	resumeTXT.setFont(blocktopiaFont);
	resumeTXT.setFillColor(sf::Color::White);
	resumeTXT.setStyle(sf::Text::Regular);
	resumeTXT.setString("R E S U M E");
	resumeTXT.setCharacterSize(30);
	resumeTXT.setPosition(228.5, 440.f);

		// Main Menu TXT
	sf::Text mainMenuTXT;
	mainMenuTXT.setFont(blocktopiaFont);
	mainMenuTXT.setFillColor(sf::Color::White);
	mainMenuTXT.setStyle(sf::Text::Regular);
	mainMenuTXT.setString("M A I N  M E N U");
	mainMenuTXT.setCharacterSize(30);
	mainMenuTXT.setPosition(195.5, 500.f);

	////////// ////////// ////////// ////////// //////////

	// THE WIN LOOP
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
				if (event.key.code == 74)	// If <DOWN ARROW> is pressed, 
				{
					std::cout << "The <DOWN ARROW> key was pressed" << "\n";
					rsSelected = false;
					resumeTXT.setFillColor(sf::Color::White);
				}
				else if (event.key.code == 73)	// If <UP ARROW> is pressed,
				{
					std::cout << "The <UP ARROW> key was pressed" << "\n";
					rsSelected = true;
					mainMenuTXT.setFillColor(sf::Color::White);
				}
				if (event.key.code == 58)	// If <ENTER> is pressed,
				{
					if (rsSelected)
					{
						// Return to game
						return false;
					}
					else if (!rsSelected)
					{
						// Main Menu runs
						MainMenu mainMenu(deltaClock);
						mainMenu.run(appWindow, event);
					}
				}
			}
		}

		/////////////////////////////////////////////////////////
		// Draw the frame
		
		if (rsSelected)
		{
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
				resumeTXT.setFillColor(sf::Color(currentColor, currentColor, currentColor));
			}
		}
		else if (!rsSelected)
		{
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
				mainMenuTXT.setFillColor(sf::Color(currentColor, currentColor, currentColor));
			}
		}
		appWindow.clear();
		appWindow.draw(pausedSprite);
		appWindow.draw(resumeTXT);
		appWindow.draw(mainMenuTXT);
		appWindow.display();
	}
}