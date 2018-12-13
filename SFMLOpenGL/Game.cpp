#include <Game.h>
#include "MyMatrix3.h"
#include "MyVector3.h"

#include <iostream>
#include <string>


bool updatable = false;

gpp::Vector3 v3;

//Vectors Front Face
MyVector3 vecArray[24]{				  {1.0,1.0,-5.0 }, {-1.0,1.0,-5.0 }, {-1.0,-1.0,-5.0 }, { 1.0,1.0,-5.0 }, //Front Face
									  {1.0,1.0,-15.0}, { -1.0,1.0,-15.0 }, { -1.0f, -1.0f, -15.0f }, { 1.0f, -1.0f, -15.0f },
									  {-1.0f, 1.0f,-5.0f}, {-1.0f, 1.0f, -15.0f}, {-1.0f, -1.0f, -15.0f}, {-1.0f, -1.0f, -5.0f},
									  { 1.0f, 1.0f, -5.0f }, { 1.0f, 1.0f, -15.0f }, { 1.0f, -1.0f, -15.0f }, { 1.0f, -1.0f, -5.0f },
									  { -1.0f, 1.0f, -5.0f }, { -1.0f, 1.0f, -15.0f }, {1.0f, 1.0f, -15.0f}, { 1.0f, 1.0f, -5.0f },
									  { -1.0f, -1.0f, -5.0f }, {-1.0f, -1.0f, -15.0f }, { 1.0f, -1.0f, -15.0f }, { 1.0f, -1.0f, -5.0f }
						};

/*
MyVector3 frontFaceOne{ 1.0,1.0,-5.0 };
MyVector3 frontFaceTwo{ -1.0,1.0,-5.0 };
MyVector3 frontFaceThree{ -1.0,-1.0,-5.0 };
MyVector3 frontFaceFour{ 1.0,1.0,-5.0 };
*/

/*
//Vector Back Face
MyVector3 backFaceOne{ 1.0,1.0,-15.0 };
MyVector3 backFaceTwo{ -1.0,1.0,-15.0 };
MyVector3 backFaceThree{ -1.0f, -1.0f, -15.0f };
MyVector3 backFaceFour{ 1.0f, -1.0f, -15.0f };
*/

/*
//Vector Left Face
MyVector3 leftFaceOne{ -1.0f, 1.0f, -5.0f };
MyVector3 leftFaceTwo{ -1.0f, 1.0f, -15.0f };
MyVector3 leftFaceThree{ -1.0f, -1.0f, -15.0f };
MyVector3 leftFaceFour{ -1.0f, -1.0f, -5.0f };
*/

/*
//Vector Right Face
MyVector3 rightFaceOne{ 1.0f, 1.0f, -5.0f };
MyVector3 rightFaceTwo{ 1.0f, 1.0f, -15.0f };
MyVector3 rightFaceThree{ 1.0f, -1.0f, -15.0f };
MyVector3 rightFaceFour{ 1.0f, -1.0f, -5.0f };
*/

/*
//Vector Top Side
MyVector3 topFaceOne{ -1.0f, 1.0f, -5.0f };
MyVector3 topFaceTwo{ -1.0f, 1.0f, -15.0f };
MyVector3 topFaceThree{ 1.0f, 1.0f, -15.0f };
MyVector3 topFaceFour{ 1.0f, 1.0f, -5.0f };
*/

//Vector Bot Side
MyVector3 botFaceOne{ -1.0f, -1.0f, -5.0f };
MyVector3 botFaceTwo{ -1.0f, -1.0f, -15.0f };
MyVector3 botFaceThree{ 1.0f, -1.0f, -15.0f };
MyVector3 botFaceFour{ 1.0f, -1.0f, -5.0f };

//Translation Vectors
MyVector3 movingCubeRight{ .001,0,0 };
MyVector3 movingCubeLeft{ -.001,0,0 };
MyVector3 movingCubeUp{ 0,0.001,0 };
MyVector3 movingCubeDown{ 0,-0.001,0 };

