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

	tileType();
	setUpMaze();
}


void Game::run()
{
	srand(time(nullptr)); // set the seed once
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

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

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{

			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}



void Game::update()
// This function takes the keyboard input and updates the game world
{
	
	m_Player.update();
}



void Game::setUpMaze()
{
	int m_x = 0;
	int m_y = 0;

	for (int row = 0; row < MAX_ROW; row++)
	{
		
		for (int col = 0; col < MAX_COL; col++)
		{
		
			m_maze[row][col].setPosition(m_x,m_y);
			m_x += 50;
		}
		m_y += 50;
		
	}


}

void Game::tileType()
{
	int col = 0;

	m_maze[6][col].assignTile(m_wall);

	int col1 = 1;

	//m_maze[0][col1].assignTile(m_wall);
	m_maze[1][col1].assignTile(m_wall);
	m_maze[2][col1].assignTile(m_wall);
	m_maze[4][col1].assignTile(m_wall);
	m_maze[5][col1].assignTile(m_wall);
	m_maze[6][col1].assignTile(m_wall);
	m_maze[7][col1].assignTile(m_wall);
	m_maze[9][col1].assignTile(m_wall);
	m_maze[10][col1].assignTile(m_crate);
	m_maze[11][col1].assignTile(m_wall);

	int col2 = 2;

	m_maze[6][col2].assignTile(m_crate);
	m_maze[11][col2].assignTile(m_wall);

	int col3 = 3;

	m_maze[col3][2].assignTile(m_wall);
	m_maze[col3][3].assignTile(m_crate);
	m_maze[col3][4].assignTile(m_wall);
	m_maze[col3][6].assignTile(m_wall);
	m_maze[col3][7].assignTile(m_wall);
	m_maze[col3][8].assignTile(m_wall);
	m_maze[col3][9].assignTile(m_wall);
	m_maze[col3][11].assignTile(m_wall);

	int col4 = 4;

	m_maze[col4][9].assignTile(m_wall);
	m_maze[col4][11].assignTile(m_wall);

	int col5 = 5;

	m_maze[col5][3].assignTile(m_crate);
	m_maze[col5][6].assignTile(m_crate);
	m_maze[col5][11].assignTile(m_wall);

	int col6 = 6;

	m_maze[col6][9].assignTile(m_wall);
	m_maze[col6][11].assignTile(m_wall);

	int col7 = 7;

	m_maze[col7][6].assignTile(m_wall);
	m_maze[col7][7].assignTile(m_wall);
	m_maze[col7][8].assignTile(m_wall);
	m_maze[col7][9].assignTile(m_wall);
	m_maze[col7][11].assignTile(m_wall);

	int col8 = 8;

	m_maze[col8][2].assignTile(m_wall);
	m_maze[col8][3].assignTile(m_crate);
	m_maze[col8][4].assignTile(m_wall);
	m_maze[col8][6].assignTile(m_wall);
	m_maze[col8][11].assignTile(m_wall);

	int col9 = 9;

	m_maze[col9][7].assignTile(m_crate);
	m_maze[col9][9].assignTile(m_wall);
	m_maze[col9][10].assignTile(m_crate);
	m_maze[col9][11].assignTile(m_wall);

	int col10 = 10;

	m_maze[col10][0].assignTile(m_wall);
	m_maze[col10][1].assignTile(m_wall);
	m_maze[col10][2].assignTile(m_wall);
	m_maze[col10][4].assignTile(m_wall);
	m_maze[col10][5].assignTile(m_wall);
	m_maze[col10][6].assignTile(m_wall);

	int col11 = 11;

	m_maze[col11][6].assignTile(m_wall);
	m_maze[0][0].assignTile(m_wall);
	m_maze[0][1].assignTile(m_wall);
	m_maze[0][3].assignTile(m_wall);

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

	m_Player.draw(m_window);
	m_window.display();
}