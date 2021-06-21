#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "snake.h"
#include "food.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define HEIGHT 25
#define WIDTH 50
using namespace std;

 //int x=10,y=10;

snake s({WIDTH/2,HEIGHT/2},1);
food f;
int score;
void draw_board()
{
	int i,j;
	COORD snake_pos=s.get_pos();
	COORD food_pos=f.get_pos();
	
	vector<COORD>snake_body=s.get_body();
	cout<<"\t\tSCORE :"<<score<<"\t\t\t A GAME BY ONKAR"<<"\n\n\n";
	for(i=0;i<HEIGHT;i++)
	{
		cout<<"\t\t#";
		for(j=0;j<WIDTH-2;j++)
		{
			if(i==0 || i==HEIGHT-1)
			{
				cout<<'#';
			}
			else if(i==snake_pos.Y && j+1==snake_pos.X)
			{
				cout<<'0';
			}
			else if(i==food_pos.Y && j+1==food_pos.X)
			{
				cout<<'*';
			}
			else
			{   
			    
				bool isbody=false;
				for(int k=0;k<snake_body.size()-1;k++)
				{
					if(i==snake_body[k].Y && j+1==snake_body[k].X)
					{
						cout<<'0';
						isbody=true;
						break;
					}
				}
				
				if(!isbody)
				{
				
					cout<<' ';
				}
			
			}
		}
		cout<<"#\n";
	}
}
int main() {
	srand(time(0));
	f.gen_food();
	bool gameover=false;
	score=0;
	while(!gameover)
	{
	   draw_board();
	   //x++;
	   //system("cls");    
	   if(kbhit())
	   {
	   	  switch(getch())
	   	  {
	   	  	case 'w':s.change_dir('w');break;
	   	  	case 's':s.change_dir('s');break;
	   	  	case 'd':s.change_dir('d');break;
	   	  	case 'a':s.change_dir('a');break;
		  }
	   	 
	   }
	   
	   if(s.eaten(f.get_pos()))
	   {
	   	  f.gen_food();
	   	  s.grow();
	   	  score++;
	   }
	   
	   if(s.collided())
	   {
	   	   gameover=true;
	   	   
	   }
	   s.move_snake();
	   SetConsoleCursorPosition(GetStdHandle (STD_OUTPUT_HANDLE),{0,0});
	}	
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tGAME OVER\n";
	return 0;
}
