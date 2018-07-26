#include <iostream>
#include <conio.h>

using namespace std;

//Main-Method
int main()
{

	bool Exit = false;
	int y = 0; //bat
	int directionX;
	int directionY;
	int BallXY[2]; // 0 = X; 1 = Y

	BallXY[0] = 0; //X
	BallXY[1] = 0; //Y

	//Gameloop
	while (!Exit)
	{
		//Input
		if (_getch() == 72) //Up-Arrow
		{
			y++;
		}

		else if(_getch() == 27) //ESC
		{
			Exit = true;
		}

		else if (_getch() == 80) //Down-Arrow
		{
			y--;
		}

		else //continue with Gameloop
		{ }

		BallXY[0] += directionX;

		//Collision
		if(BallXY[0] == 0 && BallXY[1] == y) //Ball == bat
		{
			directionX = 1; //->

			/*
			TODO:
			Ball-Slope random value (+/-)
			*/
			directionY = rand() %  + ; 
		}
		
		else if(BallXY[0] == 5) //on edge
		{
			directionX = -1; //<-
		}

		//Render
		

	}

	return 0;

}
