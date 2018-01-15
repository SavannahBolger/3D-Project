#ifndef GAME
#define GAME
// must write comments for Pete's sake


#include "Vector3D.h"
#include "Matrix3.h"
#include <SFML\Graphics.hpp>

const sf::Color CORNFLOWER_BLUE{ 154, 206, 235, 255 };

class Game
{
public:
	Game();
	void LoadContent();
	void run();

private:
	void processEvents();
	void update(sf::Time);
	void movement();
	void render();

private:        
	sf::RenderWindow m_window;
	sf::VertexArray m_triangle;
	sf::Vertex m_vertexs[3]; // only used to initialise the array 
	Vector3D origin{0,0,0};
	Vector3D originalPosition[3];
	Vector3D currentPosition[3];
	Vector3D activeTranslation{0,-1,0};
	size_t firstElement = 0;
	size_t lastElement = 0;
	Matrix3 xRotation;//x axis rotation
	Matrix3 yRotation;//y axis rotation
	Matrix3 zRotation;//z axis rotation
};

#endif // !GAME
