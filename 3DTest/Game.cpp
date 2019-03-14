/// @Author Michael Rainsford Ryan

#include "Game.h"

Game::Game() :
	m_window{ sf::VideoMode{ 800u, 600u, 32u }, "Basic Game" },
	m_exitGame{ false }
{
	setupShapes();
}

Game::~Game()
{

}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float FPS = 60.0f;
	sf::Time timePerFrame = sf::seconds(1.0f / FPS); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // Run as many times as possible
		timeSinceLastUpdate += clock.restart();
		if (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // Run at a minimum of 60 fps
			update(timePerFrame); // 60 fps
		}
		render(); // Run as many times as possible
	}
}

void Game::processEvents()
{
	sf::Event nextEvent;
	while (m_window.pollEvent(nextEvent))
	{
		if (sf::Event::Closed == nextEvent.type) // check if the close window button is clicked on.
		{
			m_window.close();
		}
	}
}

void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		for (int i = 0; i < NO_CUBES; i++)
		{
			m_cubes[i].m_displacement.x += 4.0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		for (int i = 0; i < NO_CUBES; i++)
		{
			m_cubes[i].m_displacement.x -= 4.0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		for (int i = 0; i < NO_CUBES; i++)
		{
			m_cubes[i].m_displacement.y -= 4.0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		for (int i = 0; i < NO_CUBES; i++)
		{
			m_cubes[i].m_displacement.y += 4.0;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		for (int i = 0; i < NO_CUBES; i++)
		{
			m_cubes[i].m_displacement.z += 4.0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		for (int i = 0; i < NO_CUBES; i++)
		{
			m_cubes[i].m_displacement.z -= 4.0;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		for (int i = 0; i < NO_CUBES; i++)
		{
			m_cubes[i].m_rotation.x += 0.05;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		for (int i = 0; i < NO_CUBES; i++)
		{
			m_cubes[i].m_rotation.x -= 0.05;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		for (int i = 0; i < NO_CUBES; i++)
		{
			m_cubes[i].m_rotation.y += 0.05;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		for (int i = 0; i < NO_CUBES; i++)
		{
			m_cubes[i].m_rotation.y -= 0.05;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		for (int i = 0; i < NO_CUBES; i++)
		{
			m_cubes[i].m_rotation.z += 0.05;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		for (int i = 0; i < NO_CUBES; i++)
		{
			m_cubes[i].m_rotation.z -= 0.05;
		}
	}

	for (int i = 0; i < NO_CUBES; i++)
	{
		m_cubes[i].update();
	}
}

void Game::render()
{
	m_window.clear();

	for (int i = 0; i < NO_CUBES; i++)
	{
		m_cubes[i].draw(m_window, m_renderCubes);
	}

	m_window.display();
}

void Game::setupShapes()
{
	//m_cubes[0].m_points[0] = { 150.0,200.0,0.0 };
	//m_cubes[0].m_points[1] = { 250.0,200.0,0.0 };
	//m_cubes[0].m_points[2] = { 250.0,300.0,0.0 };
	//m_cubes[0].m_points[3] = { 150.0,300.0,0.0 };
	//m_cubes[0].m_points[4] = { 150.0,200.0,100.0 };
	//m_cubes[0].m_points[5] = { 250.0,200.0,100.0 };
	//m_cubes[0].m_points[6] = { 250.0,300.0,100.0 };
	//m_cubes[0].m_points[7] = { 150.0,300.0,100.0 };

	//m_cubes[0].setup();
	//m_cubes[0].m_centre = { 250.0,250.0,50.0 };

	//m_cubes[1].m_points[0] = { 210.0,0.0,10.0 };
	//m_cubes[1].m_points[1] = { 290.0,0.0,10.0 };
	//m_cubes[1].m_points[2] = { 290.0,200.0,10.0 };
	//m_cubes[1].m_points[3] = { 210.0,200.0,10.0 };
	//m_cubes[1].m_points[4] = { 210.0,0.0,90.0 };
	//m_cubes[1].m_points[5] = { 290.0,0.0,90.0 };
	//m_cubes[1].m_points[6] = { 290.0,200.0,90.0 };
	//m_cubes[1].m_points[7] = { 210.0,200.0,90.0 };

	//m_cubes[1].setup();
	//m_cubes[1].m_centre = { 250.0,250.0,50.0 };

	//// Third shape
	//m_cubes[2].m_points[0] = { 250.0,200.0,0.0 };
	//m_cubes[2].m_points[1] = { 350.0,200.0,0.0 };
	//m_cubes[2].m_points[2] = { 350.0,300.0,0.0 };
	//m_cubes[2].m_points[3] = { 250.0,300.0,0.0 };
	//m_cubes[2].m_points[4] = { 250.0,200.0,100.0 };
	//m_cubes[2].m_points[5] = { 350.0,200.0,100.0 };
	//m_cubes[2].m_points[6] = { 350.0,300.0,100.0 };
	//m_cubes[2].m_points[7] = { 250.0,300.0,100.0 };

	//m_cubes[2].setup();
	//m_cubes[2].m_centre = { 250.0,250.0,50.0 };

	//// forth shape
	//m_cubes[3].m_points[0] = { 220.0,-100.0,20.0 };
	//m_cubes[3].m_points[1] = { 280.0,-100.0,20.0 };
	//m_cubes[3].m_points[2] = { 300.0,0.0,0.0 };
	//m_cubes[3].m_points[3] = { 200.0,0.0,0.0 };
	//m_cubes[3].m_points[4] = { 220.0,-100.0,80.0 };
	//m_cubes[3].m_points[5] = { 280.0,-100.0,80.0 };
	//m_cubes[3].m_points[6] = { 300.0,0.0,100.0 };
	//m_cubes[3].m_points[7] = { 200.0,0.0,100.0 };

	//m_cubes[3].setup();
	//m_cubes[3].m_centre = { 250.0,250.0,50.0 };

	m_cubes[0].m_points[0] = { 100.0,50.0,-50.0 }; // front, top, left
	m_cubes[0].m_points[1] = { 130.0,50.0,-50.0 }; // front, top, left
	m_cubes[0].m_points[2] = { 130.0,350.0,-50.0 };
	m_cubes[0].m_points[3] = { 100.0,350.0,-50.0 };
	m_cubes[0].m_points[4] = { 100.0,50.0,100.0 };
	m_cubes[0].m_points[5] = { 130.0,50.0,100.0 };
	m_cubes[0].m_points[6] = { 130.0,350.0,100.0 };
	m_cubes[0].m_points[7] = { 100.0,350.0,100.0 };

	m_cubes[0].setup();
	m_cubes[0].m_centre = { 275.0,200.0,25.0 };

	m_cubes[1].m_points[0] = { 420.0,50.0,-50.0 };
	m_cubes[1].m_points[1] = { 450.0,50.0,-50.0 };
	m_cubes[1].m_points[2] = { 450.0,350.0,-50.0 };
	m_cubes[1].m_points[3] = { 420.0,350.0,-50.0 };
	m_cubes[1].m_points[4] = { 420.0,50.0,100.0 };
	m_cubes[1].m_points[5] = { 450.0,50.0,100.0 };
	m_cubes[1].m_points[6] = { 450.0,350.0,100.0 };
	m_cubes[1].m_points[7] = { 420.0,350.0,100.0 };

	m_cubes[1].setup();
	m_cubes[1].m_centre = { 275.0,200.0,25.0 };

	// Third shape
	m_cubes[2].m_points[0] = { 200.0,100.0,-20.0 };
	m_cubes[2].m_points[1] = { 350.0,100.0,-20.0 };
	m_cubes[2].m_points[2] = { 350.0,300.0,-20.0 };
	m_cubes[2].m_points[3] = { 200.0,300.0,-20.0 };
	m_cubes[2].m_points[4] = { 200.0,100.0,70.0 };
	m_cubes[2].m_points[5] = { 350.0,100.0,70.0 };
	m_cubes[2].m_points[6] = { 350.0,300.0,70.0 };
	m_cubes[2].m_points[7] = { 200.0,300.0,70.0 };

	m_cubes[2].setup();
	m_cubes[2].m_centre = { 275.0,200.0,25.0 };

	// forth shape
	m_cubes[3].m_points[0] = { 230.0,0.0,20.0 };
	m_cubes[3].m_points[1] = { 320.0,0.0,20.0 };
	m_cubes[3].m_points[2] = { 350.0,100.0,-20.0 };
	m_cubes[3].m_points[3] = { 200.0,100.0,-20.0 };
	m_cubes[3].m_points[4] = { 230.0,0.0,70.0 };
	m_cubes[3].m_points[5] = { 320.0,0.0,70.0 };
	m_cubes[3].m_points[6] = { 350.0,100.0,70.0 };
	m_cubes[3].m_points[7] = { 200.0,100.0,70.0 };

	m_cubes[3].setup();
	m_cubes[3].m_centre = { 275.0,200.0,25.0 };

	// fifth shape
	m_cubes[4].m_points[0] = { 130.0,200.0,10.0 };
	m_cubes[4].m_points[1] = { 420.0,200.0,10.0 };
	m_cubes[4].m_points[2] = { 420.0,300.0,10.0 };
	m_cubes[4].m_points[3] = { 130.0,300.0,10.0 };
	m_cubes[4].m_points[4] = { 130.0,200.0,40.0 };
	m_cubes[4].m_points[5] = { 420.0,200.0,40.0 };
	m_cubes[4].m_points[6] = { 420.0,300.0,40.0 };
	m_cubes[4].m_points[7] = { 130.0,300.0,40.0 };

	m_cubes[4].setup();
	m_cubes[4].m_centre = { 275.0,200.0,25.0 };
}