/////////////////////////////////////////////////////////////////////////////
Contents:
kc_lib_cpp Project Overview
kc_core Module Overview
kc_colors Module Overview
kc_controller Module Overview
Other notes
CHANGELOG
/////////////////////////////////////////////////////////////////////////////
========================================================================
	STATIC LIBRARY : kc_lib_cpp Project Overview (Version 1.0.1)
========================================================================

kc_core.h, kc_core.cpp
	Contains core setup functions as well as the wrapper definition.

kc_colors.h
	Contains color functions and defines.

kc_controller.h, kc_controller.cpp
	Contains controller functions and defines.

TODO: kc_gui
TODO: kc_gui_controls
TODO: kc_lists
TODO: kc_dlists
TODO: kc_multithreading

========================================================================
	MODULES: kc_core Module Overview
========================================================================

Holds many functions for running the wrapper that is kc_lib_cpp.

kc::core::kc_seed
	This is the number value used to seed the random function srand().

kc::core::enableConsoleColor(void)
	This is a function that enables use of colors in the terminal.

kc::core::resizeCursor(unsigned int)
	This is a function that changes the cursor size from 0% to 100%. Used in games 
	where I do not allow a cursor.

kc::core::kc_main(int,*char[])
	This is the library wrapper's main function, the one that the user calls instead
	of main().

main(int,*char[])
	This is the entry point of the program. It runs commands such as kc::core::enableConsoleColor()
	and sets the value of kc::core::kc_seed. Runs kc::core::kc_main().

========================================================================
	MODULES: kc_colors Module Overview
========================================================================

Has text color and style definitions. Also has console manipulation functions and defines.

kc::colors::
	Has const char * variables for various colors.

kc::formatting::
	Has const char * variables for manipulating the console output.

kc::highlights::
	Has const char * variables for various highlights.

kc::styles::
	Has const char * variables for various font styles such as bold.

========================================================================
	MODULES: kc_controller Module Overview
========================================================================

Has functions for getting user input.

kc::controller::FlagCodes
	The inputted flag variable becomes one of these when using get_key().

kc::controller::KeyCodes
	Has outputs for get_key().
	
kc::controller::get_key(*int,int)
	Gets a key that a user presses and returns it. Similar to _getch(), but modified.
	The second parameter is a delay in ms. Use 0 for no delay.

/////////////////////////////////////////////////////////////////////////////
Other notes:

I use "TODO:" comments to indicate parts of the source code I am planning to add to or customize.

/////////////////////////////////////////////////////////////////////////////
CHANGELOG 1.0.1
	Edited TO_UPPER and TO_LOWER to be in-line functions instead of constants. 
		They check to see if a character is uppercase or lowercase before doing their function.
	Moved character codes from kc_controller.h into a class so it is more organized.
	Realigned some things to test out visual studio add-on and  to make things look neater
	Added function overloads for toUpper() and toLower for strings.

CHANGELOG 1.0.0
	Added kc_core module
	Added kc_colors module
	Added kc_controller module