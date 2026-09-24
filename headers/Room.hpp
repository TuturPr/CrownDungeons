#include "includes.hpp"

class Room
{
	private:
		size_t height;
		size_t width;
		size_t x;
		size_t y;

	public:
		Room(size_t height, size_t width, size_t x, size_t Y);
		~Room();
		// Room generate();
		// bool intersect(const Room &other) const;
};

