#pragma 

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace pk
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;


		sf::View view;
		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;

	};
}
