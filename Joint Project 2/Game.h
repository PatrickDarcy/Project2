// Game class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "AwesomeSq.h"   // include AwesomeSq header file
#include "EvilSq.h"   // include EvilSq header file
#include "WorldSquare.h" // include WorldSquare header file
#include "Global.h"

class Game
{
	// private data members
	// put your game objects here eg AwesomeSq object and 1D array of EvilSq objects etc.

	sf::RenderWindow m_window;

public:
	sf::Sprite m_background; // the game background
	sf::Texture m_woodFloor; // the game backgrounds texture

	WorldSquare m_maze[MAX_ROW][MAX_COL]; // the world grid

	sf::Vector2i m_blockFacingPlayer;
	bool m_itsACrate;

	int m_wall;
	int m_crate;
	int m_newFrame;

	EvilSq m_enemies[2];
	AwesomeSq m_Player;

public:	  // declaration of member functions	
	Game();  // default constructor
	void	LoadContent();
	void	run();
	void	update();
	void	movingKickedCrate();
	void	crateKicked(bool t_crateKicked, int t_playerDirection, sf::Vector2f t_playerPos);
	sf::Vector2i facingCrate();
	void	draw();
	void	setUpMaze();
	void	tileType();
};

