#pragma once
class Letter
{
public:
	Letter();
	~Letter();

	void Move();
	void Render();

private:
	int size_x = 20;
	int size_y = 20;
	int speed_x = 0;
	int speed_y = 0;
	int pos_x = 0;
	int pos_y = 0;
};

