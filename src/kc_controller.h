#ifndef KC_CONTROLLER_H_
#define KC_CONTROLLER_H_
namespace kc
{
	namespace controller
	{
		// The flag variable becomes one of these when using get_key().
		enum Flag
		{
			// Initialize all flags with this variable.
			FlagReturn,
			FlagEscape,
			FlagNumpad,
			FlagNormal
		};
		enum Key
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
		inline int ctrl(int key)
		{
			return (key - 96);
		}
		inline int keyF(int key)
		{
			return (key + 58);
		}
		inline int ctrlkeyF(int key)
		{
			return (key + 93);
		}
		inline char toUpper(char key)
		{
			if (key > 'a' && key < 'z')
			{
				return key + ('A' - 'a');
			}
			else
			{
				return key;
			}
		}
		inline char * toUpper(char * string)
		{
			for (int i = 0; string[i] != '\0'; i++)
			{
				toUpper(string[i]);
			}
			return string;
		}
		inline char toLower(char key)
		{
			if (key > 'A' && key < 'Z')
			{
				return key + ('a' - 'A');
			}
			else
			{
				return key;
			}
		}
		inline char * toLower(char * string)
		{
			for (int i = 0; string[i] != '\0'; i++)
			{
				toLower(string[i]);
			}
			return string;
		}
		// Gets a key that the user presses and returns it. _getch() modified.
		int get_key(Flag& flag, time_t delay);
	}
}

#endif // !KC_CONTROLLER_H_