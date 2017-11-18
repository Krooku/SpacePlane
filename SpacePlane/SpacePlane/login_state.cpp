#include "stdafx.h"
#include "login_state.h"
#include <Windows.h>

void login_state::Initialize(sf::RenderWindow* window)
{
	this->login_window = new sf::RenderWindow(sf::VideoMode(500u, 400u), "Login");

	coreState.SetWindow(this->login_window);

	this->nick_name = new Text_field(200.f, 50.f, (float)this->login_window->getSize().x / 2.f, 100.f, "login", false, 20, 2);
	this->password = new Text_field(200.f, 50.f, (float)this->login_window->getSize().x / 2.f, 200.f, "password", true, 20, 2);

	this->font = new sf::Font();
	this->font->loadFromFile("Fonts/Lato-Regular.ttf");

	this->logon = new hyperlink("Zarejestruj sie", (float)this->login_window->getSize().x / 2.f, 300.f, this->font, 32u);

	this->tabKey = true;
	this->enterKey = true;
}
void login_state::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Tab) && !this->tabKey)
	{
		if (this->nick_name->getActive())
		{
			this->nick_name->setActive();
			this->password->setActive();
		}
		else if (this->password->getActive())
		{
			this->password->setActive();
			this->nick_name->setActive();
		}
		else
		{
			this->nick_name->setActive();
		}
	}

	if (coreState.GetEvent() != NULL && coreState.GetEvent()->type == sf::Event::TextEntered)
	{
		this->nick_name->Write(*coreState.GetEvent());
		this->password->Write(*coreState.GetEvent());
		coreState.SetEvent(NULL);
	}

	this->nick_name->Update(this->login_window);
	this->password->Update(this->login_window);
	this->logon->Update(this->login_window);
	if (this->logon->onClick(this->login_window))
		ShellExecute(NULL, L"open", L"http://google.pl", NULL, NULL, SW_SHOWNORMAL);

	this->enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
	this->tabKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Tab);
}
void login_state::Render(sf::RenderWindow* window)
{
	this->nick_name->Render(this->login_window);
	this->password->Render(this->login_window);
	this->login_window->draw(*this->logon);
}
void login_state::Destroy(sf::RenderWindow* window)
{
	delete this->login_window;
	delete this->nick_name;
	delete this->password;
	delete this->font;
	delete this->logon;
}