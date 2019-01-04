#ifndef KC_COLORS_H_
#define KC_COLORS_H_

namespace KC
{
	static struct Formatting final
	{
		const char* Reset = "\x1b[0m";
		const char* DeleteLine = "\33[2K\r";
		const char* CursorUp = "\33[1A";
		const char* CursorDown = "\33[1B";
		const char* CursorRight = "\33[1C";
		const char* CursorLeft = "\33[1D";
	} formatting;

	static struct Styles final
	{
		const char* Bold = "\x1b[1m";
		const char* Underline = "\x1b[4m";
		const char* Inverse = "\x1b[7m";
	} styles;

	static struct Colors final
	{
		static struct Weak final
		{
			const char* Black = "\x1b[30m";
			const char* Red = "\x1b[31m";
			const char* Green = "\x1b[32m";
			const char* Yellow = "\x1b[33m";
			const char* Blue = "\x1b[34m";
			const char* Magenta = "\x1b[35m";
			const char* Cyan = "\x1b[36m";
			const char* White = "\x1b[37m";
		} Weak;

		static struct Strong final
		{
			const char* Black = "\x1b[90m";
			const char* Red = "\x1b[91m";
			const char* Green = "\x1b[92m";
			const char* Yellow = "\x1b[93m";
			const char* Blue = "\x1b[94m";
			const char* Magenta = "\x1b[95m";
			const char* Cyan = "\x1b[96m";
			const char* White = "\x1b[97m";
		} Strong;
	} colors;

	static struct Highlights final
	{
		static struct Weak final
		{
			const char* Black = "\x1b[40m";
			const char* Red = "\x1b[41m";
			const char* Green = "\x1b[42m";
			const char* Yellow = "\x1b[43m";
			const char* Blue = "\x1b[44m";
			const char* Magenta = "\x1b[45m";
			const char* Cyan = "\x1b[46m";
			const char* White = "\x1b[47m";
		} Weak;

		static struct Strong final
		{
			const char* Black = "\x1b[100m";
			const char* Red = "\x1b[101m";
			const char* Green = "\x1b[102m";
			const char* Yellow = "\x1b[103m";
			const char* Blue = "\x1b[104m";
			const char* Magenta = "\x1b[105m";
			const char* Cyan = "\x1b[106m";
			const char* White = "\x1b[107m";
		} Strong;
	} highlights;
}

#define COLORIZE(color, code) {cout << (color); {code}; cout << RESET;}

#endif // !KC_COLORS_H_
