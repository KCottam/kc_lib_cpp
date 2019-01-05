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

		char ToUpper(char key);

		char* ToUpper(char* string);

		char ToLower(char key);

		char* ToLower(char* string);

		int GetKey(InputFlag& flag, time_t delay);
	}
}

#endif // !KC_CONTROLLER_H_
