#include "stdafx.h"
#include "hyperlink.h"
#include <Windows.h>

hyperlink::hyperlink(const std::string text, float x, float y, sf::Font *font, unsigned int size) : sf::Text(text, *font, size)
{
	this->setFillColor(sf::Color::Red);
	this->setOrigin(this->getGlobalBounds().width / 2.f, this->getGlobalBounds().height / 2.f);
	this->setPosition(x, y);
}

void hyperlink::Update(sf::RenderWindow *window)
{
	if (this->Hover(window))
	{
		this->setFillColor(sf::Color::Blue);
	}
	else
	{
		this->setFillColor(sf::Color::Red);
	}
}

bool hyperlink::Hover(sf::RenderWindow *window)
{
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window);
	if (mouse_pos.x <= (int)(this->getPosition().x + this->getGlobalBounds().width / 2.f) && mouse_pos.x >= (int)(this->getPosition().x - this->getGlobalBounds().width / 2.f) && mouse_pos.y <= (int)(this->getPosition().y + this->getGlobalBounds().height / 2.f) && mouse_pos.y >= (int)(this->getPosition().y - this->getGlobalBounds().height / 2.f))
		return true;
	return false;
}

bool hyperlink::onClick(sf::RenderWindow *window)
{
	if (this->Hover(window) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		return true;
	return false;
}


hyperlink::~hyperlink()
{

}