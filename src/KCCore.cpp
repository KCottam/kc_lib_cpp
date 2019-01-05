#include "KCCore.h"
#include <Windows.h>
#include <ctime>

HANDLE KCStdout;

void KC::Core::EnableConsoleColor()
{
	DWORD dwMode = 0;
	GetConsoleMode(KCStdout, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(KCStdout, dwMode);
}

void KC::Core::ResizeCursor(const unsigned int visible)
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = visible ? visible : 10;
	info.bVisible = visible ? 1 : 0;
	SetConsoleCursorInfo(KCStdout, &info);
}

void KC::Core::SetupKCLib()
{
	KCStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	RandomizationSeed = static_cast<unsigned int>(time(nullptr));
	srand(RandomizationSeed);
	EnableConsoleColor();
}