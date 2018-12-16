#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GameWindow.h"
#include "Letter.h"
 

Letter::Letter()
{
	GameWindow *window = GameWindow::getWindowInstance();
	int spawnPoint = 0;
	srand(time(NULL));
	spawnPoint = rand() % 4 + 1;
	switch (spawnPoint)
	{
		//top position
		case 1:
			pos_x = (window->GetScreenWidth() / 2) - (size_x / 2);
			pos_y = 0;
			speed_x = 0;
			speed_y = 5;
			break;
		//right position
		case 2:
			pos_x = (window->GetScreenWidth() - size_x);
			pos_y = (window->GetScreenHeight() / 2) - (size_y / 2);
			speed_x = -5;
			speed_y = 0;
			break;
		//bottom position
		case 3:
			pos_x = (window->GetScreenWidth() / 2) - (size_x / 2);
			pos_y = (window->GetScreenHeight() - size_y);
			speed_x = 0;
			speed_y = -5;
			break;
		//left position
		case 4:
			pos_x = 0;
			pos_y = (window->GetScreenHeight() / 2) - (size_y / 2);
			speed_x = 5;
			speed_y = 0;
			break;
		default:
			break;
	}
	Render();
}


Letter::~Letter()
{
}

void Letter::Move()
{
	pos_x += speed_x;
	pos_y += speed_y;
	Render();
}

void Letter::Render()
{
	GameWindow *window = GameWindow::getWindowInstance();
	SDL_Rect fillRect = { pos_x, pos_y, size_x, size_y };
	SDL_SetRenderDrawColor(window->gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(window->gRenderer, &fillRect);
}