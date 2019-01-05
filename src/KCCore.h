#ifndef KC_CORE_H_
#define KC_CORE_H_

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif // !ENABLE_VIRTUAL_TERMINAL_PROCESSING

namespace KC
{
	static struct Core final
	{
		static unsigned int RandomizationSeed;
		static void EnableConsoleColor();
		static void ResizeCursor(unsigned int visible);
		static void SetupKCLib();
	} core;
}


#endif // !KC_CORE_H_
