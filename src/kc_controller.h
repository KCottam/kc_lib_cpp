#ifndef KC_CONTROLLER_H_
#define KC_CONTROLLER_H_
namespace kc
{
	namespace controller
	{
		// The flag variable becomes one of these when using get_key().
		enum flag
		{
			// Initialize all flags with this variable.
			flag_return,
			flag_escape,
			flag_numpad,
			flag_normal
		};
		enum key
		{
			key_up_arrow = -'U',
			key_down_arrow = -'D',
			key_left_arrow = -'L',
			key_right_arrow = -'R',
			key_home = -'H',
			key_end = -'E',
			key_pg_up = -('P' + 'U'),
			key_pg_down = -('P' + 'D'),
			key_ins = -'R',
			key_del = -'S',
			key_return = '\r'
		};
		inline int ctrl(const int key)
		{
			return (key - 96);
		}
		inline int key_f(const int key)
		{
			return (key + 58);
		}
		inline int ctrl_key_f(const int key)
		{
			return (key + 93);
		}
		inline char to_upper(const char key)
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
		inline char * to_upper(char * string)
		{
			for (auto i = 0; string[i] != '\0'; i++)
			{
				to_upper(string[i]);
			}
			return string;
		}
		inline char to_lower(const char key)
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
		inline char * to_lower(char * string)
		{
			for (auto i = 0; string[i] != '\0'; i++)
			{
				to_lower(string[i]);
			}
			return string;
		}
		// Gets a key that the user presses and returns it. _getch() modified.
		int get_key(flag& flag, time_t delay);
	}
}

#endif // !KC_CONTROLLER_H_