//Header Files
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Lose.h"
#include "Game.h"

// Complier Directives
//using namespace std;

// Global variables

Lose::Lose(void)
{
	//this->deltaClock = deltaClock;
}


Lose::~Lose(void)
{
}

void Lose::run(sf::RenderWindow& appWindow, sf::Event& event)
{
	// Local variables
		// You Lose
	sf::Vector2f youLoseScale(1, 1);
	sf::Vector2f youLosePos(0, 0);

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

	////////// ////////// ////////// ////////// //////////

	// THE LOSE LOOP
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
		appWindow.draw(youLoseSprite);
		appWindow.display();
	}
}