//Scale Vecs
MyVector3 increasScale{ 1.01,1.01,1 };




Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		//cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(vecArray[0].getX(), vecArray[0].getY(), vecArray[0].getZ());
		glVertex3f(vecArray[1].getX(), vecArray[1].getY(), vecArray[1].getZ());
		glVertex3f(vecArray[2].getX(), vecArray[2].getY(), vecArray[2].getZ());
		glVertex3f(vecArray[3].getX(), vecArray[3].getY(), vecArray[3].getZ());

		//Back Face
		glVertex3f(vecArray[4].getX(), vecArray[4].getY(), vecArray[4].getZ());
		glVertex3f(vecArray[5].getX(), vecArray[5].getY(), vecArray[5].getZ());
		glVertex3f(vecArray[6].getX(), vecArray[6].getY(), vecArray[6].getZ());
		glVertex3f(vecArray[7].getX(), vecArray[7].getY(), vecArray[7].getZ());

		//Left fACE
		glColor3f(1.0f, 0.0f, 0.0f);     // Red
		glVertex3f(vecArray[8].getX(), vecArray[8].getY(), vecArray[8].getZ());
		glVertex3f(vecArray[9].getX(), vecArray[9].getY(), vecArray[9].getZ());
		glVertex3f(vecArray[10].getX(), vecArray[10].getY(), vecArray[10].getZ());
		glVertex3f(vecArray[11].getX(), vecArray[11].getY(), vecArray[11].getZ());

		//Right Face
		glColor3f(1.0f, 0.5f, 0.0f);     // Orange
		glVertex3f(vecArray[12].getX(), vecArray[12].getY(), vecArray[12].getZ());
		glVertex3f(vecArray[13].getX(), vecArray[13].getY(), vecArray[13].getZ());
		glVertex3f(vecArray[14].getX(), vecArray[14].getY(), vecArray[14].getZ());
		glVertex3f(vecArray[15].getX(), vecArray[15].getY(), vecArray[15].getZ());

		//Top Side
		glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
		glVertex3f(vecArray[16].getX(), vecArray[16].getY(), vecArray[16].getZ());
		glVertex3f(vecArray[17].getX(), vecArray[17].getY(), vecArray[17].getZ());
		glVertex3f(vecArray[18].getX(), vecArray[18].getY(), vecArray[18].getZ());
		glVertex3f(vecArray[19].getX(), vecArray[19].getY(), vecArray[19].getZ());

		//Bottom Side
		glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
		glVertex3f(vecArray[20].getX(), vecArray[20].getY(), vecArray[20].getZ());
		glVertex3f(vecArray[21].getX(), vecArray[21].getY(), vecArray[21].getZ());
		glVertex3f(vecArray[22].getX(), vecArray[22].getY(), vecArray[22].getZ());
		glVertex3f(vecArray[23].getX(), vecArray[23].getY(), vecArray[23].getZ());
		
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	glNewList(index, GL_COMPILE);
	glBegin(GL_QUADS);
	{

		//Front Face
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(vecArray[0].getX(), vecArray[0].getY(), vecArray[0].getZ());
		glVertex3f(vecArray[1].getX(), vecArray[1].getY(), vecArray[1].getZ());
		glVertex3f(vecArray[2].getX(), vecArray[2].getY(), vecArray[2].getZ());
		glVertex3f(vecArray[3].getX(), vecArray[3].getY(), vecArray[3].getZ());

		//Back Face
		glVertex3f(vecArray[4].getX(), vecArray[4].getY(), vecArray[4].getZ());
		glVertex3f(vecArray[5].getX(), vecArray[5].getY(), vecArray[5].getZ());
		glVertex3f(vecArray[6].getX(), vecArray[6].getY(), vecArray[6].getZ());
		glVertex3f(vecArray[7].getX(), vecArray[7].getY(), vecArray[7].getZ());

		//Left fACE
		glColor3f(1.0f, 0.0f, 0.0f);     // Red
		glVertex3f(vecArray[8].getX(), vecArray[8].getY(), vecArray[8].getZ());
		glVertex3f(vecArray[9].getX(), vecArray[9].getY(), vecArray[9].getZ());
		glVertex3f(vecArray[10].getX(), vecArray[10].getY(), vecArray[10].getZ());
		glVertex3f(vecArray[11].getX(), vecArray[11].getY(), vecArray[11].getZ());

		//Right Face
		glColor3f(1.0f, 0.5f, 0.0f);     // Orange
		glVertex3f(vecArray[12].getX(), vecArray[12].getY(), vecArray[12].getZ());
		glVertex3f(vecArray[13].getX(), vecArray[13].getY(), vecArray[13].getZ());
		glVertex3f(vecArray[14].getX(), vecArray[14].getY(), vecArray[14].getZ());
		glVertex3f(vecArray[15].getX(), vecArray[15].getY(), vecArray[15].getZ());

		//Top Side
		glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
		glVertex3f(vecArray[16].getX(), vecArray[16].getY(), vecArray[16].getZ());
		glVertex3f(vecArray[17].getX(), vecArray[17].getY(), vecArray[17].getZ());
		glVertex3f(vecArray[18].getX(), vecArray[18].getY(), vecArray[18].getZ());
		glVertex3f(vecArray[19].getX(), vecArray[19].getY(), vecArray[19].getZ());

		//Bottom Side
		glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
		glVertex3f(vecArray[20].getX(), vecArray[20].getY(), vecArray[20].getZ());
		glVertex3f(vecArray[21].getX(), vecArray[21].getY(), vecArray[21].getZ());
		glVertex3f(vecArray[22].getX(), vecArray[22].getY(), vecArray[22].getZ());
		glVertex3f(vecArray[23].getX(), vecArray[23].getY(), vecArray[23].getZ());
	}
	glEnd();
	glEndList();

	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		bool translationOn = true;
		bool scaleOn = false;
		bool rotationOn = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		bool translationOn = false;
		bool scaleOn = true;
		bool rotationOn = false;
	}


	if (translationOn == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			for (int i = 0; i < 24; i++)
			{
				vecArray[i] = vecArray[i] + movingCubeRight;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			for (int i = 0; i < 24; i++)
			{
				vecArray[i] = vecArray[i] + movingCubeLeft;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			for (int i = 0; i < 24; i++)
			{
				vecArray[i] = vecArray[i] + movingCubeUp;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			for (int i = 0; i < 24; i++)
			{
				vecArray[i] = vecArray[i] + movingCubeDown;
			}
		}
	}

	if (scaleOn == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			for (int i = 0; i < 24; i++)
			{
				//MyVector3 newScale = vecArray[i].dot(increasScale);				
			}
		}
	}
	
	if (updatable)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	
	//cout << "Update up" << endl;


	
}

void Game::draw()
{
	//cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//cout << "Drawing Cube " << endl;
	glLoadIdentity();
	//glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis

	glCallList(1);


	window.display();

}

void Game::unload()
{
	//cout << "Cleaning up" << endl;
}

