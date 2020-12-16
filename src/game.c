#include "game.h"

Game* GAME_Init(const char* title, int width, int height)
{
	LOGGER_LogInformation("Initializing game: %s", title);

	// initalize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		LOGGER_LogErrorAndExit(GAME_ERR_SDL_INIT, "SDL initialization failed");
	}

	LOGGER_LogSuccess("SDL initialized");

	/// initialize window
	SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	LOGGER_HandleNullPtr(window, GAME_ERR_SDL_CREATE_WINDOW, "SDL window initialized", "SDL window initialization failed");


	/// initialize renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	LOGGER_HandleNullPtr(renderer, GAME_ERR_SDL_CREATE_RENDERER, "SDL renderer initialized", "SDL renderer initialization failed");

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);


	/// initialize texture manager
	GAME_TextureManager* texmgr = (GAME_TextureManager*)malloc(sizeof(struct GAME_TextureManager));
	LOGGER_HandleNullPtr(texmgr, GAME_ERR_TEXMGR_MALLOC, "Texture manager memory allocated", "Texture manager memory allocation failed");

	// may says that game can be a nullptr but the function LOGGER_HandleNullPtr avoid it
	texmgr->dict = dict_alloc();
	texmgr->renderer = renderer;

	/// initialize game struct
	Game* game = (Game*)malloc(sizeof(Game));
	LOGGER_HandleNullPtr(game, GAME_ERR_GAME_MALLOC, "Game memory allocated", "Game memory allocation failed");

	// may says that game can be a nullptr but the function LOGGER_HandleNullPtr avoid it
	game->isRunning = true;
	game->renderer = renderer;
	game->window = window;
	game->textureManager = texmgr;

	LOGGER_LogInformation("Game running");	

	return game;
}

void GAME_HandleEvents(Game* game)
{
	SDL_Event event;
	SDL_PollEvent(&event);
	
	switch (event.type)
	{
	case SDL_QUIT:
		game->isRunning = false;
		break;
	}
}

void GAME_Update(Game* game)
{
}

void GAME_Render(Game* game)
{
	SDL_RenderClear(game->renderer);

	SDL_RenderPresent(game->renderer);
}

void GAME_Clean(Game* game)
{
	SDL_DestroyWindow(game->window);
	LOGGER_LogSuccess("SDL window destroyed");

	SDL_DestroyRenderer(game->renderer);
	LOGGER_LogSuccess("SDL renderer destroyed");

	SDL_Quit();
	LOGGER_LogSuccess("SDL initialized subsystems cleaned");

	LOGGER_LogSuccess("Game cleaned");
}
