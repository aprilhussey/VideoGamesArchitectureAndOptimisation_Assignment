//Header Files
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Quit.h"
#include "Game.h"
#include "MainMenu.h"

// Global variables

Quit::Quit(sf::Clock *deltaClock)
{
	this->deltaClock = deltaClock;
}


Quit::~Quit(void)
{
}

void Quit::run(sf::RenderWindow& appWindow, sf::Event& event)
{
	appWindow.setFramerateLimit(30);

	// Local variables
		// You Win
	sf::Vector2f quitScale(1, 1);
	sf::Vector2f quitPos(0, 0);

		// Blocktopia Font
	sf::Font blocktopiaFont;
	if (!blocktopiaFont.loadFromFile("Assets/Blocktopia.ttf"))
	{
		std::cout << "Error: Loading font file for font has failed." << "\n";
		system("pause");
	}

	bool yesSelected = true;

	bool incrementing = true;

	int currentColor = 0;

	////////// ////////// ////////// ////////// //////////

	// Load graphics
		// Quit
	sf::Texture quitTexture;
	if (!quitTexture.loadFromFile("Assets/1942_Quit.png"))
	{
		std::cout << "Error: Loading image file for quitTexture has failed." << "\n";
		system("pause");
	}
	sf::Sprite quitSprite(quitTexture);
	quitSprite.setScale(quitScale);
	quitSprite.setPosition(quitPos);

		// Yes TXT
	sf::Text yesTXT;
	yesTXT.setFont(blocktopiaFont);
	yesTXT.setFillColor(sf::Color::White);
	yesTXT.setStyle(sf::Text::Regular);
	yesTXT.setString("Y E S");
	yesTXT.setCharacterSize(30);
	yesTXT.setPosition(270, 440.f);

		// No TXT
	sf::Text noTXT;
	noTXT.setFont(blocktopiaFont);
	noTXT.setFillColor(sf::Color::White);
	noTXT.setStyle(sf::Text::Regular);
	noTXT.setString("N O");
	noTXT.setCharacterSize(30);
	noTXT.setPosition(280, 500.f);

	////////// ////////// ////////// ////////// //////////

	// THE WIN LOOP
	while (appWindow.isOpen())
	{
		// How much time since last loop?
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
					yesSelected = false;
					yesTXT.setFillColor(sf::Color::White);
				}
				else if (event.key.code == 73)	// If <UP ARROW> is pressed,
				{
					std::cout << "The <UP ARROW> key was pressed" << "\n";
					yesSelected = true;
					noTXT.setFillColor(sf::Color::White);
				}
				if (event.key.code == 58)	// If <ENTER> is pressed,
				{
					if (yesSelected)
					{
						// Game window closes
						appWindow.close();
					}
					else if (!yesSelected)
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
		
		if (yesSelected)
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
				yesTXT.setFillColor(sf::Color(currentColor, currentColor, currentColor));
			}
		}
		else if (!yesSelected)
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
				noTXT.setFillColor(sf::Color(currentColor, currentColor, currentColor));
			}
		}
		appWindow.clear();
		appWindow.draw(quitSprite);
		appWindow.draw(yesTXT);
		appWindow.draw(noTXT);
		appWindow.display();
	}
}