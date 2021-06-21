#include "food.h"




void food::gen_food()
{
	
	pos.X=rand()% (WIDTH-3)  + 1;
	pos.Y=rand()% (HEIGHT-3) + 1;
}

COORD food::get_pos()
{
	return pos;
}

