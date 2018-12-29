#include "kc_core.h"
#include <Windows.h>
#include <ctime>

HANDLE kc_stdout;
/// <summary>
/// Enabled color and ANSI escape sequences 
/// </summary>
void kc::core::enableConsoleColor(void)
{
	DWORD dwMode = 0;
	GetConsoleMode(kc_stdout, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(kc_stdout, dwMode);
}
/// <summary>
/// Resizes the cursor of the console window
/// </summary>
/// <param name="visible">A range of 1-100 that determines how much of the area of the box the cursor is in is highlighted.</param>
void kc::core::resizeCursor(unsigned int visible)
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = visible ? visible : 10;
	info.bVisible = visible ? 1 : 0;
	SetConsoleCursorInfo(kc_stdout, &info);
}
/// <summary>
/// Sets up KCLib by assigning handles and setting the random value.
/// </summary>
void kc::core::SetupKCLib(void)
{
	kc_stdout = GetStdHandle(STD_OUTPUT_HANDLE);
	kc::core::kc_seed = (unsigned int)time(NULL);
	srand(kc::core::kc_seed);
	kc::core::enableConsoleColor();
}