#pragma once
class Letter
{
public:
	Letter(int spawnPoint);
	~Letter();

	void move();
	void render();
	void spawn();
	SDL_Rect getCollisionBox();

private:
	int size_x = 20;
	int size_y = 20;
	int speed_x = 0;
	int speed_y = 0;
	int pos_x = 0;
	int pos_y = 0;

	bool isSpawned = false;

	SDL_Rect fillRect;
};

