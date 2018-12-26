#include "kc_core.h"
#include <Windows.h>
#include <ctime>

HANDLE kc_stdout;
void kc::core::enableConsoleColor(void)
{
	DWORD dwMode = 0;
	GetConsoleMode(kc_stdout, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(kc_stdout, dwMode);
}
void kc::core::resizeCursor(unsigned int visible)
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = visible ? visible : 10;
	info.bVisible = visible ? 1 : 0;
	SetConsoleCursorInfo(kc_stdout, &info);
}
int main(int argc, char * argv[])
{
	kc_stdout = GetStdHandle(STD_OUTPUT_HANDLE);
	kc::core::kc_seed = (unsigned int)time(NULL);
	srand(kc::core::kc_seed);
	kc::core::enableConsoleColor();
	return kc::core::kc_main(argc, argv);
}
