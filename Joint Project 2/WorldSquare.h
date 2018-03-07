#pragma once
#include<SFML\Graphics.hpp>

class WorldSquare
{
	// private data members
	sf::Sprite m_worldSquare;
	sf::Texture m_crate;
	sf::Texture m_wall;

	enum squareType {empty, crate, wall};
	squareType m_square;


public:
	WorldSquare();
	void draw(sf::RenderWindow &t_window);
};