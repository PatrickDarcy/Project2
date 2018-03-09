#include "WorldSquare.h"

WorldSquare::WorldSquare()
{
	m_square = empty;
}

void WorldSquare::update(int t_squareType)
{
}

void WorldSquare::assignTile(int t_squareType)
{
	if (t_squareType == crate)
	{
		m_square = crate;
	}
	else if (t_squareType == wall)
	{
		m_square = wall;
	}
	else
	{
		m_square = empty;
	}
}

void WorldSquare::setPosition(int t_x, int t_y)
{
	m_worldSquare.setPosition(t_x, t_y);
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
