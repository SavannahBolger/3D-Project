#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-main-d.lib")
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-main.lib")
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include "game.h"
#include <iostream>

Game::Game() :
	m_window{ sf::VideoMode{800, 600}, "SMFL Game" },
	m_triangle{ sf::Triangles },
	m_vertexs{
		{ { 0,-30 },CORNFLOWER_BLUE },
		{ { -30,15 },CORNFLOWER_BLUE },
		{ { 30,15 },CORNFLOWER_BLUE }}

{

	for (size_t i = 0; i < 3; i++)
	{
		m_triangle.append(m_vertexs[i]);
		originalPosition[i] = Vector3D(m_vertexs[i].position.x, m_vertexs[i].position.y,0);
		currentPosition[i] = originalPosition[i];
	}

}

void Game::LoadContent()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{		
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);			
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void Game::update(sf::Time)
{
	// wrong way to do transformations just here to show you
	// how the vertexes could be updated you need to maintain
	// a set of MyVector3Ds and then update the vertex array
	for (size_t i = 0; i < 3; i++)
	{
		movement();
		m_triangle[i].position = sf::Vector2f(currentPosition[i].X() + 400, currentPosition[i].Y() + 300);
		
	}
	
}

void Game::movement()
{
	for (size_t i = 0; i < 3; i++)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
		{
			xRotation = Matrix3::rotationX(0.00174533);//angle set to 2 degrees
			for (size_t i = 0; i < 3; i++)
			{
				currentPosition[i] = (xRotation * currentPosition[i]);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
		{
			xRotation = Matrix3::rotationX(-0.00174533);//angle set to 2 degrees
			for (size_t i = 0; i < 3; i++)
			{
				currentPosition[i] = xRotation * currentPosition[i];
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
		{
			yRotation = Matrix3::rotationY(0.00174533);//angle set to 2 degrees
			for (size_t i = 0; i < 3; i++)
			{
				currentPosition[i] = yRotation * currentPosition[i];
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
		{
			yRotation = Matrix3::rotationY(-0.00174533);//angle set to 2 degrees
			for (size_t i = 0; i < 3; i++)
			{
				currentPosition[i] = yRotation * currentPosition[i];
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
		{
			zRotation = Matrix3::rotationZ(0.00174533);//angle set to 2 degrees
			for (size_t i = 0; i < 3; i++)
			{
				currentPosition[i] = zRotation * currentPosition[i];
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
		{
			zRotation = Matrix3::rotationZ(-0.00174533);//angle set to 2 degrees
			for (size_t i = 0; i < 3; i++)
			{
				currentPosition[i] = zRotation * currentPosition[i];
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			currentPosition[i] =(Matrix3::translation(activeTranslation) * currentPosition[i]) -  Vector3D(0, 1, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			currentPosition[i] = (Matrix3::translation(activeTranslation) * currentPosition[i]) + Vector3D(0, 1, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			currentPosition[i] = (Matrix3::translation(activeTranslation) * currentPosition[i]) - Vector3D(1,0, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			currentPosition[i] = (Matrix3::translation(activeTranslation) * currentPosition[i]) + Vector3D(1, 0, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			currentPosition[i] = (Matrix3::scale(1.5) * originalPosition[i]);
		}
		else
		{
			currentPosition[i] = originalPosition[i];
		}
	}
}

void Game::render()
{
	m_window.clear();

	m_window.draw(m_triangle);

	m_window.display();
}