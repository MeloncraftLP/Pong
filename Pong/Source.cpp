#include <iostream>

using namespace std;

bool gameOver;

const int RacketWidth = 5;
int y = 4;
int BallX = 5, BallY = 5;


const int width = 40;
const int height = 20;
int x, score;
enum eDirection{LEFT, RIGHT, LEFTUP, LEFTDOWN, RIGHTUP, RIGHTDOWN};
eDirection dir;

void Setup()
{
	gameOver = false;
	dir = LEFT;
	BallX = width / 2;
	BallY = height / 2;
	score = 0;
}

void Draw()
{
	system("cls");

	for (int i = 0, j = 0; i < RacketWidth; i++) // RacketLeft
	{
		while (y != j) // Move to top Position 
		{
			cout << endl;
			j++;
		}
		cout << "#" << endl;
	}

}

void Input()
{

}

void Logic()
{

}

int main()
{

	Setup();
	while(!gameOver)
	{
		Draw();
		Input();
		Logic();
	}

	return 0;
}