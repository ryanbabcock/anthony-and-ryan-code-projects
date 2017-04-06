#include <iostream>
#include <vector>
#include "Tile.h"
using namespace std;

const int bag_size = 106;
vector<Tile> tile_bag(bag_size);

class Bag{
	public:
		void initializeBag();
		void shuffleBag();
}
