#include "WorldSquare.h"

WorldSquare::WorldSquare()
{
}

void WorldSquare::draw(sf::RenderWindow &t_window)
{
	if (m_square == crate)
	{
		m_worldSquare.setTexture(m_crate);
	}
	if (m_square == wall)
	{
		m_worldSquare.setTexture(m_wall);
	}

	t_window.draw(m_worldSquare);
}
