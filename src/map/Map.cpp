#include "Map.hpp"

Map::Map(size_t height, size_t width) : height(height), width(width)
{
	this->map = std::vector<std::vector<char>>(this->height, std::vector(this->width, '#'));
}
Map::~Map()
{
}

void Map::print_map() const{
	for (size_t i = 0; i < this->map.size(); i++) {
		for (size_t j = 0 ; j < this->map[i].size() ; j++) {
			std::cout << this->map[i][j];
		}
		std::cout << '\n';
	}
}

void Map::generate_spawn() {

	size_t spawnW = 5;
	size_t spawnH = 5;
	size_t spawnX = this->width / 2 - spawnW / 2;
	size_t spawnY = this->height / 2 - spawnH / 2;

	for (size_t i = spawnY; i < spawnY + spawnH; i++) {
		for (size_t j = spawnX; j < spawnX + spawnW; j++) {
			this->map[i][j] = '.';
		}
	}
}
