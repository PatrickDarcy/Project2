#include "WorldSquare.h"
#include <iostream>

WorldSquare::WorldSquare()
{
	if (!m_wall.loadFromFile("ASSETS/IMAGES/stoneWall.png"))
	{
		std::cout << "error with image file" << std::endl;
	}
	if (!m_crate.loadFromFile("ASSETS/IMAGES/woodCrate.png"))
	{
		std::cout << "error with image file" << std::endl;
	}

	m_solidBlock = false;	
}

void WorldSquare::update(int t_squareType)
{
}

void WorldSquare::assignTile(int t_squareType)
{
	if (t_squareType == 1)
	{
		m_square = crate;
		m_solidBlock = true;
	}
	if (t_squareType == 2)
	{
		m_square = wall;
		m_solidBlock = true;
	}
	if (t_squareType == 0)
	{
		m_square = empty;
		m_solidBlock = false;
	}
}

void WorldSquare::setPosition(int t_x, int t_y)
{
	m_worldSquare.setPosition(t_x, t_y);
}

bool WorldSquare::containsBlock()
{
	return m_solidBlock;
}

sf::Vector2f WorldSquare::getPosition()
{
	return m_worldSquare.getPosition();
}

void WorldSquare::draw(sf::RenderWindow &t_window)
{
	if (m_square == crate)
	{
		m_worldSquare.setTexture(m_crate);
	}

	else if (m_square == wall)
	{
		m_worldSquare.setTexture(m_wall);
	}

	t_window.draw(m_worldSquare);
}
