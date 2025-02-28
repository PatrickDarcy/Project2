// EvilSq function definitions here

#include "EvilSq.h"

EvilSq::EvilSq()
{
	m_enemySpeed = { 2.5,2.5 };
	m_enemy.setPosition(m_enemyPos);

	m_enemyTemplate.loadFromFile("ASSETS/IMAGES/087-Monster01.png");
	m_rectSourceSprite = { 0,0,50,50 };
	m_enemy.setTexture(m_enemyTemplate);

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
			int random = rand() % 3;
			random = random / 3.0;
			while (random == 1)
			{
				random = rand() % 3;
			}
			m_direction = random;
		}
		else
		{
			m_enemyPos.x += m_enemySpeed.x;
			m_enemy.setPosition(m_enemyPos);
			m_rectSourceSprite.top = 100;
		}
	}
	else if (m_direction == WEST)
	{
		if (t_containsBlockLeft == true)
		{
			int random = rand() % 3;
			random = random / 3.0;
			while (random == 3)
			{
				random = rand() % 3;
			}
			m_direction = random;
		}
		else
		{
			m_enemyPos.x -= m_enemySpeed.x;
			m_enemy.setPosition(m_enemyPos);
			m_rectSourceSprite.top = 50;
		}
	}
	else if (m_direction == NORTH)
	{
		if (t_containsBlockUp == true)
		{
			int random = rand() % 3;
			random = random / 3.0;
			while (random == 0)
			{
				random = rand() % 3;
			}
			m_direction = random;
		}
		else
		{
			m_enemyPos.y -= m_enemySpeed.y;
			m_enemy.setPosition(m_enemyPos);
			m_rectSourceSprite.top = 150;
		}
	}
	else if (m_direction == SOUTH)
	{
		if (t_containsBlockDown == true)
		{
			int random = rand() % 11;
			random = random / 3.0;
			while (random == 2)
			{
				random = rand() % 3;
			}
			m_direction = random;
		}
		else
		{
			m_enemyPos.y += m_enemySpeed.y;
			m_enemy.setPosition(m_enemyPos);
			m_rectSourceSprite.top = 0;
		}
	}
}
void EvilSq::drawEnemy(sf::Time t_60FramesASec)
{
	if (t_60FramesASec.asSeconds() > 1.0f/60.0f)
	{
		if (m_rectSourceSprite.left == 100)
		{
			m_rectSourceSprite.left = 0;
		}
		else
		{
			m_rectSourceSprite.left += 50;
		}

		m_enemy.setTextureRect(m_rectSourceSprite);
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
