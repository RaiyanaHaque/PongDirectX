/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{

		x_mobile = x_mobile + 1;

	} 

		

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x_mobile = x_mobile - 1;
	
	} 
	


	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y_mobile = y_mobile - 1;
		
	} 
	

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y_mobile = y_mobile + 1;
		
	} 

	x_mobile = ContainBoxX(x_mobile);
	y_mobile = ContainBoxY(y_mobile);
	
	//Test if all the boxes are overlapping
	colliding =
		OverlapTest(x_fixed0, y_fixed0, x_mobile, y_mobile) || //OR
		OverlapTest(x_fixed1, y_fixed1, x_mobile, y_mobile) ||
		OverlapTest(x_fixed2, y_fixed2, x_mobile, y_mobile) ||
		OverlapTest(x_fixed3, y_fixed3, x_mobile, y_mobile);
	
	

}

	//Scope life span of a variable
	//Viewport is 800 x 600
		void Game::ComposeFrame()
		{
			//Draw four boxes
			DrawBox(x_fixed0, y_fixed0, 0, 255, 255);
			DrawBox(x_fixed1, y_fixed1, 0, 255, 255);
			DrawBox(x_fixed2, y_fixed2, 0, 255, 255);
			DrawBox(x_fixed3, y_fixed3, 0, 255, 255);

			if (colliding) //Colour when colliding
			{
				DrawBox(x_mobile, y_mobile, 255, 0, 0);
			}
			else
			{
				DrawBox(x_mobile, y_mobile, 255, 255, 255);
			}

			

			//First value = x
			//Second value = y
			//Third = amount of red; Fourth = green; Fifth = blue;
		}

		void Game::DrawBox(int x, int y, int r, int g, int b) //Work based on params not member variables
		{
			gfx.PutPixel(-5 + x, -5 + y, r, g, b);
			gfx.PutPixel(-5 + x, -4 + y, r, g, b);
			gfx.PutPixel(-5 + x, -3 + y, r, g, b);
			gfx.PutPixel(-4 + x, -5 + y, r, g, b);
			gfx.PutPixel(-3 + x, -5 + y, r, g, b);
			gfx.PutPixel(-5 + x, 5 + y, r, g, b);
			gfx.PutPixel(-5 + x, 4 + y, r, g, b);
			gfx.PutPixel(-5 + x, 3 + y, r, g, b);
			gfx.PutPixel(-4 + x, 5 + y, r, g, b);
			gfx.PutPixel(-3 + x, 5 + y, r, g, b);
			gfx.PutPixel(5 + x, -5 + y, r, g, b);
			gfx.PutPixel(5 + x, -4 + y, r, g, b);
			gfx.PutPixel(5 + x, -3 + y, r, g, b);
			gfx.PutPixel(4 + x, -5 + y, r, g, b);
			gfx.PutPixel(3 + x, -5 + y, r, g, b);
			gfx.PutPixel(5 + x, 5 + y, r, g, b);
			gfx.PutPixel(5 + x, 4 + y, r, g, b);
			gfx.PutPixel(5 + x, 3 + y, r, g, b);
			gfx.PutPixel(4 + x, 5 + y, r, g, b);
			gfx.PutPixel(3 + x, 5 + y, r, g, b);
		}

		bool Game::OverlapTest(int x_box0, int y_box0, int x_box1, int y_box1)
		{

			//Find edges
			const int left_box0 = x_box0 - 5;
			const int right_box0 = x_box0 + 5;
			const int top_box0 = y_box0 - 5;
			const int bottom_box0 = y_box0 + 5;

			const int left_box1 = x_box1 - 5;
			const int right_box1 = x_box1 + 5;
			const int top_box1 = y_box1 - 5;
			const int bottom_box1 = y_box1 + 5;

			//Collision spaces
			return left_box0 <= right_box1 &&
				right_box0 >= left_box1 &&
				top_box0 <= bottom_box1 &&
				bottom_box0 >= top_box1;

			
		}
	
		int Game::ContainBoxX(int x)
		{
			const int left = x - 5;
			const int right = x + 5;

			if (left < 0) {
				return 5;
			}

			else if (right >= gfx.ScreenWidth) {
				return gfx.ScreenWidth - 6;
			}

			else {

				return x;
			}

		}

		int Game::ContainBoxY(int y)
		{
			const int top = y - 5;
			const int bottom = y + 5;

			if (top < 0) {
				return 5;
			}

			else if (bottom >= gfx.ScreenHeight) {
				return gfx.ScreenHeight - 6;
			}

			else {
				
				return y;
			}
		}

