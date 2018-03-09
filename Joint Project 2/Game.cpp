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

Game::Game() : m_window(sf::VideoMode(800, 600), "Project 2")
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
	m_background.setPosition(100, 0);

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
	
}



void Game::setUpMaze()
{
	for (int row = 0; row < MAX_ROW; row++)
	{
		int x = 0;
		for (int col = 0; col < MAX_COL; col++)
		{
			int y = 0;
			m_maze[row][col].setPosition(x,y);
			y += 50;
		}

		x += 50;
	}


}

void Game::drawMaze()
{
	int row = 1;

	m_maze[row][6].assignTile(m_wall);

	row = 2;

	m_maze[row][0].assignTile(m_wall);
	m_maze[row][1].assignTile(m_wall);
	m_maze[row][2].assignTile(m_wall);
	m_maze[row][4].assignTile(m_wall);
	m_maze[row][5].assignTile(m_wall);
	m_maze[row][6].assignTile(m_wall);
	m_maze[row][7].assignTile(m_wall);
	m_maze[row][9].assignTile(m_wall);
	m_maze[row][10].assignTile(m_crate);
	m_maze[row][11].assignTile(m_wall);

	row = 3;

	m_maze[row][6].assignTile(m_crate);
	m_maze[row][11].assignTile(m_wall);
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

	drawMaze();
	setUpMaze();

	m_window.display();
}