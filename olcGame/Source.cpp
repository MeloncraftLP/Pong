#include "olcPixelGameEngine.h"

// Strukturen
struct sRacket
{
	const int width = 1;
	const int height = 15;
	const float x = 5;
	float y = 40;
	short int score = 0;
};

struct sBall
{
	float x = 75;
	float y = 40;
	float Speed[2];
};

//Strukturen
sRacket left;
sRacket right;
sBall ball;

class PixelGame : public olc::PixelGameEngine
{
public:
	PixelGame()
	{
		sAppName = "PixelGame";
	}

public:
	bool OnUserCreate() override //On Start
	{
		ball.Speed[0] = 0.1;
		ball.Speed[1] = 0.1;
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override //GameLoop
	{

		ball.x -= ball.Speed[0];
		ball.y -= ball.Speed[1];
		//INPUT
		//INPUT
		if (GetKey(olc::Key::UP).bHeld)
			left.y -= 0.2;
		else if (GetKey(olc::Key::DOWN).bHeld)
			left.y += 0.2;
		//INPUT
		//INPUT

		//COLLISION
		//COLLISION
		if (ball.x < 3)
			if (ball.y <= left.y + 15 && ball.y >= left.y - 1)
			{
				ball.Speed[0] *= -1; //x
				ball.Speed[1] = (rand()%1)/10; //y
			}
			else
				ball.x = 75;
				ball.y = 40;
				right.score++;

		if(ball.x > 150) //TODO zweiter Sch�ger
			ball.Speed[0] *= -1;

		//COLLISION
		//COLLISION

		//RENDERING
		//RENDERING
		//Clear
		for (int w = 0; w < ScreenWidth(); w++)
			for (int h = 0; h < ScreenHeight(); h++)
				Draw(w, h, olc::Pixel(0,0,0));
		//Draw
		for(int i = 0; i < left.height; i++) // Draw Racket
			Draw(3, left.y+i, olc::Pixel(255, 255, 255));

		Draw(ball.x, ball.y, olc::Pixel(255, 255, 255));
		//RENDERING
		//RENDERING

		return true;
	}

};

int main() //Main
{
	PixelGame demo;
	if (demo.Construct(150, 80, 8, 8))
		demo.Start();
	return 0;
}