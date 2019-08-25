#include "pch.h"
#include "Land.h"
#include "DEFINITIONS.h"
#include"GameState.h"
#include<iostream>

namespace pk
{
	Land::Land(GameDataRef data) : _data(data)
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Land"));
		sf::Sprite sprite2(this->_data->assets.GetTexture("Land"));
	//	sprite.scale(1, 0.3f);
	//	sprite2.scale(1, 0.3f);

		sprite.setPosition(0, /*this->_data->window.getSize().y */ 1024- (sprite.getGlobalBounds().height)-63);
		std::cout << 1024 - (sprite.getLocalBounds().height)*0.3 << std::endl;
		sprite2.setPosition(sprite.getLocalBounds().width, 1024 - (sprite.getGlobalBounds().height)-63/*this->_data->window.getSize().y - sprite2.getLocalBounds().height*/);

		_landSprites.push_back(sprite);
		_landSprites.push_back(sprite2);
	}

	void Land::MoveLand(float dt, float dx = 0)
	{

		for (unsigned short int i = 0; i < _landSprites.size(); i++)
		{
			sf::Vector2f position = _landSprites.at(i).getPosition();
			float movement =  dx* dt;

			_landSprites.at(i).move(-movement, 0.0f);

			if (_landSprites.at(i).getPosition().x < 0 - _landSprites.at(i).getLocalBounds().width)
			{
				sf::Vector2f position(_data->window.getSize().x, _landSprites.at(i).getPosition().y);

				_landSprites.at(i).setPosition(position);
			}
		}
	}

	void Land::DrawLand()
	{
		for (unsigned short int i = 0; i < _landSprites.size(); i++)
		{
			this->_data->window.draw(_landSprites.at(i));
		}

	}
}