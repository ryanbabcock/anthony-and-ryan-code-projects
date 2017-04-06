#include <iostream>
#include <vector>
#include "Tile.h"
#include "Bag.h"
using namespace std;
int main() {
	Bag.initializeBag();
	Bag.shuffleBag();
	for(int i=0; i<106; ++i){
		cout << tile_bag[i].Tile.tile_color << tile_bag[i].Tile.tile_value << '\n';
	}
	return 0;	
}