#pragma once
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include <iostream>
#include <vector>

class Sound
{
public:
	Sound(); 
	~Sound();

	void addSoundEffect(const char* path); // function to add effects
	void addAudioTrack(const char* path); // function to add tracks
	void playSoundEffect(const int which) const; // function to play the effects
	void playAudioTrack(); // function to play the tracks

private:
	Mix_Music* gMusic; //variable for storing music
	std::vector<Mix_Chunk*> mSoundEffectBank; // variable for storing chunk
};
