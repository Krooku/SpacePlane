// SpacePlane.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include <mysql.h>

#include <iostream>
#include <conio.h>

int main()
{
	std::cout << "działa" << std::endl;
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	_getch();
	return 0;
}