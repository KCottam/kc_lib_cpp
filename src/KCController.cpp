#include "KCController.h"

char KC::Controller::ToUpper(const char key)
{
	if (key > 'a' && key < 'z')
	{
		return key + ('A' - 'a');
	}
	return key;
}

char* KC::Controller::ToUpper(char* string)
{
	for (auto i = 0; string[i] != '\0'; i++)
	{
		ToUpper(string[i]);
	}
	return string;
}

char KC::Controller::ToLower(const char key)
{
	if (key > 'A' && key < 'Z')
	{
		return key + ('a' - 'A');
	}
	return key;
}

char* KC::Controller::ToLower(char* string)
{
	for (auto i = 0; string[i] != '\0'; i++)
	{
		ToLower(string[i]);
	}
	return string;
}

int KC::Controller::GetKey(InputFlag& flag, const time_t delay)
{
	if (delay)
	{
		const auto currentTime = time(nullptr);
		while (time(nullptr) <= currentTime + delay)
		{
		}
	}
	const auto key = _getch();
	if (key == FlagReturn)
	{
		flag = FlagEscape;
		return GetKey(flag, 0);
	}
	if (key == FlagNumpad)
	{
		flag = FlagNumpad;
		return GetKey(flag, 0);
	}
	if (flag == FlagEscape || flag == FlagNumpad)
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
	flag = FlagReturn;
	return key;
}
