#define _CRT_SECURE_NO_WARNINGS
#include "Debug.h"
#include "SDL.h"

// Text Colour
int WHITE = 15;
int YELLOW = 14;
int RED = 12;
int GREEN = 10;
int GRAY = 6;

namespace Debug 
{
    #pragma region LogFunctions
    bool logsEnabled = true;
    void Log(std::string output)
    {
        if (!logsEnabled) return;
        SetColour(WHITE);
        std::cout << "[" << GetTime() << "]" << " LOG - " << output << std::endl;
    }
    void Log(std::string output, void* pointer)
    {
        if (!logsEnabled) return;
        SetColour(WHITE);
        std::cout << "[" << GetTime() << "]" << " LOG - " << output << " Address: (" << GetPointerAddress(pointer) << ")" << std::endl;
    }
    void ToggleLogs()
    {
        SetColour(GRAY);
        logsEnabled = !logsEnabled;
        std::string showString = logsEnabled ? "ENABLED" : "DISABLED";
        std::cout << "[LOGS " << showString << "]" << std::endl;
        SetColour(WHITE);
    }
    #pragma endregion LogFunctions

    #pragma region WarningFunctions
    bool warningsEnabled = true;
    void LogWarn(std::string output)
    {
        if (!warningsEnabled) return;
        SetColour(YELLOW);
        std::cout << "[" << GetTime() << "]" << " WARN - " << output << std::endl;
        SetColour(WHITE);
    }
    void LogWarn(std::string output, void* pointer)
    {
        if (!warningsEnabled) return;
        SetColour(YELLOW);
        std::cout << "[" << GetTime() << "]" << " WARN - " << output << " Address: (" << GetPointerAddress(pointer) << ")" << std::endl;
        SetColour(WHITE);
    }
    void ToggleWarns()
    {
        SetColour(GRAY);
        warningsEnabled = !warningsEnabled;
        std::string showString = warningsEnabled ? "ENABLED" : "DISABLED";
        std::cout << "[WARNINGS " << showString << "]" << std::endl;
		SetColour(WHITE);
    }
    #pragma endregion WarningFunctions

    #pragma region ErrorFunctions
    bool errorsEnabled = true;
    void LogError(std::string output)
    {
        if (!errorsEnabled) return;

        SetColour(RED);
        std::cout << "[" << GetTime() << "]" << " ERROR - " << output << std::endl;
        SetColour(WHITE);
    }
    void LogError(std::string output, void* pointer)
    {
        if (!errorsEnabled) return;

        SetColour(RED);
        std::cout << "[" << GetTime() << "]" << " ERROR - " << output << " Address: (" << GetPointerAddress(pointer) << ")" << std::endl;
        SetColour(WHITE);
    }
    void ToggleErrors()
    {
        SetColour(GRAY);
        errorsEnabled = !errorsEnabled;
        std::string showString = errorsEnabled ? "ENABLED" : "DISABLED";
        std::cout << "[ERRORS " << showString << "]" << std::endl;
        SetColour(WHITE);
    }
    #pragma endregion ErrorFunctions

    #pragma region LogExtras
    std::string GetTime()
    {
        // TODO: Look into getting this to work without the _CRT_SECURE_NO_WARNINGS flag.
        std::ostringstream outputStream;

        time_t currentTime = time(0);
        struct tm timeStruct;
        char LogTime[80];
        timeStruct = *localtime(&currentTime);
        strftime(LogTime, sizeof(LogTime), "%Y-%m-%d %X", &timeStruct);

        outputStream << LogTime;

        return outputStream.str();
    }

    std::string GetPointerAddress(void* pointer)
    {
        std::ostringstream address;
        address << pointer;
        return address.str();
    }

    void SetColour(int colour)
    {
        HANDLE handle;
        handle = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(handle, colour);
    }
    #pragma endregion LogExtras

    #pragma region CommandFunctions
    SDL_Thread* ConsoleThread;
    void CreateCommandThread()
    {
        Log("Starting Command Input Thread...");
        // Null data to make SDL_CreateThread work.
        constexpr int data = 0;
        ConsoleThread = SDL_CreateThread(Debug::ConsoleGetCommandInput, "Console Thread", reinterpret_cast<void*>(data));
    }
    void StopCommandThread()
    {
        Log("Waiting for Console Thread to finish before closing...");
        SDL_WaitThread(ConsoleThread, nullptr);
        Log("Console Thread Stopped!");
    }
    int ConsoleGetCommandInput(void* data)
    {
        Log("Command Thread Started!");
        // Runs until the Engine Stops running.
        while (true)
        {
            std::string command;
            std::cin >> command;
            Log("Command Entered: " + command);
        }
    }
    #pragma endregion CommandFunctions
}