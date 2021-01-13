#include "game.h"

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

#define FPS					60
#define FRAME_DELAY 1000 / FPS

int main(int argc, char** argv)
{
	unsigned int frameStart;
	int frameTime;

	Game* game = GAME_Init("Jeu incroyable", WINDOW_WIDTH, WINDOW_HEIGHT, false);
	GAME_ImportAssetsAll(game, "assets");

	while (game->isRunning)
	{
		frameStart = SDL_GetTicks();

		GAME_HandleEvents(game);

		GAME_Update(game);

		GAME_Render(game);

		frameTime = SDL_GetTicks() - frameStart;
		if (FRAME_DELAY > frameTime)
		{
			SDL_Delay(FRAME_DELAY - frameTime);
		}
	}

	GAME_Clean(game);

	return 0;
}
