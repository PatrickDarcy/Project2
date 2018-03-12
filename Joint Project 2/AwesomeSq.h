#pragma once
#include "SFML\Graphics.hpp"
#include "Global.h"

class AwesomeSq
{
	// private data members
	sf::RectangleShape m_player;
	sf::Texture m_playerUp;
	sf::Texture m_playerDown;
	sf::Texture m_playerLeft;
	sf::Texture m_playerRight;

	sf::Vector2f m_playerLocation;
	sf::Vector2f m_speed;

public:

	AwesomeSq();
	void update();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void checkBoarder();
	void draw(sf::RenderWindow &t_window);

};