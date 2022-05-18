//Header Files
#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "Game.h"
#include "Player.h"

// Complier Directives
//using namespace std;

// Global variables
sf::Event event;

int main()
{
	sf::Vector2f appWindowCurrentDimensions(640.f, 800.f);
	sf::Vector2f appWindowPerspectiveDimensions(640.f, 800.f);
	sf::RenderWindow appWindow(sf::VideoMode(appWindowCurrentDimensions.x, appWindowCurrentDimensions.y), "1942", sf::Style::Titlebar);

	/*
	// Create the Main Menu
	MainMenu mainMenu;
	mainMenu.run(appWindow, event);
	*/

	// Run Game
	Game game;
	game.run(appWindow, event);

	return 0;
}