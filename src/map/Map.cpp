#include "Map.hpp"

Map::Map(size_t height, size_t width) : height(height), width(width)
{
	this->map = std::vector<std::vector<char>>(this->height, std::vector(this->width, '#'));
}
Map::~Map()
{
}

void Map::print_map(std::ofstream &file) {
	for (size_t i = 0; i < this->map.size(); i++) {
		for (size_t j = 0 ; j < this->map[i].size() ; j++) {
			file << this->map[i][j];
		}
		file << '\n';
	}
}

void Map::generate_room(Room &room) {

	size_t width = room.get_width();
	size_t height = room.get_height();
	size_t x = room.get_x();
	size_t y = room.get_y();

	for (size_t i = y; i < y + height; i++) {
		for (size_t j = x; j < x + width; j++) {
			this->map[i][j] = '.';
		}
	}
}

