#ifndef KC_CORE_H_
#define KC_CORE_H_

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif // !ENABLE_VIRTUAL_TERMINAL_PROCESSING

namespace kc
{
	namespace core
	{
		// the seed in srand()
		static unsigned int kc_seed;
		// Sets the Console so that color and other escape codes are enabled.
		void enable_console_color(void);
		// Sets visibility of the cursor. Visible has a range of 0-100, 0 = invisible, 100 = full block space.
		void resize_cursor(unsigned int visible);
		// Runs various setup functions such as enableConsoleColor().
		void setup_kc_lib(void);
	}
}

#endif // !KC_CORE_H_