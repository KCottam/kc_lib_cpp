/////////////////////////////////////////////////////////////////////////////
Contents:
kc_lib_cpp Project Overview
kc_core Module Overview
kc_colors Module Overview
kc_controller Module Overview
kc_lists Module Overview
Other notes
CHANGELOG
/////////////////////////////////////////////////////////////////////////////
========================================================================
	STATIC LIBRARY : kc_lib_cpp Project Overview (Version 1.0.4)
========================================================================

kc_core.h, kc_core.cpp
	Contains core setup functions as well as the wrapper definition.

kc_colors.h
	Contains color functions and defines.

kc_controller.h, kc_controller.cpp
	Contains controller functions and defines.

kc_lists.h, kc_lists.cpp
	Contains list classes and functions.

TODO: kc_gui
TODO: kc_gui_controls
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

kc::core::SetupKCLib(void)
	This runs commands such as kc::core::enableConsoleColor()
	and sets the value of kc::core::kc_seed.

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
	
kc::controller::get_key(Flag&, time_t)
	Gets a key that a user presses and returns it. Similar to _getch(), but modified.
	The second parameter is a delay in ms. Use 0 for no delay.

kc::controller::toUpper(char), kc::controller::toUpper(char *)
	Capitalizes a string or char.

kc::controller::toLower(char), kc::controller::toLower(char *)
	Lowercases a string or char.

========================================================================
	MODULES: kc_lists Module Overview
========================================================================

Has classes and functions for making linked lists of generic data.

kc::Node
	A class for each node of a linked lists.

	Private:
	kc::Node::data
		Data of each node
	kc::Node::next
		The next node of the linked list. Is 0 if there is no next node.
	kc::Node::previous
		The previous node of the linked list. Is 0 if there is no previous node.

	Public:
	kc::Node::Node(void), kc::Node::Node(*void)
		Initializes a node. If data is specified, then makes the node with that data.
	kc::Node::getData(void)
		Returns the data of a node.
	kc::Node::setData(void*)
		Sets the data of a node.
	kc::Node::getNext(void)
		Gets the next node of the linked list.
	kc::Node::setNext(*kc::Node)
		Sets the next node of the linked list. Have caution so memory isn't wasted!
	kc::Node::getPrevious(void)
		Gets the previous node of the linked list.
	kc::Node::SetPrevious(*kc::Node)
		Sets the previous node of the linked list. Have caution so memory isn't wasted!
	kc::Node::~Node(void)
		Does nothing.

kc::List
	A class for a linked list.

	Private:
	kc::List::header
		The header node of a linked list.

	Public:
	kc::List::List(void), kc::List::List(*void), kc::List::List(int, *void[])
		Initializes a linked list with any values given. int is for how many values are being initialized.
	kc::List::getHeader(void)
		Retrieves the header of the linked list.
	kc::List::length(void)
		Gets the length of the linked list.
	kc::List::push(*void), kc::List::push(int,*void[])
		Adds new data to the linked list at the beginning of it.
	kc::List::append(*void), kc::List::append(int, *void[])
		Adds new data to the linked list at the end of it.
	kc::List::push_at(int, *void), kc::List::push_at(int, int, *void[])
		Adds new data to the linked list at the index of the first parameter.
	kc::List::pull(void)
		Deletes the first node of the linked list and returns the data inside of it.
	kc::List::pop(void)
		Deletes the last node of the linked list and returns the data inside of it.
	kc::List::pull_at(int)
		Deletes the specified node of the linked list and returns the data inside of it.
	kc::List::getIndex(int)
		Gets the data of the node at the specified index without deleting the node.
	kc::List:~List(void)
		Deletes all nodes of the list before deallocating the memory of the list.

TODO: kc::CircleList definitions and comments

/////////////////////////////////////////////////////////////////////////////
Other notes:

I use "TODO:" comments to indicate parts of the source code I am planning to add to or customize.

/////////////////////////////////////////////////////////////////////////////
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