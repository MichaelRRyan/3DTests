/// @Author Michael Rainsford Ryan

#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "MyMatrix3.h"
#include "Cube3D.h"

const int NO_CUBES{ 5 };

class Game
{
public:

	Game();
	~Game();

	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	void setupShapes();

	sf::RenderWindow m_window;
	bool m_exitGame;

	sf::VertexArray m_renderCubes{ sf::Lines };
	Cube3D m_cubes[NO_CUBES];

};

#endif // !GAME

