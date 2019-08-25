#include"pch.h"
#include <sstream>
#include "SplashState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include <iostream>
#include"GameState.h"

namespace pk
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{
		flag = 1;
		visi = 200.0f;
		dx = 0.0f;
		dy = 0.0f;
	}

	void SplashState::Init()
	{
		this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
		
		
		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
		_background.scale(768 / 674.0f, 1024 / 903.0f);
	}

	void SplashState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
		}
	}

	void SplashState::Update(float dt)
	{
		
		//dx = 0.25;
		//dy = 0.25;
		
		

		if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			// Switch To Main Menu
			//_data->window.setView(_data->window.getDefaultView());
			//view.reset(sf::FloatRect(0, 0, 768, 1024));
			//_data->window.setView(view);


			_data->machine.AddState(StateRef(new MainMenuState(_data)),true);
		}
	}

	void SplashState::Draw(float dt)

	{
		//_data->window.setView(_data->window.getDefaultView());
	//	view.reset(sf::FloatRect(dx,dx,100+dx,100+dx));
		//_data->window.setView(view);
		this->_data->window.clear(sf::Color::White);

		this->_data->window.draw(this->_background);
		


		this->_data->window.display();
	}
}
