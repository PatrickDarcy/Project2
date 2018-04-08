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

	enum direction {NORTH,EAST,SOUTH,WEST};
	direction m_playersDirection;

	bool m_containsBlockLeft;
	bool m_containsBlockRight;
	bool m_containsBlockUp;
	bool m_containsBlockDown;
	bool m_didPlayerKick;

public:

	AwesomeSq();
	void update();
	void wallCheck(bool t_containsBlockLeft, bool t_containsBlockRight, bool t_containsBlockUp, bool t_containsBlockDown);
	int playersDirection();
	bool playerKicked();
	void moveLeft();
	int leftOfPlayer();
	int rightOfPlayer();
	int abovePlayer();
	int bellowPlayer();
	int playersRow();
	int playersCol();
	sf::Vector2f getPosition();
	void moveRight();
	void moveUp();
	void moveDown();
	void checkBoarder();
	void draw(sf::RenderWindow &t_window);

};