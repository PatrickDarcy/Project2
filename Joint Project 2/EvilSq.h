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
	sf::Vector2f m_enemyPos;
	sf::Vector2f m_enemySpeed;

	int m_direction;


public:
	EvilSq();
	void update(bool t_containsBlockLeft, bool t_containsBlockRight, bool t_containsBlockUp, bool t_containsBlockDown);
	void setPosition(sf::Vector2f t_enemyPos);
	void movement(bool t_containsBlockLeft, bool t_containsBlockRight, bool t_containsBlockUp, bool t_containsBlockDown);
	int leftOfEnemy();
	int rightOfEnemy();
	int aboveEnemy();
	int bellowEnemy();
	int enemyRow();
	int enemyCol();
	void draw(sf::RenderWindow & t_window);

};
