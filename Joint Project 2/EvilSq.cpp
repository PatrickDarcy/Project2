// EvilSq function definitions here

#include "EvilSq.h"

EvilSq::EvilSq()
{
	m_enemy.setSize({SQUARE_SIZE,SQUARE_SIZE });
	m_enemy.setFillColor(sf::Color::Red);
}

void EvilSq::update()
{
}

void EvilSq::setPosition(sf::Vector2f t_enemyPos)
{
	m_enemy.setPosition(t_enemyPos);
}

void EvilSq::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_enemy);
}
