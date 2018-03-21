#pragma once
#include <SFML\Graphics.hpp>
#include "Global.h"

class EvilSq
{
	// private data members
	sf::RectangleShape m_enemy;
	sf::Texture m_enemyDown;
	sf::Texture m_enemyUp;
	sf::Texture m_enemyRight;
	sf::Texture m_ememyLeft;

public:
	EvilSq();
	void update();
	void setPosition(sf::Vector2f t_enemyPos);
	void draw(sf::RenderWindow & t_window);

};
