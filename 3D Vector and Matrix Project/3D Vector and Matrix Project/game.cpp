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
		{ { 400,100 },CORNFLOWER_BLUE },
		{ { 100,550 },CORNFLOWER_BLUE },
		{ { 700,550 },CORNFLOWER_BLUE }
		}

{	

	for (size_t i = 0; i < 3; i++)
	{
		m_triangle.append(m_vertexs[i]);
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
		currentPosition[i] = originalPosition[i];
		
		movement();
	}
	
}

void Game::movement()
{
	for (size_t i = 0; i < 3; i++)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
		{
			xRotation = Matrix3::rotationX(0.0349066);//angle set to 2 degrees
			for (size_t i = 0; i < 3; i++)
			{
				currentPosition[i] = xRotation * currentPosition[i];
				m_triangle[i].position.x = currentPosition[i].X();
				m_triangle[i].position.y = currentPosition[i].Y();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			currentPosition[i] = Matrix3::translation(activeTranslation) * originalPosition[i];
			m_triangle[i].position.x = currentPosition[i].X();
			m_triangle[i].position.y = currentPosition[i].Y();
		}
	}
}

void Game::render()
{
	m_window.clear();

	m_window.draw(m_triangle);

	m_window.display();
}