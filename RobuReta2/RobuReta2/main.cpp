#include <SDL.h>
//#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "GameWindow.h"
#include "Letter.h"


int main(int argc, char* args[])
{
	bool mainLoop = true;
	GameWindow *window = GameWindow::getWindowInstance();
	SDL_Event e;
	Letter *test = new Letter();
	while (mainLoop)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				mainLoop = false;
			}

			SDL_RenderPresent(window->gRenderer);
		}
	}

	/*//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				//Render red filled quad
				SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
				SDL_RenderFillRect(gRenderer, &fillRect);

				//Render green outlined quad
				SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
				SDL_RenderDrawRect(gRenderer, &outlineRect);

				//Draw blue horizontal line
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);
				SDL_RenderDrawLine(gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

				//Draw vertical line of yellow dots
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0x00, 0xFF);
				for (int i = 0; i < SCREEN_HEIGHT; i += 4)
				{
					SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
				}

				//Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	//Free resources and close SDL
	//close();
	*/
	delete test;
	window->deleteWindowInstance();
	return 0;
}