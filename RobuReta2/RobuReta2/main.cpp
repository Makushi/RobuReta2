#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <array>
#include <iostream>
#include <time.h>
#include "GameWindow.h"
#include "Letter.h"
#include "Waifu.h"

void drawGrid()
{
	GameWindow *window = GameWindow::getWindowInstance();
	for (int i = 0; i < window->getScreenHeight(); i += 20)
	{
		SDL_SetRenderDrawColor(window->gRenderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(window->gRenderer, 0, i, window->getScreenWidth(), i);
	}

	for (int j = 0; j < window->getScreenWidth(); j += 20)
	{
		SDL_SetRenderDrawColor(window->gRenderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(window->gRenderer, j, 0, j, window->getScreenHeight());
	}

}

int main(int argc, char* args[])
{
	bool mainLoop = true;
	GameWindow *window = GameWindow::getWindowInstance();
	SDL_Event e;
	Letter *letters[20];
	int spawnPoint = 0;
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		spawnPoint = rand() % 4 + 1;
		letters[i] = new Letter(spawnPoint);
	}

	//Letter *test = new Letter();
	Waifu *mc = new Waifu();

	int colliderWidth = 40;
	int colliderHeight = 20;
	int colliderOffset = 40;

	SDL_Rect upCollider = { (window->getScreenWidth() / 2) - (colliderWidth / 2), (window->getScreenHeight() / 2) - (colliderHeight + colliderOffset), colliderWidth, colliderHeight };
	SDL_Rect downCollider = { (window->getScreenWidth() / 2) - (colliderWidth / 2), (window->getScreenHeight() / 2) + (colliderHeight + (colliderOffset / 2)), colliderWidth, colliderHeight };
	SDL_Rect rightCollider = { (window->getScreenWidth() / 2) + 40, (window->getScreenHeight() / 2) - 20, colliderHeight, colliderWidth };
	SDL_Rect leftCollider = { (window->getScreenWidth() / 2) - 60, (window->getScreenHeight() / 2) - 20, colliderHeight, colliderWidth };

	const int FPS = 60;
	const int FRAME_DELAY = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	int spawnTimer = 0;

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
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_UP && e.key.repeat == 0)
			{
				/*if (SDL_HasIntersection(&test->getCollisionBox(), &upCollider))
				{
					printf("Goteem");
				}
				else
				{
					printf("You missed");
				}*/
			}
		}

		SDL_SetRenderDrawColor(window->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(window->gRenderer);

		SDL_SetRenderDrawColor(window->gRenderer, 0x00, 0xFF, 0xFF, 0xFF);
		SDL_RenderFillRect(window->gRenderer, &upCollider);
		SDL_RenderFillRect(window->gRenderer, &downCollider);
		SDL_RenderFillRect(window->gRenderer, &rightCollider);
		SDL_RenderFillRect(window->gRenderer, &leftCollider);

		if (frameStart > spawnTimer + 3000)
		{
			int letterSelection = rand() % 20;
			if (letters[letterSelection])
			{
				letters[letterSelection]->spawn();
			}
			spawnTimer = frameStart;
		}

		for (int i = 0; i < 20 ; i++)
		{
			letters[i]->move();
		}

		mc->render();
		drawGrid();
		SDL_RenderPresent(window->gRenderer);

		frameTime = SDL_GetTicks() - frameStart;

		if (FRAME_DELAY > frameTime)
		{
			SDL_Delay(FRAME_DELAY - frameTime);
		}
	}

	//delete test;
	delete mc;
	window->deleteWindowInstance();
	return 0;
}