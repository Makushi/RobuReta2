#include "Waifu.h"
#include "GameWindow.h"


Waifu::Waifu()
{
	GameWindow *window = GameWindow::getWindowInstance();
	pos_y = (window->GetScreenHeight() / 2) - (size_y / 2);
	pos_x = (window->GetScreenWidth() / 2) - (size_x / 2);
	Render();
}


Waifu::~Waifu()
{
}

void Waifu::Render()
{
	GameWindow *window = GameWindow::getWindowInstance();
	SDL_Rect fillRect = { pos_x, pos_y, size_x, size_y };
	SDL_SetRenderDrawColor(window->gRenderer, 0x00, 0x00, 0xFF, 0xFF);
	SDL_RenderFillRect(window->gRenderer, &fillRect);
}