#include "KCColors.h"
#include <iostream>

auto KC::Colorize(char* color, void (* function)()) -> void
{
	std::cout << color;
	function();
	std::cout << KC::Colors::reset;
}
