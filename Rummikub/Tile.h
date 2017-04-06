#include <iostream>
using namespace std;

class Tile{
	public:
		enum color{red=0,orange,blue,black,joker};
		//accesor functions? why do i need these	
		color getColor(); //returns a tile's color
		int getValue(); //returns a tile's value
	private:
		color tile_color;
		int tile_value; 	
};


