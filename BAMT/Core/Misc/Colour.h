#ifndef BAMT_COLOUR
#define BAMT_COLOUR

#define BAMT_COLOUR_RED		{ 255, 0, 0, 255 }
#define BAMT_COLOUR_GREEN		{ 0, 255, 0, 255 }
#define BAMT_COLOUR_BLUE		{ 0, 0, 255, 255 }

#define BAMT_COLOUR_YELLOW		{ 255, 255, 0, 255 }
#define BAMT_COLOUR_CYAN		{ 0, 255, 255, 255 }
#define BAMT_COLOUR_PURPLE		{ 255, 0, 255, 255 }

#define BAMT_COLOUR_BLACK		{ 0, 0, 0, 255 }
#define BAMT_COLOUR_WHITE	{ 255, 255, 255, 255 }

struct Colour
{
	int r = 0;
	int g = 0;
	int b = 0;
	int a = 0;
};
#endif
