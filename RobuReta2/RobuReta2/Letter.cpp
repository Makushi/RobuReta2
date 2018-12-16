#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GameWindow.h"
#include "Letter.h"
 

Letter::Letter(int spawnPoint)
{
	GameWindow *window = GameWindow::getWindowInstance();

	switch (spawnPoint)
	{
		//top position
		case 1:
			starting_x = current_x = (window->getScreenWidth() / 2) - (size_x / 2);
			starting_y = current_y = 0;
			speed_x = 0;
			speed_y = 1;
			break;
		//right position
		case 2:
			starting_x = current_x = (window->getScreenWidth() - size_x);
			starting_y = current_y = (window->getScreenHeight() / 2) - (size_y / 2);
			speed_x = -1;
			speed_y = 0;
			break;
		//bottom position
		case 3:
			starting_x = current_x = (window->getScreenWidth() / 2) - (size_x / 2);
			starting_y = current_y = (window->getScreenHeight() - size_y);
			speed_x = 0;
			speed_y = -1;
			break;
		//left position
		case 4:
			starting_x = current_x = 0;
			starting_y = current_y = (window->getScreenHeight() / 2) - (size_y / 2);
			speed_x = 1;
			speed_y = 0;
			break;
		default:
			break;
	}
	render();
}


Letter::~Letter()
{
}

void Letter::move()
{
	if (isSpawned)
	{
		current_x += speed_x;
		current_y += speed_y;
		render();
	}
}

void Letter::render()
{
	GameWindow *window = GameWindow::getWindowInstance();
	fillRect = { current_x, current_y, size_x, size_y };
	SDL_SetRenderDrawColor(window->gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(window->gRenderer, &fillRect);
}

SDL_Rect Letter::getCollisionBox()
{
	return fillRect;
}

void Letter::spawn()
{
	if (!isSpawned)
	{
		isSpawned = true;
	}
}

void Letter::reset()
{
	isSpawned = false;
	current_x = starting_x;
	current_y = starting_y;
}