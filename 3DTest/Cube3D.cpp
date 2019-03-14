#include "Cube3D.h"



Cube3D::Cube3D()
{
}


Cube3D::~Cube3D()
{
}

void Cube3D::setup()
{
	for (int i = 0; i < NUMBER_OF_POINTS; i++)
	{
		m_currentPosition[i].color = sf::Color::White;
		m_currentPosition[i].position = m_points[i];
	}
}

void Cube3D::draw(sf::RenderWindow & t_window, sf::VertexArray t_renderPoints)
{
	t_renderPoints.clear();
	// Draw front side
	t_renderPoints.append(m_currentPosition[0]);
	t_renderPoints.append(m_currentPosition[1]);
	t_renderPoints.append(m_currentPosition[1]);
	t_renderPoints.append(m_currentPosition[2]);
	t_renderPoints.append(m_currentPosition[2]);
	t_renderPoints.append(m_currentPosition[3]);
	t_renderPoints.append(m_currentPosition[3]);
	t_renderPoints.append(m_currentPosition[0]);

	// Draw back side
	t_renderPoints.append(m_currentPosition[4]);
	t_renderPoints.append(m_currentPosition[5]);
	t_renderPoints.append(m_currentPosition[5]);
	t_renderPoints.append(m_currentPosition[6]);
	t_renderPoints.append(m_currentPosition[6]);
	t_renderPoints.append(m_currentPosition[7]);
	t_renderPoints.append(m_currentPosition[7]);
	t_renderPoints.append(m_currentPosition[4]);

	// Draw connecters
	t_renderPoints.append(m_currentPosition[0]);
	t_renderPoints.append(m_currentPosition[4]);
	t_renderPoints.append(m_currentPosition[1]);
	t_renderPoints.append(m_currentPosition[5]);
	t_renderPoints.append(m_currentPosition[2]);
	t_renderPoints.append(m_currentPosition[6]);
	t_renderPoints.append(m_currentPosition[3]);
	t_renderPoints.append(m_currentPosition[7]);

	t_window.draw(t_renderPoints);
}

void Cube3D::update()
{
	for (int i = 0; i < NUMBER_OF_POINTS; i++)
	{
		MyVector3 tempPos = m_points[i] - m_centre;
		tempPos = MyMatrix3::rotationX(m_rotation.x) * MyMatrix3::rotationY(m_rotation.y) * MyMatrix3::rotationZ(m_rotation.z) * tempPos;
		tempPos += m_centre;
		m_currentPosition[i].position = tempPos + m_displacement;
	}
}
