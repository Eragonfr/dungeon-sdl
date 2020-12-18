#include "../include/texmgr.h"

int TEXMGR_Load(GAME_TextureManager* mgr, const char* id, const char* file)
{
	// create surface and check for nullptr
	SDL_Surface* surface = IMG_Load(file);
	if (surface == NULL)
	{
		LOG_SDL_ERROR();
		return;
	}

	// create texture from surface and check for nullptr
	SDL_Texture* tex = SDL_CreateTextureFromSurface(mgr->renderer, surface);
	if (tex == NULL)
	{
		LOG_SDL_ERROR();
		return;
	}

	dict_addItem(mgr->dict, id, tex);

	LOG_INFO("Texture loaded: %s (from %s)", id, file);

	SDL_FreeSurface(surface);

	return 1;
}

SDL_Texture* TEXMGR_Get(GAME_TextureManager* mgr, const char* id)
{
	return (SDL_Texture*)dict_getItem(*mgr->dict, id);
}

void TEXMGR_Drop(GAME_TextureManager* mgr, const char* id)
{
	dict_delItem(mgr->dict, id);
}

void TEXMGR_Clean(GAME_TextureManager* mgr)
{
	dict_free(mgr->dict);
	free(mgr);
}

void TEXMGR_Draw(GAME_TextureManager* mgr, const char* id, SDL_Rect* rect)
{
	SDL_Texture* tex = TEXMGR_Get(mgr, id);
	SDL_RenderCopy(mgr->renderer, tex, NULL, rect);
}

char* filePathToTextureId(char* fname, bool folderAsPrefix, const char* pathDelimiter)
{
	char* texId = (char*)malloc(MAX_TEX_ID_SIZE);
	if (texId == NULL) 
	{ 
		// todo: errcode
		return NULL; 
	}

	int offset = 0;
	// extract folder name and set as prefix
	if (folderAsPrefix)
	{
		// to avoid replacement by strtok
		char* tempFname = (char*)malloc(strlen(fname) + 1);
		if (tempFname == NULL)
		{
			// todo: errcode
			return NULL;
		}

		strcpy(tempFname, fname);

		// get folder name and format as <root>:
		char* texIdPrefix = strtok(tempFname, pathDelimiter);
		sprintf(texId, "%s:", texIdPrefix);
		
		offset += strlen(texIdPrefix) + 1;
	}

	// get last path item (e.g real file name)
	char* lastPathItem = strrchr(fname, '\\') + 1;
	if (lastPathItem == NULL)
	{
		// todo: errcode
		return;
	}

	int lastPathItemLength = strlen(lastPathItem);

	// replace special chars by an underscore
	// remove extension
	// write to texId
	for (size_t i = 0; i < lastPathItemLength && lastPathItem[i] != '.'; i++)
	{
		char ch = lastPathItem[i];
		// if ch is not a letter and not a number and not an underscore, then this ch isn't allowed
		if (!(ch >= 'a' && ch <= 'z') && !(ch >= 'A' && ch <= 'Z') && !(ch >= '0' && ch <= '9') && ch != '_')
		{
			ch = '_';
		}

		texId[offset++] = ch;
	}

	texId[offset] = '\0';

	return texId;
}
