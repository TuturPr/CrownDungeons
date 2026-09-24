#include "Map.hpp"

#define HEIGHT 10
#define WIDTH 10

int main(int argc, char **argv) {
	if (argc == 3)
	{
		size_t seed;
		std::random_device rd;
		if (rd.entropy()) {
			seed = rd();
		} else {
			seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		}
		std::mt19937 gen(seed);


		Map map(std::stoi(argv[1]), std::stoi(argv[2]));
		map.print_map();
		map.generate_spawn();
		map.print_map();

	}
}
