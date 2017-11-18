#pragma once
#include "game_state.h"
#include "text_field.h"
#include "hyperlink.h"

class login_state : public tiny_state
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	sf::RenderWindow *login_window;

	Text_field *nick_name;
	Text_field *password;

	sf::Font *font;

	hyperlink *logon;

	bool tabKey;
	bool enterKey;
};