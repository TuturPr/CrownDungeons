#pragma once
#include "includes.hpp"
#include "Room.hpp"

class Map
{
	private:
		size_t height;
		size_t width;

		public:
		std::vector<Room> roomList;
		std::vector<std::vector<char>> map;

		void print_map(std::ofstream &file);
		void generate_spawn();
		void generate_room(Room &room);
		Map(size_t height, size_t width);
		~Map();
};
