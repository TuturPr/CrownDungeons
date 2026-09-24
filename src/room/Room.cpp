#include "Room.hpp"

Room::Room(size_t height, size_t width, size_t x, size_t y) : height(height), width(width), x(x), y(y) {
}

Room::~Room() {
}


bool Room::intersect(const Room& other) const {
	const int margin = 4;
	return (x < other.x + other.width + margin &&
			x + width + margin > other.x &&
			y < other.y + other.height + margin &&
			y + height + margin > other.y);
}

size_t Room::get_height() {
	return this->height;
}

size_t Room::get_width() {
	return this->width;
}

size_t Room::get_x() {
	return this->x;
}

size_t Room::get_y() {
	return this->y;
}
