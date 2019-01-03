#include "kc_core.h"
#include <Windows.h>
#include <ctime>

HANDLE kc_stdout;
void kc::core::enable_console_color()
{
	DWORD dw_mode = 0;
	GetConsoleMode(kc_stdout, &dw_mode);
	dw_mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(kc_stdout, dw_mode);
}
void kc::core::resize_cursor(const unsigned int visible)
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = visible ? visible : 10;
	info.bVisible = visible ? 1 : 0;
	SetConsoleCursorInfo(kc_stdout, &info);
}
void kc::core::setup_kc_lib()
{
	kc_stdout = GetStdHandle(STD_OUTPUT_HANDLE);
	kc::core::kc_seed = static_cast<unsigned int>(time(nullptr));
	srand(kc::core::kc_seed);
	kc::core::enable_console_color();
}