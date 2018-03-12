// AwesomeSq function definitions here

#include "AwesomeSq.h"

AwesomeSq::AwesomeSq()
{
	m_playerLocation = { 550,0 };
	m_speed = { 2.5,2.5 };

	m_player.setFillColor(sf::Color::Blue);
	m_player.setSize(sf::Vector2f{ PLAYER_SIZE,PLAYER_SIZE });
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
	if (t_containsBlockLeft == true)
	{
		m_containsBlockLeft = t_containsBlockLeft;
	}
	if (t_containsBlockRight == true)
	{
		m_containsBlockRight = t_containsBlockRight;
	}
	if (t_containsBlockUp == true)
	{
		m_containsBlockUp = t_containsBlockUp;
	}
	if (t_containsBlockDown == true)
	{
		m_containsBlockDown = t_containsBlockDown;
	}
}


void AwesomeSq::moveLeft()
{
	if (m_containsBlockLeft = false)
	{
		m_playerLocation.x -= m_speed.x;
		m_player.setPosition(m_playerLocation);
		//m_player.setTexture(m_playerLeft);
	}
}

int AwesomeSq::playersLeft()
{
	return ((m_player.getPosition().x) / 50) - 1;
}

int AwesomeSq::playersRight()
{
	return ((m_player.getPosition().x) / 50) + 1;
}

int AwesomeSq::playersTop()
{
	return ((m_player.getPosition().y) / 50) - 1;
}

int AwesomeSq::playersBottom()
{
	return ((m_player.getPosition().y) / 50) + 1;
}

int AwesomeSq::playersRow()
{
	return (m_player.getPosition().y) / 50;
}

int AwesomeSq::playersCol()
{
	return (m_player.getPosition().x) / 50;
}

void AwesomeSq::moveRight()
{
	if (m_containsBlockRight = false)
	{
		m_playerLocation.x += m_speed.x;
		m_player.setPosition(m_playerLocation);
		//m_player.setTexture(m_playerRight);
	}
}

void AwesomeSq::moveUp()
{
	if (m_containsBlockUp = false)
	{
		m_playerLocation.y -= m_speed.y;
		m_player.setPosition(m_playerLocation);
		//m_player.setTexture(m_playerUp);
	}
}

void AwesomeSq::moveDown()
{
	if (m_containsBlockDown = false)
	{
		m_playerLocation.y += m_speed.y;
		m_player.setPosition(m_playerLocation);
		//m_player.setTexture(m_playerDown);
	}
}

void AwesomeSq::checkBoarder()
{
	if (m_playerLocation.x >= SCREEN_WIDTH - PLAYER_SIZE)
	{
		m_playerLocation.x = SCREEN_WIDTH - PLAYER_SIZE;
	}
	if (m_playerLocation.x <= 0)
	{
		m_playerLocation.x = 0;
	}
	if (m_playerLocation.y >= SCREEN_HEIGHT - PLAYER_SIZE)
	{
		m_playerLocation.y = SCREEN_HEIGHT - PLAYER_SIZE;
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
