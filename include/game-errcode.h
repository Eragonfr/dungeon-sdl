#ifndef game_errcode_h
#define game_errcode_h

/// <summary>
///  Error code used when the initalialization of SDL fails
/// </summary>
#define GAME_ERR_SDL_INIT		     1

/// <summary>
///  Error code used when the creation of SDL window fails
/// </summary>
#define GAME_ERR_SDL_CREATE_WINDOW   2

/// <summary>
///	 Error code used when the creation of SDL renderer fails
/// </summary>
#define GAME_ERR_SDL_CREATE_RENDERER 3

/// <summary>
///	 Error code used when the memory allocation for the game returns a null pointer
/// </summary>
#define GAME_ERR_GAME_MALLOC		 4

/// <summary>
///	 Error code used when the memory allocation for the texture manager returns a null pointer
/// </summary>
#define GAME_ERR_TEXMGR_MALLOC 5

#endif