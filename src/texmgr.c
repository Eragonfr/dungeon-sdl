#include "../include/texmgr.h"

int TEXMGR_Load(GAME_TextureManager* mgr, const char* id, const char* file)
{
	// create surface and check for nullptr
	SDL_Surface* surface = IMG_Load(file);
	if (!surface)
	{
		// todo: errcode surface creation
		LOG_SDL_CRITICAL(-1);
	}

	// create texture from surface and check for nullptr
	
	SDL_Texture* tex = SDL_CreateTextureFromSurface(mgr->renderer, surface);
	if (!tex)
	{
		// todo: errcode tex creation
		LOG_SDL_CRITICAL(-1);
	}

	//dict_addItem(mgr->dict, id, tex);

	SDL_FreeSurface(surface);

	return 1;
}

void TEXMGR_Drop(GAME_TextureManager* mgr, const char* id)
{
	//dict_delItem(mgr->dict, id);
}

void TEXMGR_Clean(GAME_TextureManager* mgr)
{
	//dict_free(mgr->dict);
	//free(mgr);
}

void TEXMGR_Draw(GAME_TextureManager* mgr, const char* id, SDL_Rect dst)
{
}
