// Name: Patrick Darcy
// Login: C00226157
// Date: 07/03/2018
// Approximate time taken: 
//---------------------------------------------------------------------------
// Project Description: This is a maze based game using 2D arrays
// ---------------------------------------------------------------------------
// Known Bugs:
// 

//////////////////////////////////////////////////////////// 
// Headers for SFML projects
// include correct library file for release and debug versions
// include iostream for console window output
// include 
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "Game.h"   // include Game header file


int main()
{
	Game aGame;
	aGame.LoadContent();
	aGame.run();

	return 0;
}

Game::Game() : m_window(sf::VideoMode(600, 600), "Project 2")
// Default constructor
{
	m_wall = 2;
	m_crate = 1;

	sf::Vector2f enemyPos = { 50,500 };

	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		m_enemies[i].setPosition(enemyPos);

		enemyPos.x += 200;
	}
	
	m_newFrame = 0;
	m_itsACrate = false;
}


void Game::LoadContent()
// load the font file & set up message
{
	if (!m_woodFloor.loadFromFile("ASSETS/IMAGES/floor.png"))
	{
		std::cout << "error with image file" << std::endl;
	}

	m_background.setTexture(m_woodFloor, true);
	m_background.setPosition(0, 0);

	setUpMaze();
	tileType();
	
}


void Game::run()
{
	srand(time(nullptr)); // set the seed once
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time spriteAnimationSpeed = sf::seconds(0.0f);

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (m_window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();
		spriteAnimationSpeed += sf::seconds(1.0f);

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			for (int i = 0; i < MAX_ENEMIES; i++)
			{
				m_enemies[i].drawEnemy(timeSinceLastUpdate);
			}

			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			spriteAnimationSpeed = sf::Time::Zero;
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}



void Game::update()
// This function takes the keyboard input and updates the game world
{
	m_Player.update();
	m_Player.wallCheck(m_maze[m_Player.playersRow()][m_Player.leftOfPlayer()].containsBlock(), m_maze[m_Player.playersRow()][m_Player.rightOfPlayer()].containsBlock(),
		m_maze[m_Player.abovePlayer()][m_Player.playersCol()].containsBlock(), m_maze[m_Player.bellowPlayer()][m_Player.playersCol()].containsBlock());
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		m_enemies[i].update(m_maze[m_enemies[i].enemyRow()][m_enemies[i].leftOfEnemy()].containsBlock(), m_maze[m_enemies[i].enemyRow()][m_enemies[i].rightOfEnemy()].containsBlock(),
			m_maze[m_enemies[i].aboveEnemy()][m_enemies[i].enemyCol()].containsBlock(), m_maze[m_enemies[i].bellowEnemy()][m_enemies[i].enemyCol()].containsBlock());
	}

	m_newFrame++;
	if (m_newFrame >= 15)
	{
		m_Player.drawPlayer();
		m_newFrame = 0;
	}

	crateKicked(m_Player.playerKicked(), m_Player.playersDirection(), m_Player.getPosition());
	if (m_itsACrate == true)
	{
		movingKickedCrate();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		Game();
		LoadContent();
	}

}

void Game::movingKickedCrate()
{
	sf::Vector2f movingCrate;
	sf::Vector2f crateSpeed = { 2.5,2.5 };

	movingCrate = m_maze[facingCrate().x][facingCrate().y].getPosition();

	if (m_Player.playerKicked() == true)
	{
		if (m_Player.playersDirection() == EAST)
		{
			movingCrate.x += crateSpeed.x;
			m_maze[facingCrate().x][facingCrate().y].setPosition(movingCrate.x, movingCrate.y);
		}
		if (m_Player.playersDirection() == WEST)
		{
			movingCrate.x -= crateSpeed.x;
			m_maze[facingCrate().x][facingCrate().y].setPosition(movingCrate.x, movingCrate.y);
		}
		if (m_Player.playersDirection() == NORTH)
		{
			movingCrate.y -= crateSpeed.y;
			m_maze[facingCrate().x][facingCrate().y].setPosition(movingCrate.x, movingCrate.y);
		}
		if (m_Player.playersDirection() == SOUTH)
		{
			movingCrate.y += crateSpeed.y;
			m_maze[facingCrate().x][facingCrate().y].setPosition(movingCrate.x, movingCrate.y);
		}
	}
}

