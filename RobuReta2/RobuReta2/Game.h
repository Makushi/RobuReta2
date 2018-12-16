#include "Waifu.h";
#include "Letter.h";
#include "GameWindow.h";
#pragma once
class Game
{
	public:
		Game();
		~Game();
		
		Letter *letters[50];
		Waifu *waifu;
		bool isRunning = true;

		const int FPS = 60;
		const int FRAME_DELAY = 1000 / FPS;

		SDL_Rect upCollider;
		SDL_Rect downCollider;
		SDL_Rect leftCollider;
		SDL_Rect rightCollider;

		GameWindow *window;

		SDL_Event e;

		Uint32 frameStart;
		int frameTime;
		int spawnTimer = 0;

		void run();
		void handleInput();
		void update();
		void initEntities();
		void initColliders();
		void deleteEntities();
		void drawDebugGrid();
};

