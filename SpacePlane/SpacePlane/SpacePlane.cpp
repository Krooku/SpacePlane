// SpacePlane.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include <mysql.h>

#include <iostream>
#include <Windows.h>

#include "game_state.h"
#include "text_field.h"
#include "hyperlink.h"
#include "login_state.h"

game_state coreState;

int main()
{
	coreState.SetState(new login_state);

	sf::Color bg_color(51u, 51u, 0u);

	while (coreState.GetWindow()->isOpen())
	{
		sf::Event event;
		//coreState.SetEvent(&event);
		while (coreState.GetWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::TextEntered)
			{
				coreState.SetEvent(&event);
				//nick_name.Write(event);
				//password.Write(event);
			}
			else if (event.type == sf::Event::Closed) 
			{
				coreState.GetWindow()->close();
				return 0;
			}
		}

		coreState.GetWindow()->clear(bg_color);

		coreState.Update();
		coreState.Render();

		coreState.GetWindow()->display();
	}
	return 0;
}