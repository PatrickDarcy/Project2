// EvilSq function definitions here

#include "EvilSq.h"

EvilSq::EvilSq()
{
	m_enemySpeed = { 2.5,2.5 };
	m_enemy.setSize({SQUARE_SIZE,SQUARE_SIZE });
	m_enemy.setFillColor(sf::Color::Red);
	m_enemy.setPosition(m_enemyPos);

	m_direction = rand() % 3;
}

void EvilSq::update(bool t_containsBlockLeft, bool t_containsBlockRight, bool t_containsBlockUp, bool t_containsBlockDown)
{
	movement(t_containsBlockLeft, t_containsBlockRight, t_containsBlockUp, t_containsBlockDown);
}

void EvilSq::setPosition(sf::Vector2f t_enemyPos)
{
	m_enemyPos = t_enemyPos;
	m_enemy.setPosition(m_enemyPos);
}

void EvilSq::movement(bool t_containsBlockLeft, bool t_containsBlockRight, bool t_containsBlockUp, bool t_containsBlockDown)
{
	if (m_direction == EAST)
	{
		if (t_containsBlockRight == true)
		{
			m_direction = 1;
		}
		else
		{
			m_enemyPos.x += m_enemySpeed.x;
			m_enemy.setPosition(m_enemyPos);
		}
	}
	else if (m_direction == WEST)
	{
		if (t_containsBlockLeft == true)
		{
			m_direction = 2;
		}
		else
		{
			m_enemyPos.x -= m_enemySpeed.x;
			m_enemy.setPosition(m_enemyPos);
		}
	}
	else if (m_direction == NORTH)
	{
		if (t_containsBlockUp == true)
		{
			m_direction = 3;
		}
		else
		{
			m_enemyPos.y -= m_enemySpeed.y;
			m_enemy.setPosition(m_enemyPos);
		}
	}
	else if (m_direction == SOUTH)
	{
		if (t_containsBlockDown == true)
		{
			m_direction = 0;
		}
		else
		{
			m_enemyPos.y += m_enemySpeed.y;
			m_enemy.setPosition(m_enemyPos);
		}
	}
}
int EvilSq::leftOfEnemy()
{
	int enemyLeft = ((m_enemy.getPosition().x) / 50);
	return enemyLeft;
}

int  EvilSq::rightOfEnemy()
{
	int enemyRight = ((m_enemy.getPosition().x) / 50) + 1;
	return enemyRight;
}

int  EvilSq::aboveEnemy()
{
	int enemyUp = ((m_enemy.getPosition().y) / 50);
	return enemyUp;
}

int  EvilSq::bellowEnemy()
{
	int enemyDown = ((m_enemy.getPosition().y) / 50) + 1;
	return enemyDown;
}

int  EvilSq::enemyRow()
{
	int enemyRow = ((m_enemy.getPosition().y) / 50);
	return enemyRow;
}

int  EvilSq::enemyCol()
{
	int enemyCol = ((m_enemy.getPosition().x) / 50);
	return enemyCol;
}

void EvilSq::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_enemy);
}
