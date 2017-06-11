///******************************************************************************/
///*!
// \file   SoundSystem.c
// \proj   Dark Rising
// \author Jesus Herrera
// \par    Course: GAM150
// \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
// \brief  Debugging System defined
// */
///******************************************************************************/

#ifndef SOUNDSYSTEM_H
#define SOUNDSYSTEM_H

#include "fmod.hpp"

enum SOUND_LIST
{
	SOUND_1 = 0,
  SOUND_SPLASH,
  SOUND_SPLASH_DROP,
  SOUND_GUN,
  SOUND_BUTTON_CLICK,
  SOUND_BUTTON_HOVER,
  SOUND_MAINMENU_MUSIC,
  SOUND_PLACING_BARRICADE,
  SOUND_PLACING_SPIKE,
  SOUND_PLACING_ERROR,
  SOUND_PLACING_DELETE,
  SOUND_GAME_MUSIC,
	SOUND_END
};

/*extern FMOD_RESULT  Result;
extern FMOD_SYSTEM  *System;
extern FMOD_SOUND   *Sound[SOUND_END];
extern FMOD_CHANNEL *Channel[SOUND_END];
extern FMOD_BOOL    Playing[SOUND_END];
extern FMOD_BOOL    Paused[SOUND_END];
extern float        Volume[SOUND_END];*/
static FMOD_RESULT  Result;
static FMOD_SYSTEM  *System;
static FMOD_SOUND   *Sound[SOUND_END];
static FMOD_CHANNEL *Channel[SOUND_END];
static FMOD_BOOL    Playing[SOUND_END];
static FMOD_BOOL    Paused[SOUND_END];
static float        Volume[SOUND_END];

void SoundSystemLoad(void);
int SoundAdd(const char* filePath, const int loopStyle, const unsigned int soundList);
void SoundPlay(const unsigned int soundList);
void SoundPausePlay(const unsigned int soundList);
void SoundStop(const unsigned int soundList);
int SoundIsPlaying(const unsigned int soundList);
void SetVolume(const unsigned int soundList, float volume);
float GetVolume(const unsigned int soundList);
void SoundSystemExit(void);
void SoundUpdate (void);

#endif