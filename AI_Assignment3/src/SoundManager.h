#pragma once
#ifndef __SOUND_MANAGER__
#define __SOUND_MANAGER__

// Core Libraries
#include <iostream>
#include <string>
#include <map> 

#include "SoundType.h"
#include <SDL_mixer.h>

/* Singleton */
class SoundManager
{
public:
	static SoundManager& Instance()
	{
		static SoundManager instance; // Magic statics.
		return instance;
	}
	static void Init();
	static void allocateChannels(const int channels);
	static bool load(const std::string& file_name, const std::string& id, SoundType type);
	static void unload(const std::string& id, SoundType type);
	static void playMusic(const std::string& id, int loop = -1, int fade_in = 0);
	static void stopMusic(int fade_out = 0) ;
	static void pauseMusic() ;
	static	void resumeMusic() ;
	static	void playSound(const std::string& id, int loop = 0, int channel = -1);
	static	void setMusicVolume(const int vol) ;
	static	void setSoundVolume(const int vol);
	static	void setAllVolume(const int vol) ;
	
	// Panning converts a single slider value from 0 to 100 to the stereo speaker volumes.
	static	void panLeft(const unsigned increment = 5, const int channel = MIX_CHANNEL_POST);
	static	void panRight(const unsigned increment = 5, const int channel = MIX_CHANNEL_POST);
	static	void panReset(const int channel = MIX_CHANNEL_POST);
	static	void panSet(const int amount, const int channel = MIX_CHANNEL_POST);
	static	void quit();
	
private: // Methods.
	SoundManager();
	SoundManager(const SoundManager&);
	~SoundManager();
	
private: // Properties.
	static SoundManager* s_pInstance;
	static	std::map<std::string, Mix_Chunk*> m_sfxs;
	static	std::map<std::string, Mix_Music*> m_music;
	static int m_pan; // A slider value from 0 to 100. 0 = full left, 100 = full right.
	
};
typedef SoundManager SOMA;
#endif /* defined (__SOUND_MANAGER__) */