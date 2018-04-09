#pragma once
#include <SFML\Graphics.hpp>
#include "Global.h"

class EvilSq
{
	// private data members
	sf::Sprite m_enemy;
	sf::Texture m_enemyTemplate;
	sf::IntRect m_rectSourceSprite;

	sf::Vector2f m_enemyPos;
	sf::Vector2f m_enemySpeed;

	int m_direction;


public:
	EvilSq();
	void update(bool t_containsBlockLeft, bool t_containsBlockRight, bool t_containsBlockUp, bool t_containsBlockDown);
	void setPosition(sf::Vector2f t_enemyPos);
	void movement(bool t_containsBlockLeft, bool t_containsBlockRight, bool t_containsBlockUp, bool t_containsBlockDown);
	void drawEnemy(sf::Time t_60FramesASec);
	int leftOfEnemy();
	int rightOfEnemy();
	int aboveEnemy();
	int bellowEnemy();
	int enemyRow();
	int enemyCol();
	void draw(sf::RenderWindow & t_window);

};
