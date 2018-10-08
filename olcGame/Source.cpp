#include "olcPixelGameEngine.h"
#include <cstring>

//Strucutures
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

//Structures
sRacket left;
sRacket right;
sBall ball;

auto GlobalScore = left.score + " : " + right.score; //Score

void reset() //Functions
{
	ball.x = 75;
	ball.y = 40;
	ball.Speed[1] = rand() % 40; //y
	ball.Speed[1] = (ball.Speed[1] - 20) / 100; //y
}

void collision()
{
	ball.Speed[0] *= -1; //x
	ball.Speed[1] = rand() % 40; //y
	ball.Speed[1] = (ball.Speed[1] - 20) / 100; //y
}

class PixelGame : public olc::PixelGameEngine
{
public:
	PixelGame()
	{
		sAppName = "Pong";
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
		ball.x -= ball.Speed[0]; //Changing the x and y. So that the ball moves.
		ball.y -= ball.Speed[1];

		if (GetKey(olc::Key::W).bHeld) //Input (left)
			left.y -= 0.2;
		else if (GetKey(olc::Key::S).bHeld)
			left.y += 0.2;

		if (GetKey(olc::Key::UP).bHeld) //Input (right)
			right.y -= 0.2;
		else if (GetKey(olc::Key::DOWN).bHeld) 
			right.y += 0.2;

		if (ball.x < 3) //Collision-Detection (left)
			if (ball.y <= left.y + 15 && ball.y >= left.y - 1)
				collision();
			else 
			{ //no Collision -> Goal
				reset();
				right.score++;
			}

		if (ball.x > 146) //Collision-Detection (right)
			if (ball.y <= right.y + 15 && ball.y >= right.y - 1)
				collision();
			else
			{ //no Collision -> Goal
				reset();
				left.score++;
			}

		if (ball.y <= 0) //Collision on Sealing
			ball.Speed[1] *= -1;

		else if (ball.y >= 80) //Collision on Floor
			ball.Speed[1] *= -1;

		for (int w = 0; w < ScreenWidth(); w++) //Clear the Screen
			for (int h = 0; h < ScreenHeight(); h++)
				Draw(w, h, olc::Pixel(0,0,0));

		for(int i = 0; i < left.height; i++) // Draw Racket (left)
			Draw(3, left.y+i, olc::Pixel(255, 255, 255));

		for (int i = 0; i < right.height; i++) // Draw Racket (right)
			Draw(146, right.y + i, olc::Pixel(255, 255, 255));

		Draw(ball.x, ball.y, olc::Pixel(255, 255, 255)); //Draw Ball

		std::string GlobalScore = "" + std::to_string(left.score) + " : " + std::to_string(right.score); //Adding Information to the String
		if (left.score >= 10) //Centering the Text
			DrawString(48, 0, GlobalScore, olc::WHITE, 1U);
		else
			DrawString(56, 0, GlobalScore, olc::WHITE, 1U);

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