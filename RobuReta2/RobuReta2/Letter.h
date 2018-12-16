#pragma once
class Letter
{
public:
	Letter();
	~Letter();

	void Move();
	void Render(SDL_Rect fillRect);

private:
	void CreateAvatar();

	int size_x = 10;
	int size_y = 10;
	int speed = 10;
	int pos_x = 0;
	int pos_y = 0;
};

