#pragma once

#include "SDL_error.h"

#define LOG_INFO(fmt, ...)				printf("\x1b[38;5;7minfo:\x1b[0m    " fmt "\n", ##__VA_ARGS__)
#define LOG_DEBUG(fmt, ...)				printf("\x1b[38;5;7mdebug:\x1b[0m   " fmt "\n", ##__VA_ARGS__)
#define LOG_WARNING(fmt, ...)			printf("\x1b[38;5;11mwarning:\x1b[0m " fmt "\n", ##__VA_ARGS__)
#define LOG_SUCCESS(fmt, ...)			printf("\x1b[38;5;10msuccess:\x1b[0m " fmt "\n", ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...)				printf("\x1b[38;5;9merror:\x1b[0m   " fmt "\n", ##__VA_ARGS__)
#define LOG_CRITICAL(errCode, fmt, ...)	printf("\x1b[38;5;9merror:\x1b[0m   " fmt "\n", ##__VA_ARGS__); exit(errCode)

#define LOG_SDL_ERROR()					LOG_ERROR("%s", SDL_GetError())
#define LOG_SDL_CRITICAL(errCode)		LOG_CRITICAL(errCode, "%s", SDL_GetError());
