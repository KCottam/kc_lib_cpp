#ifndef KC_CONTROLLER_H_
#define KC_CONTROLLER_H_
#include <ctime>
#include <conio.h>

namespace KC
{
	namespace Controller
	{
		enum InputFlag
		{
			FlagReturn,
			FlagEscape,
			FlagNumpad,
			FlagNormal
		};

		enum InputKey
		{
			KeyUpArrow = -'U',
			KeyDownArrow = -'D',
			KeyLeftArrow = -'L',
			KeyRightArrow = -'R',
			KeyHome = -'H',
			KeyEnd = -'E',
			KeyPgUp = -('P' + 'U'),
			KeyPgDown = -('P' + 'D'),
			KeyIns = -'R',
			KeyDel = -'S',
			KeyReturn = '\r'
		};

		inline int Ctrl(const int key)
		{
			return (key - 96);
		}

		inline int KeyF(const int key)
		{
			return (key + 58);
		}

		inline int CtrlKeyF(const int key)
		{
			return (key + 93);
		}

		inline char ToUpper(const char key)
		{
			if (key > 'a' && key < 'z')
			{
				return key + ('A' - 'a');
			}
			return key;
		}

		inline char* ToUpper(char* string)
		{
			for (auto i = 0; string[i] != '\0'; i++)
			{
				ToUpper(string[i]);
			}
			return string;
		}

		inline char ToLower(const char key)
		{
			if (key > 'A' && key < 'Z')
			{
				return key + ('a' - 'A');
			}
			return key;
		}

		inline char* ToLower(char* string)
		{
			for (auto i = 0; string[i] != '\0'; i++)
			{
				ToLower(string[i]);
			}
			return string;
		}

		inline int GetKey(InputFlag& flag, const time_t delay)
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
	}
}

#endif // !KC_CONTROLLER_H_
