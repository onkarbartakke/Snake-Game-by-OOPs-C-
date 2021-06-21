#ifndef FOOD_H
#define FOOD_H
#include <cstdlib>
#include <windows.h>

#define HEIGHT 25
#define WIDTH 50

class food
{
	private:
		COORD pos;
	public:
		
		void gen_food();
		COORD get_pos();
};

#endif


