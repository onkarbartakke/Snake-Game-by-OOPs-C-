#ifndef SNAKE_H
#define SNAKE_H
#include <windows.h>
#include <vector>
#define HEIGHT 25
#define WIDTH 50

using namespace std;
class snake
{
	private:
		COORD pos;
		int len;
		int vel;
		char direction;
		vector<COORD>body;
	
	public:
		snake(COORD pos, int vel);
		void change_dir(char direction); //to change direction
		void move_snake(); //to move
		COORD get_pos();  //to get current position of snake
		
		vector<COORD>get_body();
		bool eaten(COORD food_pos);
		void grow();
		bool collided();
};

#endif


