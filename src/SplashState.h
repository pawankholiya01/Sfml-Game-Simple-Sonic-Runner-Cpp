#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace pk
{
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Clock _clock;
		sf::Clock cl;
		sf::View view;
		float visi;
		float dx, dy;
		int flag ;
		sf::Texture _backgroundTexture;
		sf::Sprite _background;
	};
}