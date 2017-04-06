#include <iostream>
#include <vector>

using namespace std;

void Bag::initializeBag(){
	for(int i=0; i<4; ++i){ //create 4 different colors
		for(int j=0; j<2; ++j){ //create 2 instances of each color group
			for(int l=0; l<13; ++l){ //create 13 different valued tiles in each group
				tile_bag[i].Tile.tile_color=i; //i is the underlying type of the color enum, so 0==red
				tile_bag[i].Tile.tile_value=i+1; //+1 corrects for the loop starting at 0
			}
		}
	}
	tile_bag[104].Tile.tile_color=joker;
	tile_bag[105].Tile.tile_color=joker;
};

void Bag::shuffleBag(){
	random_shuffle(tile_bag.begin(), tile_bag.end());
};