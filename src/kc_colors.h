#ifndef KC_COLORS_H_
#define KC_COLORS_H_
namespace kc
{
	// Used for formatting in the console.
	static class formatting final
	{
	public:
		// Resets font styles and colors to default
		const char * reset = "\x1b[0m";
		// Deletes the line the cursor is currently on
		const char * delete_line = "\33[2K\r";
		// Moves the cursor up one
		const char * cursor_up = "\33[1A";
		// Moves the cursor down one
		const char * cursor_down = "\33[1B";
		// Moves the cursor right one
		const char * cursor_right = "\33[1C";
		// Moves the cursor left one
		const char * cursor_left = "\33[1D";
	} formatting;
	static class styles final
	{
	public:
		// Applies a bold font style to the text after it
		const char * bold = "\x1b[1m";
		// Applies an underlined font style to the text after it
		const char * underline = "\x1b[4m";
		// Swaps the color of the foreground and background colors of the text after it
		const char * inverse = "\x1b[7m";
	} styles;
	static class colors final
	{
	public:
		// dark black
		// Default terminal background color
		const char * black = "\x1b[30m";
		// dark red
		const char * red = "\x1b[31m";
		// dark green
		const char * green = "\x1b[32m";
		// dark yellow
		const char * yellow = "\x1b[33m";
		// dark blue
		const char * blue = "\x1b[34m";
		// dark magenta
		const char * magenta = "\x1b[35m";
		// dark cyan
		const char * cyan = "\x1b[36m";
		// white
		// default terminal foreground color
		const char * white = "\x1b[37m";
		// a shade below char * white
		const char * BLACK = "\x1b[90m";
		// bright or strong red
		const char * RED = "\x1b[91m";
		// bright or strong green
		const char * GREEN = "\x1b[92m";
		// bright or strong yellow
		const char * YELLOW = "\x1b[93m";
		// bright or strong blue
		const char * BLUE = "\x1b[94m";
		// bright or strong magenta
		const char * MAGENTA = "\x1b[95m";
		// bright or strong cyan
		const char * CYAN = "\x1b[96m";
		// bright or strong white
		const char * WHITE = "\x1b[97m";
	} colors;
	static class highlights final
	{
	public:
		// dark black highlight.
		// default terminal background color
		const char * black = "\x1b[40m";
		// dark red highlight
		const char * red = "\x1b[41m";
		// dark green highlight
		const char * green = "\x1b[42m";
		// dark yellow highlight
		const char * yellow = "\x1b[43m";
		// dark blue highlight
		const char * blue = "\x1b[44m";
		// dark magenta highlight
		const char * magenta = "\x1b[45m";
		// dark cyan highlight
		const char * cyan = "\x1b[46m";
		// white highlight
		// default terminal foreground color
		const char * white = "\x1b[47m";
		// a shade below char * white highlight
		const char * BLACK = "\x1b[100m";
		// bright or strong red highlight
		const char * RED = "\x1b[101m";
		// bright or strong green highlight
		const char * GREEN = "\x1b[102m";
		// bright or strong yellow highlight
		const char * YELLOW = "\x1b[103m";
		// bright or strong blue highlight
		const char * BLUE = "\x1b[104m";
		// bright or strong magenta highlight
		const char * MAGENTA = "\x1b[105m";
		// bright or strong cyan highlight
		const char * CYAN = "\x1b[106m";
		// bright or strong white highlight
		const char * WHITE = "\x1b[107m";
	} highlights;
}

// Usage:	Colorize(color, <insert all code that needs to be colorized>(;
//			Colorize(kc::colors::RED, draw_box(....));
#define COLORIZE(color, code) {cout << (color); {code}; cout << (RESET);}

#endif // !KC_COLORS_H_