void Game::crateKicked(bool t_crateKicked, int t_playerDirection, sf::Vector2f t_playerPos)
{
	if (t_crateKicked == true)
	{
		if (t_playerDirection == EAST)
		{
			m_blockFacingPlayer.y = (t_playerPos.x / 50) + 1;
			m_blockFacingPlayer.x = (t_playerPos.y / 50);
			if (m_maze[m_blockFacingPlayer.x][m_blockFacingPlayer.y].isItACrate() == true)
			{
				m_itsACrate = true;
			}
			else
			{
				m_itsACrate = false;
			}
		}
		else if (t_playerDirection == WEST)
		{
			m_blockFacingPlayer.y = (t_playerPos.x / 50) - 1;
			m_blockFacingPlayer.x = (t_playerPos.y / 50);
			if (m_maze[m_blockFacingPlayer.x][m_blockFacingPlayer.y].isItACrate() == true)
			{
				m_itsACrate = true;
			}
			else
			{
				m_itsACrate = false;
			}
		}
		else if (t_playerDirection == NORTH)
		{
			m_blockFacingPlayer.y = (t_playerPos.x / 50);
			m_blockFacingPlayer.x = (t_playerPos.y / 50) - 1;
			if (m_maze[m_blockFacingPlayer.x][m_blockFacingPlayer.y].isItACrate() == true)
			{
				m_itsACrate = true;
			}
			else
			{
				m_itsACrate = false;
			}
		}
		else if (t_playerDirection == SOUTH)
		{
			m_blockFacingPlayer.y = (t_playerPos.x / 50);
			m_blockFacingPlayer.x = (t_playerPos.y / 50) + 1;
			if (m_maze[m_blockFacingPlayer.x][m_blockFacingPlayer.y].isItACrate() == true)
			{
				m_itsACrate = true;
			}
			else
			{
				m_itsACrate = false;
			}
		}
	}
	
}

sf::Vector2i Game::facingCrate()
{
	return m_blockFacingPlayer;
}



void Game::setUpMaze()
{
	int m_x = 0;
	int m_y = 0;

	for (int row = 0; row < MAX_ROW; row++)
	{

		for (int col = 0; col < MAX_COL; col++)
		{

			m_maze[row][col].setPosition(m_x, m_y);
			m_x += 50;
		}
		m_x = 0;
		m_y += 50;

	}
}

void Game::tileType()
{
	int row = 0;
	int col = 0;
	for (int i = 0; i < MAX_COL; i++)
	{
		m_maze[row][i].assignTile(m_wall);
		m_maze[i][col].assignTile(m_wall);
	}

	int row1 = 1;
	
	m_maze[row1][6].assignTile(m_wall);

	int row2 = 2;

	m_maze[row2][1].assignTile(m_wall);
	m_maze[row2][2].assignTile(m_wall);
	m_maze[row2][4].assignTile(m_wall);
	m_maze[row2][5].assignTile(m_wall);
	m_maze[row2][6].assignTile(m_wall);

	int row3 = 3;

	m_maze[row3][6].assignTile(m_wall);
	m_maze[row3][8].assignTile(m_wall);
	m_maze[row3][9].assignTile(m_crate);
	m_maze[row3][10].assignTile(m_wall);
	

	int row4 = 4;

	m_maze[row4][2].assignTile(m_wall);
	m_maze[row4][3].assignTile(m_crate);
	m_maze[row4][4].assignTile(m_wall);
	m_maze[row4][8].assignTile(m_wall);

	int row5 = 5;

	m_maze[row5][6].assignTile(m_wall);
	m_maze[row5][8].assignTile(m_wall);


	int row6 = 6;

	m_maze[row6][6].assignTile(m_crate);
	

	int row7 = 7;

	m_maze[row7][6].assignTile(m_wall);
	m_maze[row7][8].assignTile(m_wall);

	int row8 = 8;

	m_maze[row8][2].assignTile(m_wall);
	m_maze[row8][3].assignTile(m_crate);
	m_maze[row8][4].assignTile(m_wall);
	m_maze[row8][8].assignTile(m_wall);


	int row9 = 9;

	m_maze[row9][6].assignTile(m_wall);
	m_maze[row9][7].assignTile(m_wall);
	m_maze[row9][8].assignTile(m_wall);
	m_maze[row9][9].assignTile(m_crate);

	int row11 = 11;
	col = 11;

	for (int i = 0; i < MAX_COL; i++)
	{
		m_maze[row11][i].assignTile(m_wall);
		m_maze[i][col].assignTile(m_wall);
	}


}

void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	m_window.clear();

	m_window.draw(m_background);

	for (int row = 0; row < MAX_ROW; row++)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			m_maze[row][col].draw(m_window);
		}
	}
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		m_enemies[i].draw(m_window);
	}

	m_Player.draw(m_window);
	m_window.display();
}