#include <ctime>
#include <conio.h>
#include "kc_controller.h"
int kc::controller::get_key(int * flag, int delay)
{
	if (delay)
	{
		time_t currentTime = time(NULL);
		while (time(NULL) <= currentTime + delay) {}
	}
	int key = _getch();
	if (key == KC_ESCAPE_CHARACTER_CODE)
	{
		*flag = KC_ESCAPE_CHARACTER_CODE;
		return get_key(flag, 0);
	}
	if (key == KC_NUMPAD_CHARACTER_CODE)
	{
		*flag = KC_NUMPAD_CHARACTER_CODE;
		return get_key(flag, 0);
	}
	else if (*flag == KC_ESCAPE_CHARACTER_CODE || *flag == KC_NUMPAD_CHARACTER_CODE)
	{
		switch (key)
		{
		case 'H':
			return UP_ARROW;
		case 'P':
			return DOWN_ARROW;
		case 'K':
			return LEFT_ARROW;
		case 'M':
			return RIGHT_ARROW;
		case 'G':
			return HOME;
		case 'I':
			return PG_UP;
		case 'O':
			return END;
		case 'Q':
			return PG_DOWN;
		case 'R':
			return INS;
		case 'S':
			return DEL;
		default:
			return key;
		}
	}
	else if (key == '\r')
	{
		*flag = KC_RETURN_CHARACTER_CODE;
	}
	else
	{
		*flag = KC_NORMAL_CHARACTER_CODE;
	}
	return key;
}
