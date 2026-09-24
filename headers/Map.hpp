#pragma once
#include "includes.hpp"
#include "Room.hpp"

class Map
{
	private:
		size_t height;
		size_t width;
		std::map<int, Room> roomList;

	public:
		std::vector<std::vector<char>> map;
		void print_map() const;
		void generate_spawn();
		Map(size_t height, size_t width);
		~Map();
};
