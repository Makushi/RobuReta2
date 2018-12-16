#include <SDL.h>
#include "GameWindow.h"
#include "Letter.h"


Letter::Letter()
{
	CreateAvatar();
}


Letter::~Letter()
{
}

void Letter::CreateAvatar()
{
	GameWindow *window = GameWindow::getWindowInstance();
	SDL_Rect fillRect = { 0, 0, 10, 10 };
	SDL_SetRenderDrawColor(window->gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(window->gRenderer, &fillRect);
}

void Letter::Move()
{
	pos_x += speed;
	SDL_Rect fillRect = { pos_x, pos_y, size_x, size_y };	
	Render(fillRect);
}

void Letter::Render(SDL_Rect fillRect)
{
	GameWindow *window = GameWindow::getWindowInstance();
	//SDL_Rect fillRect = { 0, 0, 10, 10 };
	SDL_SetRenderDrawColor(window->gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(window->gRenderer, &fillRect);
}