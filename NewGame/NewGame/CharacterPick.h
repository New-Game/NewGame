/**
 * Project:      NewGame
 * File Name:    CharacterPick.h
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      人物选择类头文件
 */

#pragma once

#include "GameState.h"
#include "System.h"

using namespace std;

// 人物选择类，单实例类
class CharacterPick : public GameState {
public:
	CharacterPick() {
		for (int i = 0; i < NUM_OF_CHARACTERS; ++i) {
			mesh_[i] = nullptr;
			texture_[i] = nullptr;
		}
		picture_[EMILIA] = "picture\\emilia_large.png";
		picture_[REM] = "picture\\rem_large.png";
		picture_[RAM] = "picture\\ram_large.png";
		picture_[FILLIS] = "picture\\fillis_large.png";
		picture_[FELT] = "picture\\felt_large.png";
	}

	~CharacterPick() {}

	void Load() override;

	void Reset() override;

	void Process() override;

	void Unload() override;

private:
	enum CharacterNames {
		EMILIA,
		REM,
		RAM,
		FILLIS,
		FELT,
		NUM_OF_CHARACTERS
	};

	string picture_[NUM_OF_CHARACTERS];
	AEGfxVertexList* mesh_[NUM_OF_CHARACTERS];
	AEGfxTexture* texture_[NUM_OF_CHARACTERS];
};
