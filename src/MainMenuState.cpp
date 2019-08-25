#include"pch.h"
#include <sstream>
#include "MainMenuState.h"
#include"GameState.h"
#include "DEFINITIONS.h"

#include <iostream>

namespace pk
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}

	void MainMenuState::Init()
	{
		
		this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);

		this->_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);

		this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));

		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_background.scale(1, 1024 / 740.0f);
		

		_playButton .setTexture(this->_data->assets.GetTexture("Play Button"));
	
		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), 100/*_title.getGlobalBounds().height / 2*/);

		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2),SCREEN_HEIGHT/2- _playButton.getGlobalBounds().height/2+80);
	
	
	    
	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new GameState(_data)), true);
			


				//std::cout << "Game Khel simon" << std::endl;
			}
		}
	}

	void MainMenuState::Update(float dt)
	{
		
	}

	void MainMenuState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_playButton);

		this->_data->window.display();
	}
}
