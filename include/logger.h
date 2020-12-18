#pragma once

#include "SDL_error.h"

/// <summary>
///  Log an informative message to the standard output
/// </summary>
#define LOG_INFO(fmt, ...)				printf("\x1b[38;5;7minfo:\x1b[0m    " fmt "\n", __VA_ARGS__)

/// <summary>
///  Log a debug message to the standard output
/// </summary>
#define LOG_DEBUG(fmt, ...)				printf("\x1b[38;5;7mdebug:\x1b[0m   " fmt "\n", __VA_ARGS__)

/// <summary>
///  Log a warning message to the standard output
/// </summary>
#define LOG_WARNING(fmt, ...)			printf("\x1b[38;5;11mwarning:\x1b[0m " fmt "\n", __VA_ARGS__)

/// <summary>
///  Log a success message to the standard output
/// </summary>
#define LOG_SUCCESS(fmt, ...)			printf("\x1b[38;5;10msuccess:\x1b[0m " fmt "\n", __VA_ARGS__)

/// <summary>
///  Log an error message to the standard output
/// </summary>
#define LOG_ERROR(fmt, ...)				printf("\x1b[38;5;9merror:\x1b[0m   " fmt "\n", __VA_ARGS__)

/// <summary>
///  Log an error message to the standard output and exit the program with a certain error code
/// </summary>
#define LOG_CRITICAL(errCode, fmt, ...)	printf("\x1b[38;5;9merror:\x1b[0m   " fmt "\n", __VA_ARGS__); exit(errCode)

/// <summary>
///  Log the last SDL error to the standard output
/// </summary>
#define LOG_SDL_ERROR()					LOG_ERROR("%s", SDL_GetError())

/// <summary>
///  Log the last SDL error to the standard output and exit the program with a certain error code
/// </summary>
#define LOG_SDL_CRITICAL(errCode)		LOG_CRITICAL(errCode, "%s", SDL_GetError());