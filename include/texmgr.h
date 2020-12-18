#pragma once

#include "SDL_image.h"

#include "game.h"
#include "logger.h"
#include "dict.h"

#define MAX_TEX_ID_SIZE			256
#define TEX_ID_PREFIX_DELIMITER ":"

/// <summary>
///  Struct which represents a texture manager in a game
/// </summary>
typedef struct GAME_TextureManager
{
	/// <summary>
	///  Pointer to the texture registry
	/// </summary>
	dict_t** dict;

	/// <summary>
	///  Pointer to the SDL renderer
	/// </summary>
	SDL_Renderer* renderer;
} GAME_TextureManager;

/// <summary>
///  Load a texture to a texture manager
/// </summary>
/// <param name="mgr">Target texture manager</param>
/// <param name="id">Target texture id</param>
/// <param name="fname">File path</param>
/// <returns>If the texture was loaded, returns 1. Otherwise, returns 0</returns>
int TEXMGR_Load(GAME_TextureManager* mgr, char* id, const char* fname);

/// <summary>
///  Get a texture from a texture manager
/// </summary>
/// <param name="id">Target texture id</param>
/// <returns>Stored image with the corresponding id</returns>
SDL_Texture* TEXMGR_Get(GAME_TextureManager* mgr, char* id);

/// <summary>
///  Drop an image from a texture manager
/// </summary>
/// <param name="mgr">Target texture manager</param>
/// <param name="id">Target texture id</param>
void TEXMGR_Drop(GAME_TextureManager* mgr, char* id);

/// <summary>
///  Clean the texture manager
/// </summary>
/// <param name="mgr">Target texture manager</param>
void TEXMGR_Clean(GAME_TextureManager* mgr);

/// <summary>
///  Clean the texture manager
/// </summary>
/// <param name="mgr">Target texture manager</param>
/// <param name="id">Target texture id</param>
/// <param name="rect">Destination rect</param>
void TEXMGR_Draw(GAME_TextureManager* mgr, char* id, SDL_Rect* rect);

/// <summary>
///  Convert a filename to a valid texture id
/// </summary>
/// <param name="fname">Target file name</param>
/// <param name="folderAsPrefix">If true, add the folder name as a prefix to the texture id (assets:tex)</param>
/// <param name="pathDelimiter">Path delimiter</param>
/// <returns>Texture id</returns>
char* filePathToTextureId(char* fname, bool folderAsPrefix, const char* pathDelimiter);
