#ifndef KC_CORE_H_
#define KC_CORE_H_
#include <Windows.h>
#include <ctime>

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif // !ENABLE_VIRTUAL_TERMINAL_PROCESSING

namespace KC
{
	static class
	{
		HANDLE KCStdout;
	public:
		unsigned int RandomizationSeed;
		void EnableConsoleColor() const
		{
			DWORD dwMode = 0;
			GetConsoleMode(KCStdout, &dwMode);
			dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
			SetConsoleMode(KCStdout, dwMode);
		}

		void ResizeCursor(const unsigned int visible) const
		{
			CONSOLE_CURSOR_INFO info;
			info.dwSize = visible ? visible : 10;
			info.bVisible = visible ? 1 : 0;
			SetConsoleCursorInfo(KCStdout, &info);
		}

		void SetupKCLib()
		{
			KCStdout = GetStdHandle(STD_OUTPUT_HANDLE);
			RandomizationSeed = static_cast<unsigned int>(time(nullptr));
			srand(RandomizationSeed);
			EnableConsoleColor();
		}
	} core;
}


#endif // !KC_CORE_H_
