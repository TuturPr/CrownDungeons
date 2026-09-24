#include "includes.hpp"

class Room
{
	private:
		size_t height;
		size_t width;
		size_t x;
		size_t y;

	public:
		Room(size_t height, size_t width, size_t x, size_t y);
		~Room();
		bool intersect(const Room &other) const;

		size_t get_height();
		size_t get_width();
		size_t get_x();
		size_t get_y();
};
