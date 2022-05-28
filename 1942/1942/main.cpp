//Header Files
#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"

// Complier Directives
//using namespace std;

// Global variables
sf::Event event;
sf::Clock deltaClock;

int main()
{
	sf::Vector2f appWindowCurrentDimensions(600.f, 680.f);
	sf::Vector2f appWindowPerspectiveDimensions(600.f, 680.f);
	sf::RenderWindow appWindow(sf::VideoMode(appWindowCurrentDimensions.x, appWindowCurrentDimensions.y), "1942", sf::Style::Titlebar);

	// Run the Main Menu
	MainMenu mainMenu(&deltaClock);
	mainMenu.run(appWindow, event);

	return 0;
}