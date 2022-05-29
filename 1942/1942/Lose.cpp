//Header Files
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Lose.h"
#include "Game.h"

// Complier Directives
//using namespace std;

// Global variables

Lose::Lose(sf::Clock *deltaClock)
{
	this->deltaClock = deltaClock;
}


Lose::~Lose(void)
{
}

void Lose::run(sf::RenderWindow& appWindow, sf::Event& event)
{
	appWindow.setFramerateLimit(30);

	// Local variables
		// You Lose
	sf::Vector2f youLoseScale(1, 1);
	sf::Vector2f youLosePos(0, 0);

		// Blocktopia Font
	sf::Font blocktopiaFont;
	if (!blocktopiaFont.loadFromFile("Assets/Blocktopia.ttf"))
	{
		std::cout << "Error: Loading font file for font has failed." << "\n";
		system("pause");
	}

	bool rtSelected = true;

	bool incrementing = true;

	int currentColor = 0;

	////////// ////////// ////////// ////////// //////////

	// Load graphics
		// You Lose
	sf::Texture youLoseTexture;
	if (!youLoseTexture.loadFromFile("Assets/1942_You Lose.png"))
	{
		std::cout << "Error: Loading image file for youLoseTexture has failed." << "\n";
		system("pause");
	}
	sf::Sprite youLoseSprite(youLoseTexture);
	youLoseSprite.setScale(youLoseScale);
	youLoseSprite.setPosition(youLosePos);

		// Retry TXT
	sf::Text retryTXT;
	retryTXT.setFont(blocktopiaFont);
	retryTXT.setFillColor(sf::Color::White);
	retryTXT.setStyle(sf::Text::Regular);
	retryTXT.setString("R E T R Y");
	retryTXT.setCharacterSize(30);
	retryTXT.setPosition(244, 440.f);

		// Main Menu TXT
	sf::Text mainMenuTXT;
	mainMenuTXT.setFont(blocktopiaFont);
	mainMenuTXT.setFillColor(sf::Color::White);
	mainMenuTXT.setStyle(sf::Text::Regular);
	mainMenuTXT.setString("M A I N  M E N U");
	mainMenuTXT.setCharacterSize(30);
	mainMenuTXT.setPosition(195.5, 500.f);

	////////// ////////// ////////// ////////// //////////

	// THE LOSE LOOP
	while (appWindow.isOpen())
	{
		float dt = deltaClock->restart().asSeconds();

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
					rtSelected = false;
					retryTXT.setFillColor(sf::Color::White);
				}
				else if (event.key.code == 73)	// If <UP ARROW> is pressed,
				{
					std::cout << "The <UP ARROW> key was pressed" << "\n";
					rtSelected = true;
					mainMenuTXT.setFillColor(sf::Color::White);
				}
				if (event.key.code == 58)	// If <ENTER> is pressed,
				{
					if (rtSelected)
					{
						// Same level runs
						Game game(deltaClock);
						game.run(appWindow, event);
					}
					else if (!rtSelected)
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
		
		if (rtSelected)
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
				retryTXT.setFillColor(sf::Color(currentColor, currentColor, currentColor));
			}
		}
		else if (!rtSelected)
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
		appWindow.draw(youLoseSprite);
		appWindow.draw(retryTXT);
		appWindow.draw(mainMenuTXT);
		appWindow.display();
	}
}