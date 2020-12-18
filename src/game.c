#include "../include/game.h"

Game* GAME_Init(const char* title, int width, int height, bool fullscreen)
{
	int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

	LOG_INFO("Initializing game: %s", title);

	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		LOG_SDL_CRITICAL(ERRCODE_SDL_SUBSYS_INIT_FAILED);
	}

	LOG_SUCCESS("SDL subsystems initialized");

	// create window and check for nullptr
	SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags | SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		LOG_SDL_CRITICAL(ERRCODE_SDL_WINDOW_INIT_FAILED);
	}

	LOG_SUCCESS("SDL window initialized");

	// create renderer and check for nullptr
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
	{
		LOG_SDL_CRITICAL(ERRCODE_SDL_RENDER_INIT_FAILED);
	}

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	LOG_SUCCESS("SDL renderer initialized");


	// initialize texture manager and check for nullptr
	GAME_TextureManager* texmgr = (GAME_TextureManager*)malloc(sizeof(struct GAME_TextureManager));
	if (texmgr == NULL)
	{
		LOG_CRITICAL(ERRCODE_GAME_TEXMGR_MALLOC, "Texture manager memory allocation failed");
	}

	texmgr->dict = dict_alloc();
	texmgr->renderer = renderer;

	// initialize game struct
	Game* game = (Game*)malloc(sizeof(Game));
	if (game == NULL)
	{
		LOG_CRITICAL(ERRCODE_GAME_MALLOC, "Game memory allocation failed");
	}

	game->isRunning = true;
	game->renderer = renderer;
	game->window = window;
	game->textureManager = texmgr;

	LOG_INFO("Game running");

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

	SDL_Rect rect = { 5, 5, 50, 50 };
	TEXMGR_Draw(game->textureManager, "assets:placeholder", &rect);

	SDL_RenderPresent(game->renderer);
}

void GAME_Clean(Game* game)
{
	// clean SDL (window, renderer)

	SDL_DestroyWindow(game->window);
	LOG_SUCCESS("SDL window destroyed");

	SDL_DestroyRenderer(game->renderer);
	LOG_SUCCESS("SDL renderer destroyed");

	SDL_Quit();
	LOG_SUCCESS("SDL initialized subsystems cleaned");

	LOG_INFO("Game cleaned");
}
