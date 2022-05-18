// Header Files
#include <iostream>
#include <SFML/Graphics.hpp>

#include "MainMenu.h"

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
	
	// Load graphics

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
		}
		appWindow.clear();
		//appWindow.draw();
	}
}
