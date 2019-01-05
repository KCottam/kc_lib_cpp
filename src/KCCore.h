#ifndef KC_CORE_H_
#define KC_CORE_H_

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif // !ENABLE_VIRTUAL_TERMINAL_PROCESSING

namespace KC
{
	static class Core final
	{
	public:
		unsigned int RandomizationSeed;
		void EnableConsoleColor();
		void ResizeCursor(unsigned int visible);
		void SetupKCLib();
	} core;
}


#endif // !KC_CORE_H_
