// The character used for filled pixels of one number
#define FILL_CHAR "\u2588"

// The character used for empty pixels of one number
#define EMPTY_CHAR " "

// The character used for the spaces between the numbers
#define SPACE_CHAR " "


// The number of space characters between the numbers
#define SPACE_SIZE 1

// The color in which the time is displayed as hex value
#define COLOR 0x4e4e4e

// The format in which the time is displayed (H: Hours; M: Minutes; S: Seconds)
#define FORMAT "HMS"


// The offset which is applied to the centering of the clock (in columns and rows)
#define OFF_X 0
#define OFF_Y 0

// The width and height of one pixel (in columns and rows)
#define PIX_W 2
#define PIX_H 1

// The width and height of one number (in pixels)
#define CHAR_W 3
#define CHAR_H 5

// The font clck uses (can be any size -> specified by CHAR_W and CHAR_H) (1: Filled Pixels; 0: Empty Pixels)
const int font[11][CHAR_H][CHAR_W] = {
	{ // 0
		{1, 1, 1},
		{1, 0, 1},
		{1, 0, 1},
		{1, 0, 1},
		{1, 1, 1}
	},
	{ // 1
		{1, 1, 0},
		{0, 1, 0},
		{0, 1, 0},
		{0, 1, 0},
		{1, 1, 1}
	},
	{ // 2
		{1, 1, 1},
		{0, 0, 1},
		{1, 1, 1},
		{1, 0, 0},
		{1, 1, 1}
	},
	{ // 3
		{1, 1, 1},
		{0, 0, 1},
		{1, 1, 1},
		{0, 0, 1},
		{1, 1, 1}
	},
	{ // 4
		{1, 0, 1},
		{1, 0, 1},
		{1, 1, 1},
		{0, 0, 1},
		{0, 0, 1}
	},
	{ // 5
		{1, 1, 1},
		{1, 0, 0},
		{1, 1, 1},
		{0, 0, 1},
		{1, 1, 1}
	},
	{ // 6
		{1, 1, 1},
		{1, 0, 0},
		{1, 1, 1},
		{1, 0, 1},
		{1, 1, 1}
	},
	{ // 7
		{1, 1, 1},
		{0, 0, 1},
		{0, 0, 1},
		{0, 0, 1},
		{0, 0, 1}
	},
	{ // 8
		{1, 1, 1},
		{1, 0, 1},
		{1, 1, 1},
		{1, 0, 1},
		{1, 1, 1}
	},
	{ // 9
		{1, 1, 1},
		{1, 0, 1},
		{1, 1, 1},
		{0, 0, 1},
		{1, 1, 1}
	},
	{ // :
		{0, 0, 0},
		{0, 1, 0},
		{0, 0, 0},
		{0, 1, 0},
		{0, 0, 0}
	}
};
