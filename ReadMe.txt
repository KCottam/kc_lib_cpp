Name: KCLib
Author: Kace Cottam
Version: 1.1.0

/////////////////////////////////////////////////////////////////////////////
Contents:
Other notes
CHANGELOG
/////////////////////////////////////////////////////////////////////////////
Other notes:

I use "TODO:" comments to indicate parts of the source code I am planning to add to or customize.
I use "BUG:" comments to indicate parts of the source code where there is a bug that needs to be fixed.

/////////////////////////////////////////////////////////////////////////////
CHANGELOG 1.1.1
	Reformatted list length.

CHANGELOG 1.1.0
	Reformatted using ReSharper C++
	TODO: REMAKE kc_lists
	Renamed all files to PascalCase to follow Microsoft coding guidelines.
	Added some operator functions
	Switched to trailing return types for better alignment and thus readability
	Made InputFlag into an enum class

CHANGELOG 1.0.5
	Reformatted kc_lists to use templates.
	Also started using more references and const.

CHANGELOG 1.0.4
	Reformatted kc::controller to use Flag enum for variable.
	FlagCodes->Flag
	KeyCodes->Key
	Made kc::controller::get_key() use reference instead of pointer.

CHANGELOG 1.0.3
	Adds XML Documentation.

CHANGELOG 1.0.2
	Made main() into just a setup function, kc::core::SetupKCLib
	Added beginnings of Lists module.
	Reformatted comments to have a space between the text and the double slashes, 
		so I can differentiate between temporarily commented code and comments.

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