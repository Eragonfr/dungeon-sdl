#ifndef game_h
#define game_h

#include <stdio.h>
#include <stdbool.h>

#include "SDL.h"
#include "SDL_image.h"

#include "game-errcode.h"
#include "texmgr.h"
#include "logger.h"

typedef struct GAME_TextureManager GAME_TextureManager;

/// <summary>
///  Struct which represents a game instance
/// </summary>
typedef struct Game
{
	/// <summary>
	///  Represent if the game is currently running or not. Setting it to false stops the game. Note that setting it to true doesn't start or restart the game.
	/// </summary>
	bool isRunning;

	/// <summary>
	///  Pointer to the SDL window
	/// </summary>
	SDL_Window* window;

	/// <summary>
	///  Pointer to the SDL renderer
	/// </summary>
	SDL_Renderer* renderer;

	/// <summary>
	///  Pointer to the texture manager
	/// </summary>
	GAME_TextureManager* textureManager;
} Game;

/// <summary>
///  Initiliaze a game instance with SDL
/// </summary>
/// <param name="title">Title of the window</param>
/// <param name="width">Width of the window</param>
/// <param name="height">Height of the window</param>
/// <returns>If initialization succeeded, returns a pointer to a Game. Otherwhise returns NULL.</returns>
Game* GAME_Init(const char* title, int width, int height);

/// <summary>
///  Handle events
/// </summary>
/// <param name="game">Target game</param>
void GAME_HandleEvents(Game* game);

/// <summary>
///  Update the game
/// </summary>
/// <param name="game">Target game</param>
void GAME_Update(Game* game);

/// <summary>
///  Render the game
/// </summary>
/// <param name="game">Target game</param>
void GAME_Render(Game* game);

/// <summary>
///  Clean the game
/// </summary>
/// <param name="game">Target game</param>
void GAME_Clean(Game* game);

/// <summary>
///  Import all files as texture assets from dirs with a certain filter
/// </summary>
/// <param name="game">Target game</param>
/// <param name="filter">Filter</param>
/// <param name="dir">Target directory</param>
int GAME_ImportAssetsAll(Game* game, const char* dir, const char* filter);

#endif // !game_h
