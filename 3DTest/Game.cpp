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
		m_cube.m_displacement.x += 4.0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_cube.m_displacement.x -= 4.0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_cube.m_displacement.y -= 4.0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_cube.m_displacement.y += 4.0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		m_cube.m_rotation.x += 0.05;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		m_cube.m_rotation.x -= 0.05;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_cube.m_rotation.y += 0.05;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_cube.m_rotation.y -= 0.05;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		m_cube.m_rotation.z += 0.05;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		m_cube.m_rotation.z -= 0.05;
	}

	m_cube.update();
}

void Game::render()
{
	m_window.clear();

	m_cube.draw(m_window, m_cubes);

	m_window.display();
}

void Game::setupShapes()
{
	m_cube.m_points[0] = { 200.0,200.0,0.0 };
	m_cube.m_points[1] = { 300.0,200.0,0.0 };
	m_cube.m_points[2] = { 300.0,300.0,0.0 };
	m_cube.m_points[3] = { 200.0,300.0,0.0 };
	m_cube.m_points[4] = { 200.0,200.0,100.0 };
	m_cube.m_points[5] = { 300.0,200.0,100.0 };
	m_cube.m_points[6] = { 300.0,300.0,100.0 };
	m_cube.m_points[7] = { 200.0,300.0,100.0 };

	m_cube.setup();

	m_cube.m_centre = { 250.0,250.0,50.0 };
}