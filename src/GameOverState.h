#pragma once

#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace pk
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
	};
}