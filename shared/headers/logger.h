#ifndef logger_h
#define logger_h

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>

/// <summary>
///  Write an information to the standard output.
/// </summary>
/// <param name="format">C string that contains the text to be written to stdout</param>
/// <returns>Number of chars written.</returns>
int LOGGER_LogInformation(const char* format, ...);

/// <summary>
///  Write a debug message to the standard output.
/// </summary>
/// <param name="format">C string that contains the text to be written to stdout</param>
/// <returns>Number of chars written.</returns>
int LOGGER_LogDebug(const char* format, ...);

/// <summary>
///  Write a error message to the standard output.
/// </summary>
/// <param name="format">C string that contains the text to be written to stdout</param>
/// <returns>Number of chars written.</returns>
int LOGGER_LogError(const char* format, ...);

/// <summary>
///  Write a error message to the standard output and exits the program with a certain error code.
/// </summary>
/// <param name="errCode">Error code to return if an error occurs</param>
/// <param name="format">C string that contains the text to be written to stdout</param>
void LOGGER_LogErrorAndExit(const int errCode, const char* format, ...);

/// <summary>
///  Write a warning message to the standard output.
/// </summary>
/// <param name="format">C string that contains the text to be written to stdout</param>
/// <returns>Number of chars written.</returns>
int LOGGER_LogWarning(const char* format, ...);

/// <summary>
///  Write a success message to the standard output.
/// </summary>
/// <param name="format">C string that contains the text to be written to stdout</param>
/// <returns>Number of chars written.</returns>
int LOGGER_LogSuccess(const char* format, ...);

/// <summary>
///  Write an error message to the standard output if a target pointer is null.
/// </summary>
/// <param name="target">Target pointer</param>
/// <param name="format">C string that contains the text to be written to stdout</param>
/// <returns>Number of chars written. Since it only writes when an error occured, if this function returns 0, means target isn't a null pointer.</returns>
int LOGGER_LogErorrIfNull(const void* target, const char* format, ...);

/// <summary>
///  Write an error message to the standard output if a target pointer is null. If an error occured (e.g is the pointer is null), exits the program with a certain error code.
/// </summary>
/// <param name="target">Target pointer</param>
/// <param name="errCode">Error code to return if an error occurs</param>
/// <param name="format">C string that contains the text to be written to stdout</param>
/// <returns>Number of chars written. Since it only writes when an error occured, if this function returns 0, means target isn't a null pointer.</returns>
int LOGGER_LogErrorIfNullAndExit(const void* target, const int errCode, const char* format, ...);

/// <summary>
///  Write an error message message to the standard output if a target pointer is null. If an error occured (e.g is the pointer is null), exits the program with a certain error code. If there is no error, write a success message.
/// </summary>
/// <param name="target">Target pointer</param>
/// <param name="errCode">Error code to return if an error occurs</param>
/// <param name="successMessage">Message to write if no error occurs</param>
/// <param name="errorMessage">Message to write if an error occurs</param>
/// <returns>Number of chars written. Since it only writes when an error occured, if this function returns 0, means target isn't a null pointer.</returns>
int LOGGER_HandleNullPtr(const void* target, const int errCode, const char* successMessage, const char* errorMessage);
#endif // !logger_h