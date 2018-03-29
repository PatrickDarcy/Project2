#pragma once
#include<SFML\Graphics.hpp>
#include "Global.h"

class WorldSquare
{
	// private data members
	sf::Sprite m_worldSquare;
	sf::Texture m_crate;
	sf::Texture m_wall;

	enum squareType {empty, crate, wall};
	squareType m_square;

	sf::Vector2i m_blockFacingPlayer;

	bool m_solidBlock;

public:
	WorldSquare();
	void update(bool t_crateKicked, int t_playerDirection, sf::Vector2f t_playerPos);
	void assignTile(int t_squareType);
	void setPosition(int t_x, int t_y);
	void crateKicked(bool t_crateKicked, int t_playerDirection, sf::Vector2f t_playerPos);
	bool containsBlock();
	sf::Vector2i facingCrate();
	sf::Vector2f getPosition();
	void draw(sf::RenderWindow &t_window);
};