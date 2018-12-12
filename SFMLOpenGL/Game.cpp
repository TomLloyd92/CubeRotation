#include <Game.h>
#include "MyMatrix3.h"
#include "MyVector3.h"

#include <iostream>
#include <string>


bool updatable = false;

gpp::Vector3 v3;

//Vectors Front Face
MyVector3 vecArrayWithAllTheLads[24]{ {1.0,1.0,-5.0 }, {-1.0,1.0,-5.0 }, {-1.0,-1.0,-5.0 }, { 1.0,1.0,-5.0 }, //Front Face
									  {1.0,1.0,-15.0}, { -1.0,1.0,-15.0 }, { -1.0f, -1.0f, -15.0f }, { 1.0f, -1.0f, -15.0f },
									  {-1.0f, 1.0f,-5.0f}, {-1.0f, 1.0f, -15.0f}, {-1.0f, -1.0f, -15.0f}, {-1.0f, -1.0f, -5.0f},
									  { 1.0f, 1.0f, -5.0f }, { 1.0f, 1.0f, -15.0f }, { 1.0f, -1.0f, -15.0f }, { 1.0f, -1.0f, -5.0f },
									  {}



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


//Vector Top Side
MyVector3 topFaceOne{ -1.0f, 1.0f, -5.0f };
MyVector3 topFaceTwo{ -1.0f, 1.0f, -15.0f };
MyVector3 topFaceThree{ 1.0f, 1.0f, -15.0f };
MyVector3 topFaceFour{ 1.0f, 1.0f, -5.0f };

//Vector Bot Side
MyVector3 botFaceOne{ -1.0f, -1.0f, -5.0f };
MyVector3 botFaceTwo{ -1.0f, -1.0f, -15.0f };
MyVector3 botFaceThree{ 1.0f, -1.0f, -15.0f };
MyVector3 botFaceFour{ 1.0f, -1.0f, -5.0f };

//Translation Vectors
MyVector3 movingCubeRight{ .01,0,0 };




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
		glVertex3f(frontFaceOne.getX(), frontFaceOne.getY(), frontFaceOne.getZ());
		glVertex3f(frontFaceTwo.getX(), frontFaceTwo.getY(), frontFaceTwo.getZ());
		glVertex3f(frontFaceThree.getX(), frontFaceThree.getY(), frontFaceThree.getZ());
		glVertex3f(frontFaceFour.getX(), frontFaceFour.getY(), frontFaceFour.getZ());

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(backFaceOne.getX(), backFaceOne.getY(), backFaceOne.getZ());
		glVertex3f(backFaceTwo.getX(), backFaceTwo.getY(), backFaceTwo.getZ());
		glVertex3f(backFaceThree.getX(), backFaceThree.getY(), backFaceThree.getZ());
		glVertex3f(backFaceFour.getX(), backFaceFour.getY(), backFaceFour.getZ());
		
		//Left fACE
		glColor3f(1.0f, 0.0f, 0.0f);     // Red
		glVertex3f(leftFaceOne.getX(), leftFaceOne.getY(), leftFaceOne.getZ());
		glVertex3f(leftFaceTwo.getX(), leftFaceTwo.getY(), leftFaceTwo.getZ());
		glVertex3f(leftFaceThree.getX(), leftFaceThree.getY(), leftFaceThree.getZ());
		glVertex3f(leftFaceFour.getX(),leftFaceFour.getY(), leftFaceFour.getZ());

		//Right Face
		glColor3f(1.0f, 0.5f, 0.0f);     // Orange
		glVertex3f(rightFaceOne.getX(), rightFaceOne.getY(), rightFaceOne.getZ());
		glVertex3f(rightFaceTwo.getX(), rightFaceTwo.getY(), rightFaceTwo.getZ());
		glVertex3f(rightFaceThree.getX(), rightFaceThree.getY(), rightFaceThree.getZ());
		glVertex3f(rightFaceFour.getX(), rightFaceFour.getY(), rightFaceFour.getZ());

		//Top Side
		glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
		glVertex3f(topFaceOne.getX(), topFaceOne.getY(), topFaceOne.getZ());
		glVertex3f(topFaceTwo.getX(), topFaceTwo.getY(), topFaceTwo.getZ());
		glVertex3f(topFaceThree.getX(), topFaceThree.getY(), topFaceThree.getZ());
		glVertex3f(topFaceFour.getX(), topFaceFour.getY(), topFaceFour.getZ());

		//Bottom Side
		glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
		glVertex3f(botFaceOne.getX(), botFaceOne.getY(), botFaceOne.getZ());
		glVertex3f(botFaceTwo.getX(), botFaceTwo.getY(), botFaceTwo.getZ());
		glVertex3f(botFaceThree.getX(), botFaceThree.getY(), botFaceThree.getZ());
		glVertex3f(botFaceFour.getX(), botFaceFour.getY(), botFaceFour.getZ());
		
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
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(frontFaceOne.getX(), frontFaceOne.getY(), frontFaceOne.getZ());
		glVertex3f(frontFaceTwo.getX(), frontFaceTwo.getY(), frontFaceTwo.getZ());
		glVertex3f(frontFaceThree.getX(), frontFaceThree.getY(), frontFaceThree.getZ());
		glVertex3f(frontFaceFour.getX(), frontFaceFour.getY(), frontFaceFour.getZ());

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(backFaceOne.getX(), backFaceOne.getY(), backFaceOne.getZ());
		glVertex3f(backFaceTwo.getX(), backFaceTwo.getY(), backFaceTwo.getZ());
		glVertex3f(backFaceThree.getX(), backFaceThree.getY(), backFaceThree.getZ());
		glVertex3f(backFaceFour.getX(), backFaceFour.getY(), backFaceFour.getZ());

		//Left fACE
		glColor3f(1.0f, 0.0f, 0.0f);     // Red
		glVertex3f(leftFaceOne.getX(), leftFaceOne.getY(), leftFaceOne.getZ());
		glVertex3f(leftFaceTwo.getX(), leftFaceTwo.getY(), leftFaceTwo.getZ());
		glVertex3f(leftFaceThree.getX(), leftFaceThree.getY(), leftFaceThree.getZ());
		glVertex3f(leftFaceFour.getX(), leftFaceFour.getY(), leftFaceFour.getZ());

		//Right Face
		glColor3f(1.0f, 0.5f, 0.0f);     // Orange
		glVertex3f(rightFaceOne.getX(), rightFaceOne.getY(), rightFaceOne.getZ());
		glVertex3f(rightFaceTwo.getX(), rightFaceTwo.getY(), rightFaceTwo.getZ());
		glVertex3f(rightFaceThree.getX(), rightFaceThree.getY(), rightFaceThree.getZ());
		glVertex3f(rightFaceFour.getX(), rightFaceFour.getY(), rightFaceFour.getZ());

		//Top Side
		glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
		glVertex3f(topFaceOne.getX(), topFaceOne.getY(), topFaceOne.getZ());
		glVertex3f(topFaceTwo.getX(), topFaceTwo.getY(), topFaceTwo.getZ());
		glVertex3f(topFaceThree.getX(), topFaceThree.getY(), topFaceThree.getZ());
		glVertex3f(topFaceFour.getX(), topFaceFour.getY(), topFaceFour.getZ());

		//Bottom Side
		glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
		glVertex3f(botFaceOne.getX(), botFaceOne.getY(), botFaceOne.getZ());
		glVertex3f(botFaceTwo.getX(), botFaceTwo.getY(), botFaceTwo.getZ());
		glVertex3f(botFaceThree.getX(), botFaceThree.getY(), botFaceThree.getZ());
		glVertex3f(botFaceFour.getX(), botFaceFour.getY(), botFaceFour.getZ());

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

	if (translationOn == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			std::cout << "DEW IT" << std::endl;

			std::cout << frontFaceOne.getX() << std::endl;

			//Vector Front Face
			frontFaceOne = frontFaceOne + movingCubeRight;
			frontFaceTwo = frontFaceTwo + movingCubeRight;
			frontFaceThree = frontFaceThree + movingCubeRight;
			frontFaceFour = frontFaceFour + movingCubeRight;

			//Vector Back Face
			backFaceOne = backFaceOne + movingCubeRight;
			backFaceTwo = backFaceOne + movingCubeRight;
			backFaceThree = backFaceOne + movingCubeRight;
			backFaceFour = backFaceFour + movingCubeRight;

			//Vector Left Face
			leftFaceOne = leftFaceOne + movingCubeRight;
			leftFaceTwo = leftFaceTwo + movingCubeRight;
			leftFaceThree = leftFaceThree + movingCubeRight;
			leftFaceFour = leftFaceFour + movingCubeRight;

			//Vector Right Face
			rightFaceOne = rightFaceOne + movingCubeRight;
			rightFaceTwo = rightFaceTwo + movingCubeRight;
			rightFaceThree = rightFaceThree + movingCubeRight;
			rightFaceFour = rightFaceFour + movingCubeRight;

			//Vector Top Side
			topFaceOne = topFaceOne + movingCubeRight;
			topFaceTwo = topFaceTwo + movingCubeRight;
			topFaceThree = topFaceThree + movingCubeRight;
			topFaceFour = topFaceFour + movingCubeRight;

			//Vector Bot Side
			botFaceOne = botFaceOne + movingCubeRight;
			botFaceTwo = botFaceTwo + movingCubeRight;
			botFaceThree = botFaceThree + movingCubeRight;
			botFaceFour = botFaceFour + movingCubeRight;
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

