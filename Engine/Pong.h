#pragma once
#include "pch.h"

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include <iostream>
#include <time.h>
#include<conio.h>
#include <Windows.h>
using namespace std;
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 }; //Direction of the ball 
enum eNumber { First = 1, Second =  2, Third = 3, Fourth = 4, Fifth = 5};

struct Vector2 {

public:
		int x;
		int y;
};

class Pong {

private:
	void ComposeFrame();
	void UpdateModel();
	int ContainBoxX(int x);
	int ContainBoxY(int y);

private:
	int x, y; //Position on the screen
	int originalX, originalY; //Starting position 

private:
	MainWindow& wnd;
	Graphics gfx;

	int x_mobile = 50;
	int y_mobile = 300;
	int x_mobile1 = 590;
	int y_mobile1 = 300;
	int ballx = (gfx.ScreenWidth / 2) - 70;
	int bally = gfx.ScreenHeight / 2;
	int ballxspeed = 1;
	int ballyspeed = 1;
	int textX = 50;
	int textY = 540;
	int score;

	Vector2 paddle1Points[4];
	Vector2 paddle2Points[4];
	Vector2 ballPoints[4];



	void Reset() {

		int x_mobile = 50;
		int y_mobile = 300;
		int x_mobile1 = 590;
		int y_mobile1 = 300;
		int ballx = (gfx.ScreenWidth / 2) - 70;
		int bally = gfx.ScreenHeight / 2;
		direction = STOP;
	}

	void DrawPaddle(int x, int y);
	void DrawBall(int x, int y);

	void DrawNumbers(int x, int y, int toDraw);

	void DrawNumber1(int x, int y);
	void DrawNumber2(int x, int y);
	void DrawNumber3(int x, int y);
	void DrawNumber4(int x, int y);
	void DrawNumber5(int x, int y);


public:
	Pong(class MainWindow& wnd);
	Pong(const Pong&) = delete;
	Pong& operator=(const Pong&) = delete;
	void Go();
	eDir direction;

public:
	void PongStart(int posX, int posY) {
		originalX = posX;
		originalY = posY; //Save the original pos for reset
		x = posX; y = posY; //Current pos
		direction = STOP;
	}

	void changeDirection(eDir dir)
	{
		direction = dir;
	}

	void randomDirection()
	{
		direction = (eDir)((rand() % 6) + 1);
	}

	inline int getX() { return x; } //Inline makes the function replace the current position
	inline int getY() { return y; }
	inline eDir getDirection() { return direction; }



	/*void changeNumbers() 
	{
		switch (number) {
		}
	}*/
	

	void Move() //Ball Movement 
	{
		switch (direction)
		{
		case STOP:
			break;
		case LEFT:
			x--; //Decrease X coordinate
			break;
		case RIGHT:
			x++;
			break;
		case UPLEFT:
			x--; y--;
			break;
		case UPRIGHT:
			x++; y--;
			break;
		case DOWNLEFT:
			x--; y++;
			break;
		case DOWNRIGHT:
			x++; y++;
			break;
		default:
			break;
		}
	}

	friend ostream & operator << (ostream & o, Pong p)
	{
		o << "Ball [" << p.x << "," << p.y << "][" << p.direction << "]";
		return o;
	}
}; 



class GameManager {

private: 
	int width, height;
	int score1, score2;
	char up1, down1, up2, down2;//Player controls
	bool quit;
	Pong * ball;
public:
	int ballxspeed = 1;
	int ballyspeed = 1;



};

 
