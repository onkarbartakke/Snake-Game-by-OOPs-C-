#include "snake.h"

snake::snake(COORD pos, int vel)
{
	this->pos=pos;
	this->vel=vel;
	len=1;
	direction='n';
	body.push_back(pos);
}

void snake::change_dir(char dir)
{
	direction=dir;
} 

vector<COORD> snake::get_body()
{
	return body;
}

void snake::move_snake()
{
	switch(direction)
	{
		case 'w': pos.Y-=vel;break; //up
		case 's': pos.Y+=vel;break;  //down
		case 'd': pos.X+=vel;break; //right
		case 'a': pos.X-=vel;break; //left
	}
	body.push_back(pos);
	
	if(body.size()>len)
	{
		body.erase(body.begin());
	}
}

COORD snake::get_pos()
{
	return pos;
}

bool snake::eaten(COORD food_pos)
{
	if(food_pos.X==pos.X && food_pos.Y==pos.Y)
	{
		return true;
	}
	else
	return false;
}

void snake::grow()
{
	len++;
}

bool snake::collided()
{
	if(pos.X< 1 || pos.X>WIDTH-2 || pos.Y< 1 || pos.Y>HEIGHT-2)
	return true;
	else
	return false;
}


