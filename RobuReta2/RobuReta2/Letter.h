#pragma once
class Letter
{
public:
	Letter(int spawnPoint);
	~Letter();

	void move();
	void render();
	void spawn();
	void reset();
	bool getIsSpawned() { return isSpawned; };

	SDL_Rect getCollisionBox();

private:
	int size_x = 20;
	int size_y = 20;
	int speed_x = 0;
	int speed_y = 0;
	int current_x = 0;
	int current_y = 0;
	int starting_x = 0;
	int starting_y = 0;

	bool isSpawned = false;

	SDL_Rect fillRect;
};

