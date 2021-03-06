#include "SDL.h"
#pragma once
class GameWindow
{
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 640;

	private:
		static GameWindow *window;
		GameWindow();

	public:
		SDL_Renderer* gRenderer = NULL;
		SDL_Window* gWindow = NULL;

		static GameWindow * getWindowInstance()
		{
			if (window == NULL)
			{
				window = new GameWindow;
			}

			return window;
		};

		static void deleteWindowInstance()
		{
			delete window;
			window = NULL;
		}

		~GameWindow();

		int getScreenWidth() { return SCREEN_WIDTH; }
		int getScreenHeight() { return SCREEN_HEIGHT; }
};
//GameWindow* GameWindow::window = NULL;
