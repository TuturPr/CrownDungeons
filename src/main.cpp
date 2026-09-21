#include "Map.hpp"

#define HEIGHT 10
#define WIDTH 10

int main(int argc, char **argv) {
	if (argc == 3)
	{
		Map map(std::stoi(argv[1]), std::stoi(argv[2]));
		map.print_map();
		map.generate_spawn();
		map.print_map();
	}
}
