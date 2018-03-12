// AwesomeSq function definitions here

#include "AwesomeSq.h"

AwesomeSq::AwesomeSq()
{
	m_playerLocation = { 550,0 };
	m_speed = { 2.5,2.5 };

	m_player.setFillColor(sf::Color::Blue);
	m_player.setSize(sf::Vector2f{ PLAYER_SIZE,PLAYER_SIZE });
	m_player.setPosition(m_playerLocation);

}

void AwesomeSq::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		moveLeft();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		moveRight();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		moveUp();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		moveDown();
	}

	checkBoarder();
}


void AwesomeSq::moveLeft()
{
	m_playerLocation.x -= m_speed.x;
	m_player.setPosition(m_playerLocation);
	//m_player.setTexture(m_playerLeft);
}

void AwesomeSq::moveRight()
{
	m_playerLocation.x += m_speed.x;
	m_player.setPosition(m_playerLocation);
	//m_player.setTexture(m_playerRight);
}

void AwesomeSq::moveUp()
{
	m_playerLocation.y -= m_speed.y;
	m_player.setPosition(m_playerLocation);
	//m_player.setTexture(m_playerUp);
}

void AwesomeSq::moveDown()
{
	m_playerLocation.y += m_speed.y;
	m_player.setPosition(m_playerLocation);
	//m_player.setTexture(m_playerDown);
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
