// AwesomeSq function definitions here

#include "AwesomeSq.h"

AwesomeSq::AwesomeSq()
{
	m_playerLocation = { 50,50 };
	m_speed = { 2.5,2.5 };

	m_playerTemplate.loadFromFile("ASSETS/IMAGES/penguin.png");
	m_sourceSpriteRect = { 0,0,50,50 };
	m_player.setTexture(m_playerTemplate);
	
	m_player.setPosition(m_playerLocation);

	m_containsBlockLeft = false;
	m_containsBlockRight = false;
	m_containsBlockUp = false;
	m_containsBlockDown = false;

	m_didPlayerKick = false;

	m_playersDirection == SOUTH;
}

void AwesomeSq::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		moveLeft();
		m_didPlayerKick = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		moveRight();
		m_didPlayerKick = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		moveUp();
		m_didPlayerKick = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		moveDown();
		m_didPlayerKick = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		playersDirection();
		m_didPlayerKick = true;
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

int AwesomeSq::playersDirection()
{
	return m_playersDirection;
}

bool AwesomeSq::playerKicked()
{
	return m_didPlayerKick;
}

void AwesomeSq::drawPlayer(sf::Time t_60FramesASec)
{
	if (t_60FramesASec.asSeconds() > 1.0f/60.0f )
	{
		if (m_sourceSpriteRect.left == 100)
		{
			m_sourceSpriteRect.left = 0;
		}
		else
		{
			m_sourceSpriteRect.left += 50;
		}

		m_player.setTextureRect(m_sourceSpriteRect);
	}
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

sf::Vector2f AwesomeSq::getPosition()
{
	return m_player.getPosition();
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
