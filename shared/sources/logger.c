#include "../headers/logger.h"

#define BLACK            0
#define RED              1
#define GREEN            2
#define YELLOW           3
#define BLUE             4
#define MAGENTA          5
#define CYAN             6
#define WHITE            7
#define GRAY             8
#define BRIGHT_BLACK     8
#define BRIGHT_RED       9
#define BRIGHT_GREEN    10
#define BRIGHT_YELLOW   11
#define BRIGHT_BLUE     12
#define BRIGHT_MAGENTA  13
#define BRIGHT_CYAN     14
#define BRIGHT_WHITE    15

int logInternal(char* header, const int headerColor, const char* msg)
{
    return 
        // print colored header
        // there are spaces so no difference with tabs between info and success (header length)
        printf("\x1b[38;5;%dm%s:   \t", headerColor, header) +
        // reset color and print message, reset color again in case the message use ansi sequences too
        printf("\x1b[0m%s\x1b[0m\n", msg);
}

int LOGGER_LogInformation(const char* format, ...)
{
    va_list args;
    char buffer[1024];
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    return logInternal("info", WHITE, buffer);
}

int LOGGER_LogDebug(const char* format, ...)
{
    va_list args;
    char buffer[1024];
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    return logInternal("debug", WHITE, buffer);
}

int LOGGER_LogError(const char* format, ...)
{
    va_list args;
    char buffer[1024];
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    return logInternal("error", BRIGHT_RED, buffer);
}

void LOGGER_LogErrorAndExit(const int errCode, const char* format, ...)
{
    va_list args;
    char buffer[1024];
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    logInternal("error", BRIGHT_RED, buffer);
    exit(errCode);
}

int LOGGER_LogSuccess(const char* format, ...)
{
    va_list args;
    char buffer[1024];
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    return logInternal("success", BRIGHT_GREEN, buffer);
}

int LOGGER_LogWarning(const char* format, ...)
{
    va_list args;
    char buffer[1024];
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    return logInternal("warning", BRIGHT_YELLOW, buffer);
}

int LOGGER_LogErorrIfNull(const void* target, const char* format, ...)
{
    if (target == NULL || target == 0)
    {
        va_list args;
        char buffer[1024];
        va_start(args, format);
        vsnprintf(buffer, sizeof(buffer), format, args);
        va_end(args);

        return LOGGER_LogError(buffer);
    }

    return 0;
}

int LOGGER_LogErrorIfNullAndExit(const void* target, const int errCode, const char* format, ...)
{
    va_list args;
    char buffer[1024];
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    if (LOGGER_LogErorrIfNull(target, buffer) > 0)
    {
        exit(errCode);
    }
}

int LOGGER_HandleNullPtr(const void* target, const int errCode, const char* successMessage, const char* errorMessage)
{
    if (LOGGER_LogErorrIfNull(target, errorMessage) > 0)
    {
        exit(errCode);
    }

    LOGGER_LogSuccess(successMessage);
}
