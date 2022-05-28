//Header Files
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Win.h"
#include "Game.h"
#include "MainMenu.h"

// Complier Directives
//using namespace std;

// Global variables

Win::Win(sf::Clock *deltaClock)
{
	this->deltaClock = deltaClock;
}


Win::~Win(void)
{
}

void Win::run(sf::RenderWindow& appWindow, sf::Event& event)
{
	appWindow.setFramerateLimit(30);

	// Local variables
		// You Win
	sf::Vector2f youWinScale(1, 1);
	sf::Vector2f youWinPos(0, 0);

		// Blocktopia Font
	sf::Font blocktopiaFont;
	if (!blocktopiaFont.loadFromFile("Assets/Blocktopia.ttf"))
	{
		std::cout << "Error: Loading font file for font has failed." << "\n";
		system("pause");
	}

	bool nlSelected = true;

	bool incrementing = true;

	int currentColor = 0;

	////////// ////////// ////////// ////////// //////////

	// Load graphics
		// You Win
	sf::Texture youWinTexture;
	if (!youWinTexture.loadFromFile("Assets/1942_You Win.png"))
	{
		std::cout << "Error: Loading image file for youWinTexture has failed." << "\n";
		system("pause");
	}
	sf::Sprite youWinSprite(youWinTexture);
	youWinSprite.setScale(youWinScale);
	youWinSprite.setPosition(youWinPos);

		// Next Level TXT
	sf::Text nextLevelTXT;
	nextLevelTXT.setFont(blocktopiaFont);
	nextLevelTXT.setFillColor(sf::Color::White);
	nextLevelTXT.setStyle(sf::Text::Regular);
	nextLevelTXT.setString("N E X T  L E V E L");
	nextLevelTXT.setCharacterSize(30);
	nextLevelTXT.setPosition(191.5, 440.f);

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
					nlSelected = false;
					nextLevelTXT.setFillColor(sf::Color::White);
				}
				else if (event.key.code == 73)	// If <UP ARROW> is pressed,
				{
					std::cout << "The <UP ARROW> key was pressed" << "\n";
					nlSelected = true;
					mainMenuTXT.setFillColor(sf::Color::White);
				}
				if (event.key.code == 58)	// If <ENTER> is pressed,
				{
					if (nlSelected)
					{
						// Next Level runs
					}
					else if (!nlSelected)
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
		
		if (nlSelected)
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
				nextLevelTXT.setFillColor(sf::Color(currentColor, currentColor, currentColor));
			}
		}
		else if (!nlSelected)
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
		appWindow.draw(youWinSprite);
		appWindow.draw(nextLevelTXT);
		appWindow.draw(mainMenuTXT);
		appWindow.display();
	}
}