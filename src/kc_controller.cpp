#include <ctime>
#include <conio.h>
#include "kc_controller.h"
int kc::controller::get_key(flag& flag, time_t delay)
{
	if (delay)
	{
		const auto current_time = time(nullptr);
		while (time(nullptr) <= current_time + delay) {}
	}
	const auto key = _getch();
	if (key == flag_return)
	{
		flag = flag_escape;
		return get_key(flag, 0);
	}
	if (key == flag_numpad)
	{
		flag = flag_numpad;
		return get_key(flag, 0);
	}
	else if (flag == flag_escape || flag == flag_numpad)
	{
		switch (key)
		{
		case 'H':
			return key_up_arrow;
		case 'P':
			return key_down_arrow;
		case 'K':
			return key_left_arrow;
		case 'M':
			return key_right_arrow;
		case 'G':
			return key_home;
		case 'I':
			return key_pg_up;
		case 'O':
			return key_end;
		case 'Q':
			return key_pg_down;
		case 'R':
			return key_ins;
		case 'S':
			return key_del;
		default:
			return key;
		}
	}
	else if (key == '\r')
	{
		flag = flag_return;
	}
	else
	{
		flag = flag_return;
	}
	return key;
}