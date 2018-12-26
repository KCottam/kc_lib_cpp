#ifndef KC_CORE_H_
#define KC_CORE_H_

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif // !ENABLE_VIRTUAL_TERMINAL_PROCESSING

namespace kc
{
	namespace core
	{
		//the seed in srand()
		static unsigned int kc_seed;
		//Sets the Console so that color and other escape codes are enabled.
		void enableConsoleColor(void);
		//Sets visibility of the cursor. Visible has a range of 0-100, 0 = invisible, 100 = full block space.
		void resizeCursor(unsigned int visible);
		//NEEDS TO BE DEFINED AS REPLACEMENT TO MAIN FUNCTION
		extern int kc_main(int argc, char * argv[]);
	}
}
//kc_lib replaces main and runs some commands before running the user main function. User must define kc_main instead of main.
int main(int argc, char * argv[]);

#endif // !KC_CORE_H_