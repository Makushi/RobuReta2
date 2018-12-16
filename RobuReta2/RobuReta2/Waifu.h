#pragma once
class Waifu
{
	public:
		Waifu();
		~Waifu();

		void Render();

	private:
		int size_x = 20;
		int size_y = 20;
		int pos_x = 0;
		int pos_y = 0;
};

