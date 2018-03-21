// AwesomeSq function definitions here

#include "AwesomeSq.h"

AwesomeSq::AwesomeSq()
{
	m_playerLocation = { 50,50 };
	m_speed = { 2.5,2.5 };

	m_player.setFillColor(sf::Color::Blue);
	m_player.setSize(sf::Vector2f{ SQUARE_SIZE,SQUARE_SIZE });
	m_player.setPosition(m_playerLocation);

	m_containsBlockLeft = false;
	m_containsBlockRight = false;
	m_containsBlockUp = false;
	m_containsBlockDown = false;

}

void AwesomeSq::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		moveLeft();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		moveRight();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		moveUp();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		moveDown();
	}

	checkBoarder();
}

void AwesomeSq::wallCheck(bool t_containsBlockLeft, bool t_containsBlockRight, bool t_containsBlockUp, bool t_containsBlockDown)
{
	m_containsBlockLeft = t_containsBlockLeft;
	m_containsBlockRight = t_containsBlockRight;
	m_containsBlockUp = t_containsBlockUp;
	m_containsBlockDown = t_containsBlockDown;
}

int AwesomeSq::leftOfPlayer()
{
	int playerLeft = ((m_player.getPosition().x) / 50);
	return playerLeft;
}

int AwesomeSq::rightOfPlayer()
{
	int playerRight = ((m_player.getPosition().x) / 50) + 1;
	return playerRight;
}

int AwesomeSq::abovePlayer()
{
	int playerUp = ((m_player.getPosition().y) / 50);
	return playerUp;
}

int AwesomeSq::bellowPlayer()
{
	int playerDown = ((m_player.getPosition().y) / 50) + 1;
	return playerDown;
}

int AwesomeSq::playersRow()
{
	int playerRow = ((m_player.getPosition().y) / 50);
	return playerRow;
}

int AwesomeSq::playersCol()
{
	int playerCol = ((m_player.getPosition().x) / 50);
	return playerCol;
}

void AwesomeSq::moveLeft()
{
	if (m_containsBlockLeft == false)
	{
		m_playerLocation.x -= m_speed.x;
		m_player.setPosition(m_playerLocation);
		m_playersDirection = WEST;
		//m_player.setTexture(m_playerLeft);
	}
}

void AwesomeSq::moveRight()
{
	if (m_containsBlockRight == false)
	{
		m_playerLocation.x += m_speed.x;
		m_player.setPosition(m_playerLocation);
		m_playersDirection = EAST;
		//m_player.setTexture(m_playerRight);
	}
}

void AwesomeSq::moveUp()
{
	if (m_containsBlockUp == false)
	{
		m_playerLocation.y -= m_speed.y;
		m_player.setPosition(m_playerLocation);
		m_playersDirection = NORTH;
		//m_player.setTexture(m_playerUp);
	}
}

void AwesomeSq::moveDown()
{
	if (m_containsBlockDown == false)
	{
		m_playerLocation.y += m_speed.y;
		m_player.setPosition(m_playerLocation);
		m_playersDirection = SOUTH;
		//m_player.setTexture(m_playerDown);
	}
}

void AwesomeSq::checkBoarder()
{
	if (m_playerLocation.x >= SCREEN_WIDTH - SQUARE_SIZE)
	{
		m_playerLocation.x = SCREEN_WIDTH - SQUARE_SIZE;
	}
	if (m_playerLocation.x <= 0)
	{
		m_playerLocation.x = 0;
	}
	if (m_playerLocation.y >= SCREEN_HEIGHT - SQUARE_SIZE)
	{
		m_playerLocation.y = SCREEN_HEIGHT - SQUARE_SIZE;
	}
	if (m_playerLocation.y <= 0)
	{
		m_playerLocation.y = 0 ;
	}

}

void AwesomeSq::draw(sf::RenderWindow &t_window)
{
	t_window.draw(m_player);
}
