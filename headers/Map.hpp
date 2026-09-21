#pragma once
#include "includes.hpp"

class Map
{
	private:
		size_t height;
		size_t width;

	public:
		std::vector<std::vector<char>> map;
		void print_map();
		void generate_spawn();
		Map(size_t height, size_t width);
		~Map();
};
