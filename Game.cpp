#include "Game.h"
#include "Camera.h"
#include <iostream>
#include <string>


Transform transform;

Game::Game()
{
	_gameState = GameState::PLAY;
	Screen* _gameDisplay = new Screen(); //new display
    Mesh* mesh1();
	Mesh* mesh2();
	Mesh* mesh3();
	
}

Game::~Game()
{
}

void Game::run()
{
	initialiseSystems(); 
	Loop();
}

void Game::initialiseSystems()
{
	_gameDisplay.initialiseScreen(); 
	
	sound.addAudioTrack("..\\res\\epic.wav");


	mesh1.loadModel("..\\res\\Grass_block.obj");
	mesh2.loadModel("..\\res\\planet_obj.obj");
	mesh3.loadModel("..\\res\\monkey3.obj");
	
	myCamera.initisaliseCamera(glm::vec3(0, 0, -5), 70.0f, (float)_gameDisplay.getScreenWidth()/_gameDisplay.getScreenHeight(), 0.01f, 1000.0f);

	shader.initialise("..\\res\\shader"); //new shader

	counter = 1.0f;
}

void Game::Loop()
{
	while (_gameState != GameState::EXIT)
	{

		playSound(0, mesh1.getSpherePosition());
		processInput();
		drawGame();
		collision(mesh1.getSpherePosition(), mesh1.getSphereRadius(), mesh2.getSpherePosition(), mesh2.getSphereRadius());
	}
}

void Game::processInput()
{
	SDL_Event evnt;

	while(SDL_PollEvent(&evnt)) //get and process events
	{
		switch (evnt.type)
		{
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;
		}
	}
	
}


bool Game::collision(glm::vec3 m1Pos, float m1Rad, glm::vec3 m2Pos, float m2Rad)
{
	float distance = ((m2Pos.x - m1Pos.x)*(m2Pos.x - m1Pos.x) + (m2Pos.y - m1Pos.y)*(m2Pos.y - m1Pos.y) + (m2Pos.z - m1Pos.z)*(m2Pos.z - m1Pos.z)); // calculating collision detection through distances of spheres
	
	if (distance*distance < (m1Rad + m2Rad))
	{
		cout << distance << '\n';
		return true;
	}
	else
	{
		return false;
	}
}

void Game::playSound(unsigned int Source, glm::vec3 pos)
{
	sound.playAudioTrack(); // plays specific audio track
}


void Game::drawGame()
{
	_gameDisplay.clearScreen(0.0f, 0.0f, 0.0f, 1.0f); //emptys screen 
	
	transform.SetPosition(glm::vec3(sinf(counter), 0.5, 0.0)); //mesh 1 position
	transform.SetRotation(glm::vec3(0.0, 0.0, counter * 0.2)); // mesh 1 rotation
	transform.SetScale(glm::vec3(0.1, 0.1, 0.1)); // mesh 1 scale
	
	Texture texture("..\\res\\Metal.jpg"); //load texture
	Texture texture1("..\\res\\bricks.jpg"); //load texture

	shader.Bind(); // bind shader
	shader.Update(transform, myCamera);
	texture.Bind(0); // bind texture
	mesh1.draw(); // draw the mesh to screen
	mesh1.updateSphereData(*transform.GetPosition(), 0.6f);
	

	transform.SetPosition(glm::vec3(-sinf(counter), -0.5, -sinf(counter)*5)); //mesh 2 position
	transform.SetRotation(glm::vec3(0.0, 0.0, counter * 5)); //mesh 2 rotation
	transform.SetScale(glm::vec3(0.03, 0.03, 0.03)); //mesh 2 scale

	shader.Bind(); // bind shader
	shader.Update(transform, myCamera);
	texture.Bind(1); // bind texture
	mesh2.draw(); // draw mesh 2 to screen
	mesh2.updateSphereData(*transform.GetPosition(), 0.6f);
	counter = counter + 0.05f;

	transform.SetPosition(glm::vec3(sinf(counter), -0.0, -sinf(counter) * 5)); //mesh 3 position
	transform.SetRotation(glm::vec3(0.0, 0.0, counter * 0)); //mesh 3 rotation
	transform.SetScale(glm::vec3(0.9, 0.9, 0.9)); //mesh 3 scale

	shader.Bind(); // bind shader
	shader.Update(transform, myCamera);
	texture.Bind(1); // bind texture
	mesh3.draw(); // draw mesh 3 to screen
	mesh3.updateSphereData(*transform.GetPosition(), 0.6f);
	counter = counter + 0.05f;

				
	glEnableClientState(GL_COLOR_ARRAY); 
	glEnd();

	_gameDisplay.swapBuffer();
} 