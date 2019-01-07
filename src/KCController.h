#ifndef KC_CONTROLLER_H_
#define KC_CONTROLLER_H_
#include <ctime>
#include <conio.h>

namespace KC
{
	namespace Controller
	{
		enum class InputFlag : int
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

		inline auto Ctrl(int key) -> int;

		inline auto KeyF(int key) -> int;

		inline auto CtrlKeyF(int key) -> int;

		auto ToUpper(char key) -> char;

		auto ToUpper(char* string) -> char*;

		auto ToLower(char key) -> char;

		auto ToLower(char* string) -> char*;

		auto GetKey(InputFlag& flag, time_t delay) -> int;
	}
}

#endif // !KC_CONTROLLER_H_
