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

	bool m_containsBlockLeft;
	bool m_containsBlockRight;
	bool m_containsBlockUp;
	bool m_containsBlockDown;

public:

	AwesomeSq();
	void update();
	void wallCheck(bool t_containsBlockLeft, bool t_containsBlockRight, bool t_containsBlockUp, bool t_containsBlockDown);
	void moveLeft();
	int playersLeft();
	int playersRight();
	int playersTop();
	int playersBottom();
	int playersRow();
	int playersCol();
	void moveRight();
	void moveUp();
	void moveDown();
	void checkBoarder();
	void draw(sf::RenderWindow &t_window);

};