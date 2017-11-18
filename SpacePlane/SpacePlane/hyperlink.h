#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class hyperlink : public sf::Text
{
public:
	hyperlink(const std::string text, float x, float y, sf::Font *font, unsigned int size);
	~hyperlink();
	void Update(sf::RenderWindow *window);
	bool onClick(sf::RenderWindow *window);

private:
	bool Hover(sf::RenderWindow *window);

};