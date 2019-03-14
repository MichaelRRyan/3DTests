#pragma once

#include"MyMatrix3.h"

class Cube3D
{
public:
	Cube3D();
	~Cube3D();

public:
	static const int NUMBER_OF_POINTS = 8;
	MyVector3 m_points[NUMBER_OF_POINTS];
	sf::Vertex m_currentPosition[NUMBER_OF_POINTS];
	MyVector3 m_centre;
	MyVector3 m_displacement;
	MyVector3 m_rotation;

	void setup();
	void draw(sf::RenderWindow & t_window, sf::VertexArray t_renderPoints);
	void update();
};

