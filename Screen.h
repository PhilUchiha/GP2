#pragma once
#include <SDL/SDL.h>
#include <GL\glew.h>
#include <iostream>
#include <string>
using namespace std;


class Screen
{
public:
	Screen();
	~Screen();
	void initialiseScreen(); // creates screen/display
	void swapBuffer(); // swaps between buffers
	void clearScreen(float r, float g, float b, float a); // emptys anything on screen

	float getScreenWidth(); //gets width of screen display
	float getScreenHeight(); // gets height of screen display

private:

	void returnError(std::string errorString);
	
	SDL_GLContext glContext; //global variable to hold the context
	SDL_Window* sdlWindow; //holds pointer to out window
	float screenWidth; // variable for width
	float screenHeight; // variable for height
};

