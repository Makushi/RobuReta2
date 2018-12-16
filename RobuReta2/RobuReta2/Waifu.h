#include <SDL.h>
#pragma once

class Waifu
{
	public:
		Waifu();
		~Waifu();

		SDL_Rect getCollisionBox();

		void render();
		bool damage();

	private:
		int size_x = 20;
		int size_y = 20;
		int pos_x = 0;
		int pos_y = 0;
		int health = 100;
		bool isAlive = true;

		SDL_Rect fillRect;
};

