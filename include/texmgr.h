#pragma once

#include "SDL_image.h"

#include "game.h"
#include "logger.h"
#include "dict.h"

typedef struct GAME_TextureManager
{
	//dict_t** dict;
	SDL_Renderer* renderer;
} GAME_TextureManager;

int TEXMGR_Load(GAME_TextureManager* mgr, const char* id, const char* fname);

void TEXMGR_Drop(GAME_TextureManager* mgr, const char* id);

void TEXMGR_Clean(GAME_TextureManager* mgr);

void TEXMGR_Draw(GAME_TextureManager* mgr, const char* id, SDL_Rect dst);