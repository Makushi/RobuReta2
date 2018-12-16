#include "Game.h"
#include "GameWindow.h"
#include "Waifu.h"
#include "Letter.h"
#include  <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <array>
#include <iostream>
#include <time.h>

Game::Game()
{
}


Game::~Game()
{
}

void Game::run()
{
	window = GameWindow::getWindowInstance();
	initEntities();
	initColliders();

	while (isRunning)
	{
		handleInput();
		update();
	}

	deleteEntities();
}

void Game::handleInput()
{
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE && e.key.repeat == 0))
		{
			isRunning = false;
		}
		else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_UP && e.key.repeat == 0)
		{
			bool missed = true;
			for (int i = 0; i < std::size(letters); i++)
			{
				if (letters[i]->getIsSpawned() && SDL_HasIntersection(&letters[i]->getCollisionBox(), &upCollider))
				{
					letters[i]->reset();
					missed = false;
				}
			}

			if (missed)
			{
				printf("You missed\n");
			}
		}
		else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_DOWN && e.key.repeat == 0)
		{
			bool missed = true;
			for (int i = 0; i < std::size(letters); i++)
			{
				if (letters[i]->getIsSpawned() && SDL_HasIntersection(&letters[i]->getCollisionBox(), &downCollider))
				{
					letters[i]->reset();
					missed = false;
				}
			}

			if (missed)
			{
				printf("You missed\n");
			}
		}
		else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_LEFT && e.key.repeat == 0)
		{
			bool missed = true;
			for (int i = 0; i < std::size(letters); i++)
			{
				if (letters[i]->getIsSpawned() && SDL_HasIntersection(&letters[i]->getCollisionBox(), &leftCollider))
				{
					letters[i]->reset();
					missed = false;
				}
			}

			if (missed)
			{
				printf("You missed\n");
			}
		}
		else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RIGHT && e.key.repeat == 0)
		{
			bool missed = true;
			for (int i = 0; i < std::size(letters); i++)
			{
				if (letters[i]->getIsSpawned() && SDL_HasIntersection(&letters[i]->getCollisionBox(), &rightCollider))
				{
					letters[i]->reset();
					missed = false;
				}
			}

			if (missed)
			{
				printf("You missed\n");
			}
		}
	}
}

void Game::update()
{
	frameStart = SDL_GetTicks();

	SDL_SetRenderDrawColor(window->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(window->gRenderer);

	SDL_SetRenderDrawColor(window->gRenderer, 0x00, 0xFF, 0x00, 0xFF);
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

	for (int i = 0; i < std::size(letters); i++)
	{
		letters[i]->move();
	}

	waifu->render();
	drawDebugGrid();
	SDL_RenderPresent(window->gRenderer);

	frameTime = SDL_GetTicks() - frameStart;

	if (FRAME_DELAY > frameTime)
	{
		SDL_Delay(FRAME_DELAY - frameTime);
	}
}

void Game::initEntities()
{
	int spawnPoint = 0;
	srand(time(NULL));
	for (int i = 0; i < std::size(letters); i++)
	{
		spawnPoint = rand() % 4 + 1;
		letters[i] = new Letter(spawnPoint);
	}

	waifu = new Waifu();
}

void Game::initColliders()
{
	int colliderWidth = 40;
	int colliderHeight = 20;
	int colliderOffset = 40;

	upCollider = { (window->getScreenWidth() / 2) - (colliderWidth / 2), (window->getScreenHeight() / 2) - (colliderHeight + colliderOffset), colliderWidth, colliderHeight };
	downCollider = { (window->getScreenWidth() / 2) - (colliderWidth / 2), (window->getScreenHeight() / 2) + (colliderHeight + (colliderOffset / 2)), colliderWidth, colliderHeight };
	rightCollider = { (window->getScreenWidth() / 2) + 40, (window->getScreenHeight() / 2) - 20, colliderHeight, colliderWidth };
	leftCollider = { (window->getScreenWidth() / 2) - 60, (window->getScreenHeight() / 2) - 20, colliderHeight, colliderWidth };
}

void Game::deleteEntities()
{
	for (int i = 0; i < std::size(letters); i++)
	{
		delete letters[i];
		letters[i] = NULL;
	}

	delete waifu;
	window->deleteWindowInstance();
}

void Game::drawDebugGrid()
{
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