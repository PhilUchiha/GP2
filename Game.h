#pragma once
#include <SDL\SDL.h>
#include <GL/glew.h>
#include <SDL/SDL_mixer.h>
#include "Screen.h" 
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "transform.h"
#include "Sound.h"

enum class GameState{PLAY, EXIT}; // two different game states

class Game
{
public:
	Game();
	~Game();

	void run();

private:

	void initialiseSystems(); // used to initialise systems such as models, shaders and displays
	void processInput();
	void Loop(); // this shows the game loop
	void drawGame(); //draws the game to the screen
	bool collision(glm::vec3 m1Pos, float m1Rad, glm::vec3 m2Pos, float m2Rad); // creates collision detection between mesh1 and mesh 2
	void playSound(unsigned int Source, glm::vec3 pos); // initialises the audio systems

	Screen _gameDisplay; // creates screen
	GameState _gameState; // creates game state
	Mesh mesh1; // creates mesh 1
	Mesh mesh2; //creates mesh 2
	Mesh mesh3; // creates mesh 3
	Camera myCamera; // creates camera
	Shader shader; // creates shader
	Sound sound;


	float counter; // counter variable
	unsigned int whistle; // whistle variable
	unsigned int backGroundMusic; // background music variable
};

