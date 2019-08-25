#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Pipe.h"
#include "Land.h"

namespace pk
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		//Pipe *pipe;
		sf::View view;
		int dx,dy;
		int rot;

		int tm,count;



		sf::IntRect rect;

		sf::IntRect backrect;

		bool isonjump,isclimbing,isfalling;
		sf::Clock cl,clj;

		sf::Clock clock;
		Land *land;
		sf::Sprite _player;
		sf::Sprite _background;
	};
}