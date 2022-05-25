//Header Files
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Win.h"
#include "Game.h"

// Complier Directives
//using namespace std;

// Global variables

Win::Win(void)
{
	//this->deltaClock = deltaClock;
}


Win::~Win(void)
{
}

void Win::run(sf::RenderWindow& appWindow, sf::Event& event)
{
	// Local variables
		// You Win
	sf::Vector2f youWinScale(1, 1);
	sf::Vector2f youWinPos(0, 0);

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

	////////// ////////// ////////// ////////// //////////

	// THE WIN LOOP
	while (appWindow.isOpen())
	{
		//float dt = deltaClock.restart().asSeconds();
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
			}
		}
		/////////////////////////////////////////////////////////
		// Draw the frame

		appWindow.clear();
		appWindow.draw(youWinSprite);
		appWindow.display();
	}
}