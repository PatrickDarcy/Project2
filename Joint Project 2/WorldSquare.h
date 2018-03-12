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

	bool m_solidBlock;

public:
	WorldSquare();
	void update(int t_squareType);
	void assignTile(int t_squareType);
	void setPosition(int t_x, int t_y);
	bool containsBlock();
	sf::Vector2f getPosition();
	void draw(sf::RenderWindow &t_window);
};