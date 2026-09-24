#include "Map.hpp"

#define MIN_ROOM_SIZE 4
#define MAX_ROOM_SIZE 13
#define MAX_ROOM_NUM 10
#define MAX_ATTEMPTS 500

int main(int argc, char **argv) {
	if (argc >= 3) {
		std::ofstream file("output.txt");
		int mapHeight = std::stoi(argv[1]);
		int mapWidth = std::stoi(argv[2]);

		size_t seed;
		std::random_device rd;
		if (rd.entropy()) {
			seed = rd();
		} else {
			seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		}
		if (argc == 4)
			seed = std::atoi(argv[3]);
		std::cout << "Seed = " << seed << '\n';
		std::mt19937 gen(seed);

		Map map(mapHeight, mapWidth);

		std::uniform_int_distribution<int> roomSize(MIN_ROOM_SIZE, MAX_ROOM_SIZE);

		int roomsPlaced = 0;
		int attempts = 0;

		Room spawn(9, 9, mapHeight / 2 - 5, mapWidth / 2 - 5);
		map.roomList.push_back(spawn);
		map.generate_room(spawn);

		while (roomsPlaced < MAX_ROOM_NUM && attempts < MAX_ATTEMPTS) {
			attempts++;

			int h = roomSize(gen);
			int w = roomSize(gen);

			std::uniform_int_distribution<int> roomX(1, mapWidth - w - 1);
			std::uniform_int_distribution<int> roomY(1, mapHeight - h - 1);
			int x = roomX(gen);
			int y = roomY(gen);

			Room newRoom(h, w, x, y);
			bool overlap = false;

			for (const auto& other_room : map.roomList) {
				if (newRoom.intersect(other_room)) {
					overlap = true;
					break;
				}
			}

			if (!overlap) {
				map.roomList.push_back(newRoom);
				map.generate_room(newRoom);
				roomsPlaced++;
			}
		}

		std::cout << "Room placed : " << roomsPlaced << "/" << MAX_ROOM_NUM
				   << " in " << attempts << " attempts\n";

		map.print_map(file);
		file.close();
	}
}
