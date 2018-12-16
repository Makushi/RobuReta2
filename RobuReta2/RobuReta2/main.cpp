#include <SDL.h>
//#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "GameWindow.h"
#include "Letter.h"
#include "Waifu.h"

void drawGrid()
{
	GameWindow *window = GameWindow::getWindowInstance();
	for (int i = 0; i < window->GetScreenHeight(); i += 20)
	{
		SDL_SetRenderDrawColor(window->gRenderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(window->gRenderer, 0, i, window->GetScreenWidth(), i);
	}

	for (int j = 0; j < window->GetScreenWidth(); j += 20)
	{
		SDL_SetRenderDrawColor(window->gRenderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(window->gRenderer, j, 0, j, window->GetScreenHeight());
	}

}

int main(int argc, char* args[])
{
	bool mainLoop = true;
	GameWindow *window = GameWindow::getWindowInstance();
	SDL_Event e;
	Letter *test = new Letter();
	Waifu *mc = new Waifu();

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	while (mainLoop)
	{
		frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				mainLoop = false;
			}
		}

		SDL_SetRenderDrawColor(window->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(window->gRenderer);

		test->Move();
		mc->Render();
		drawGrid();
		SDL_RenderPresent(window->gRenderer);

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	delete test;
	delete mc;
	window->deleteWindowInstance();
	return 0;
}