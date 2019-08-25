#include"pch.h"
#include <sstream>
#include "GameState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include <iostream>
#include "Land.h"

namespace pk
{
	GameState ::GameState(GameDataRef data) : _data(data)
	{
		count = 0;
		isonjump = false;
		rect.left = 0;
		rect.top = 0;
		rect.height = 115;
		rect.width = 102;

		backrect.top = 180;
		backrect.height = 88;
		backrect.width = 100;
		backrect.left = 540; 


	}

	void GameState::Init()
	{
		dx = 0;
		rot;
		std::cout << "Game aa gya ";


		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);

		this->_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);

		this->_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);

		this->_data->assets.LoadTexture("Land", LAND_FILEPATH);

		this->_data->assets.LoadTexture("Player1", PLAYER_FILEPATH1);

		this->_data->assets.LoadTexture("Player2", PLAYER_FILEPATH2);


		_player.setTexture(this->_data->assets.GetTexture("Player1"));
		//sf::IntRect rect(0, 200, 100, 300);
		_player.setTextureRect(rect);

	
		
		land = new Land(_data);
		_player.setPosition(400, 774.2);
		_player.setOrigin(100, 110);
	//	_player.scale(3, 3);
		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		_background.scale(2,2);
	
	}

	void GameState::HandleInput()
	{

		int a = 0, b = 200, x = 106 , y=300;
		sf::Event event;

		/*


		rect.left = a;
		rect.top = b;

		rect.height = 100;
		rect.width = 106;
		*/


		
		this->_data->window.pollEvent(event);

		//while (this->_data->window.pollEvent(event))
		//{
			//std::cout << 2;

			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (sf::Event::KeyPressed&&sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				dx = -300;
				if (isonjump == false)
				{
					if (cl.getElapsedTime().asSeconds() > 0.08)
					{
						if (dx == 0)
						{
							rect.top = 0;
							rect.left = 710;

						}


						rect.left = rect.left - 102;

						if (rect.left <= 0)
						{
							rect.top = 0;
							rect.left = 710;
						}
						else
							if (rect.top > 200 && rect.left < 440)
							{
								rect.top = 180;
								rect.left = 540;

							}

						std::cout << rect.left << std::endl;
						_player.setTexture(this->_data->assets.GetTexture("Player2"));

						_player.setTextureRect(rect);


						cl.restart();

					    
					}
				}
				else
				{
					rect.top = 230;
					rect.left = rect.left + 102;

					if (rect.left >= 920)
					{
						//rect.top = 270;
						rect.left = 104;
					}
					_player.setTextureRect(rect);



				}
				
				/*rot -= 20;
				if (rot <= -40)
					rot = -40;
				                    //_player.setTexture(this->_data->assets.GetTexture("Player2"));
				_player.setRotation(rot);
				*/

				dx = -300;

			}
			else
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					if (isonjump == false)
					{
						_player.setTexture(this->_data->assets.GetTexture("Player1"));
						std::cout << " * ";
						/*if (dx == 0)
						{
							rect.top = 180;
							rect.left = 400;
						}*/


						if (cl.getElapsedTime().asSeconds() > 0.08)
						{


							std::cout << "!!";
							//rect.left = 0;
							//rect.top = 0;

	//                      rect.height = 100;
		//					rect.width = 106;

							//_player.setTextureRect(rect);


							rect.left = rect.left + 102;

							if (rect.left >= 1020)
							{
								//rect.top = 270;
								rect.left = 204;
							}
							else
								if (rect.top > 200 && rect.left > 190)
								{
									rect.top = 180;
									rect.left = 0;

								}

							std::cout << rect.left << std::endl;
							_player.setTextureRect(rect);

							//this->_data->window.draw(this->_player);


							//	rot += 10;
							//	if (rot >= 60)
								//	rot = 40;				                  //	_player.setTexture(this->_data->assets.GetTexture("Player1"));
						//	_player.setRotation(rot);

							dx = 300;
							cl.restart();
						}

					}
					else
					{
						rect.top = 230;
						rect.left = rect.left + 102;

						if (rect.left >= 920)
						{
							//rect.top = 270;
							rect.left = 104;
						}
						_player.setTextureRect(rect);




					}
					dx = 300;
					
				}
				else 
				{
					if (dx == 300)
					{
						rect.top = 0;
						rect.left = 0;

					//	_player.setTextureRect(rect);

						//this->_data->window.draw(this->_player);

					}
					else
						if (dx == -300)
						{
							rect.top = 0;
							rect.left = 920;

						}

					_player.setTextureRect(rect);
				
					dx = 0;
					/*				rot = 0;
					_player.setRotation(rot);
					*/

				//	rect.left = a;
				//	rect.top = b;

					//rect.height = 100;
					//rect.width = 106;

					//_player.setTextureRect(rect);

				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && isonjump != true)
				{
					std::cout << "  $$$$$$$$$$$$$  ";
					isonjump = true;
					isclimbing = true;
					isfalling = false;
					tm = clj.getElapsedTime().asSeconds();

				}
				





			/*if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
			{
				*
				pipe->SpawnInvisiblePipe();
				pipe->SpawnBottomPipe();

				pipe->SpawnTopPipe();
				*
			}*/

		//}
	}

	void GameState::Update(float dt)
	{
		std::cout << 9;

		if (isonjump == true)
		{
			rect.top = 230;
			rect.left = rect.left + 102;

			if (rect.left >= 920)
			{
				//rect.top = 270;
				rect.left = 104;
			}
		//	tm = clj.getElapsedTime().asSeconds();
			if (_player.getPosition().y>500&&isclimbing==true)                                              /*clj.getElapsedTime().asSeconds() -tm < 2.0f */
			{
				isclimbing = true;
				isfalling = false;
				dy = -5;
				count++;

			}
			else if (/*clj.getElapsedTime().asSeconds() -tm < 4.0f&&*/count>0)
			{
				isclimbing = false;
				isfalling = true;
				dy = +5;
				count--;
			}
			else
				{
					isonjump = false;
					dy = 0;
					count = 0;
					rect.top = 0;
					rect.left = 0;
					_player.setTextureRect(rect);
				}
			

			/*if (isonjump = false)
			{
				rect.top = 0;
				rect.left = 0;
			//	_player.setTextureRect(rect);

			}*/
				


		}
		//pipe->MovePipes(dt);
		land->MoveLand(dt,dx);

		_player.move(0, dy);
		std::cout << count<<" ";


		//_player.setTextureRect(rect);

		this->_data->window.draw(this->_player);



		//_player.setTextureRect(rect);

		/*if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
		{
			pipe->RandomisePipeOffset();
			pipe->SpawnInvisiblePipe();
			pipe->SpawnBottomPipe();

			pipe->SpawnTopPipe();
			clock.restart();

		}*/



	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

//      view.reset(sf::FloatRect(0, 0, 768,1024));

		
		this->_data->window.clear(sf::Color::Blue);

		this->_data->window.draw(this->_background);

		this->_data->window.draw(this->_player);
		 
	//	pipe->DrawPipes();
		land->DrawLand();
		this->_data->window.draw(this->_player);
		this->_data->window.display();
	}
}
