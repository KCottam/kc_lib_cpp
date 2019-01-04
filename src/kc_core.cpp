#include "kc_core.h"
#include <Windows.h>
#include <ctime>

HANDLE kcStdout;

void KC::Core::EnableConsoleColor()
{
	DWORD dwMode = 0;
	GetConsoleMode(kcStdout, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(kcStdout, dwMode);
}

void KC::Core::ResizeCursor(const unsigned int visible)
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = visible ? visible : 10;
	info.bVisible = visible ? 1 : 0;
	SetConsoleCursorInfo(kcStdout, &info);
}

void KC::Core::SetupKCLib()
{
	kcStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	randomizationSeed = static_cast<unsigned int>(time(nullptr));
	srand(randomizationSeed);
	EnableConsoleColor();
}
