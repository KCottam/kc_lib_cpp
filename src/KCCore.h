#ifndef KC_CORE_H_
#define KC_CORE_H_

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif // !ENABLE_VIRTUAL_TERMINAL_PROCESSING

namespace KC
{
	struct Core final
	{
		static unsigned int RandomizationSeed;
		static auto EnableConsoleColor() -> void;
		static auto ResizeCursor(unsigned int visible) -> void;
		static auto SetupKCLib() -> void;
	};
}


#endif // !KC_CORE_H_
