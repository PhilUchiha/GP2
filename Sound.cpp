#include "Sound.h"
#pragma once

Sound::Sound()
{
    int audio_rate = 22050;
    Uint16 audio_format = AUDIO_S16SYS;
    int audio_channels = 2;
    int audio_buffers = 4096;

    Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers);

        if (Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't init audio: %s", Mix_GetError());
            exit(-1);
        }
}

Sound::~Sound()
{
    SDL_Quit();
}

void Sound::addSoundEffect(const char* path)
{
    Mix_Chunk* tmpChunk = Mix_LoadWAV(path);

    if (tmpChunk != nullptr)
    {
        mSoundEffectBank.push_back(tmpChunk);
        std::cout << (mSoundEffectBank.size() - 1) << " Sound is Ready, path: " << path << '\n';
    }
    else
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't init audio: %s", Mix_GetError());
    }
}

void Sound::addAudioTrack(const char* path)
{
    gMusic = Mix_LoadMUS(path);

    if (gMusic == NULL) // checks for music
    {
        printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
    }
}

void Sound::playSoundEffect(const int which) const
{
    if (which > mSoundEffectBank.size() - 1) // checks position of music
    {
        std::cout << "Sound out of range.\n";
        return;
    }

    Mix_PlayChannel(-1, mSoundEffectBank[which], 0);

    std::cout << "Played Sound: " << which << '\n';
}

void Sound::playAudioTrack()
{
    if (Mix_PlayingMusic() == 0)
    {
        //Play the music
        Mix_PlayMusic(gMusic, -1);
    }

}