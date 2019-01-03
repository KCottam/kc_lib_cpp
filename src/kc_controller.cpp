#include <ctime>
#include <conio.h>
#include "kc_controller.h"
/// <summary>
/// Gets a key press from the user.
/// </summary>
/// <param name="flag">The "flag" variable that shows where the key press came from.</param>
/// <param name="delay">A delay between key presses.</param>
/// <returns></returns>
int kc::controller::get_key(Flag& flag, time_t delay)
{
	if (delay)
	{
		time_t currentTime = time(NULL);
		while (time(NULL) <= currentTime + delay) {}
	}
	int key = _getch();
	if (key == FlagReturn)
	{
		flag = FlagEscape;
		return get_key(flag, 0);
	}
	if (key == FlagNumpad)
	{
		flag = FlagNumpad;
		return get_key(flag, 0);
	}
	else if (flag == FlagEscape || flag == FlagNumpad)
	{
		switch (key)
		{
		case 'H':
			return KeyUpArrow;
		case 'P':
			return KeyDownArrow;
		case 'K':
			return KeyLeftArrow;
		case 'M':
			return KeyRightArrow;
		case 'G':
			return KeyHome;
		case 'I':
			return KeyPgUp;
		case 'O':
			return KeyEnd;
		case 'Q':
			return KeyPgDown;
		case 'R':
			return KeyIns;
		case 'S':
			return KeyDel;
		default:
			return key;
		}
	}
	else if (key == '\r')
	{
		flag = FlagReturn;
	}
	else
	{
		flag = FlagReturn;
	}
	return key;
}