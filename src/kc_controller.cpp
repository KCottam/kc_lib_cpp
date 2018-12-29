#include <ctime>
#include <conio.h>
#include "kc_controller.h"
/// <summary>
/// Gets a key press from the user.
/// </summary>
/// <param name="flag">The "flag" variable that shows where the keypress came from.</param>
/// <param name="delay">A delay between keypresses.</param>
/// <returns></returns>
int kc::controller::get_key(int * flag, int delay)
{
	if (delay)
	{
		time_t currentTime = time(NULL);
		while (time(NULL) <= currentTime + delay) {}
	}
	int key = _getch();
	if (key == RETURN)
	{
		*flag = ESCAPE;
		return get_key(flag, 0);
	}
	if (key == NUMPAD)
	{
		*flag = NUMPAD;
		return get_key(flag, 0);
	}
	else if (*flag == ESCAPE || *flag == NUMPAD)
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
		*flag = RETURN;
	}
	else
	{
		*flag = RETURN;
	}
	return key;
}