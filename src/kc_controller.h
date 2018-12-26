#ifndef KC_CONTROLLER_H_
#define KC_CONTROLLER_H_

namespace kc
{
	namespace controller
	{
		const int KC_ESCAPE_CHARACTER_CODE = 224;
		const int KC_NUMPAD_CHARACTER_CODE = 0;
		//Initialize all flags with this variable.
		const int KC_RETURN_CHARACTER_CODE = 1;
		const int KC_NORMAL_CHARACTER_CODE = 2;
		const int UP_ARROW = 'U';
		const int DOWN_ARROW = 'D';
		const int LEFT_ARROW = 'L';
		const int RIGHT_ARROW = 'R';
		const int HOME = 'H';
		const int PG_UP = ('P' + 'U');
		const int END = 'E';
		const int PG_DOWN = ('P' + 'D');
		const int INS = 'R';
		const int DEL = 'S';
		const int ENTER = '\r';
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
		//Add this to a lowercase letter to move it to uppercase.
		const int TO_UPPER = ('A' - 'a');
		//Add this to an uppercase letter to move it to lowercase.
		const int TO_LOWER = ('a' - 'A');
		//Gets a key that the user presses and returns it. _getch() modified.
		int get_key(int * flag, int delay);
	}
}

#endif // !KC_CONTROLLER_H_