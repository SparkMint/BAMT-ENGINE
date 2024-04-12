#ifndef BAMT_DEBUG
#define BAMT_DEBUG

#include "windows.h"

#include <iostream>
#include <sstream>

namespace Debug
{
	#pragma region LogDeclarations
	/// <summary>
	/// Logs information on the console.
	/// </summary>
	void Log(std::string output);
	void Log(std::string output, void* pointer);

	void ToggleLogs();
	#pragma endregion LogDeclarations

	#pragma region WarnDeclarations
	/// <summary>
	/// Logs a warning on the console.
	/// </summary>
	void LogWarn(std::string output);
	void LogWarn(std::string output, void* pointer);

	void ToggleWarns();

	#pragma endregion WarnDeclarations

	#pragma region ErrorDeclarations
	/// <summary>
	/// Logs a error on the console.
	/// </summary>
	void LogError(std::string output);
	void LogError(std::string output, void* pointer);

	void ToggleErrors();
	#pragma endregion ErrorDeclarations

	#pragma region LogExtras
	/// <summary>
	/// Returns the current currentTimeSeconds as a string.
	/// </summary>
	/// <returns>Format: [YEAR-MONTH-DAY HOUR:MINUTE:SECOND]</returns>
	std::string GetTime();

	std::string GetPointerAddress(void* pointer);

	/// <summary>
	/// Changes the colour of text.
	/// </summary>
	/// <param name="colour">The colour to change it into.</param>
	void SetColour(int colour);
	#pragma endregion LogExtras

	#pragma region CommandInputs
	/// <summary>
	/// Creates a new thread that handles console inputs.
	/// </summary>
	void CreateCommandThread();

	/// <summary>
	/// Stops a Command Thread after the program is finished.
	/// </summary>
	void StopCommandThread();

	/// <summary>
	/// Called to get commands from the user.
	/// </summary>
	int ConsoleGetCommandInput(void* data);
	#pragma endregion CommandInputs
}
#endif