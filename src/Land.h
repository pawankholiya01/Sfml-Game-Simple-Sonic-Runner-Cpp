#pragma once

#include "SFML/Graphics.hpp"
#include "Game.h"
#include <vector>

namespace pk
{
	class Land
	{
	public:
		Land(GameDataRef data);

		void MoveLand(float dt,float dx);
		void DrawLand();

	private:
		GameDataRef _data;

		std::vector<sf::Sprite>_landSprites;

	};
}