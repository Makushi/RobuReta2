#include "Waifu.h"
#include "GameWindow.h"
#include <stdio.h>

Waifu::Waifu()
{
	GameWindow *window = GameWindow::getWindowInstance();
	pos_y = (window->getScreenHeight() / 2) - (size_y / 2);
	pos_x = (window->getScreenWidth() / 2) - (size_x / 2);
	render();
}


Waifu::~Waifu()
{
}

void Waifu::render()
{
	GameWindow *window = GameWindow::getWindowInstance();
	fillRect = { pos_x, pos_y, size_x, size_y };
	SDL_SetRenderDrawColor(window->gRenderer, 0x00, 0x00, 0xFF, 0xFF);
	SDL_RenderFillRect(window->gRenderer, &fillRect);
}

SDL_Rect Waifu::getCollisionBox()
{
	return fillRect;
}

bool Waifu::damage()
{
	health -= 10;
	printf("Health remaining : %d\n", health);
	if (health <= 0)
	{
		isAlive = false;
	}

	return isAlive;
}