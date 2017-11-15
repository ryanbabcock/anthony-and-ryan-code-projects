#include <iostream>
#include <vector>
#include <string>

#include "card.h"
#include "deck.h"


int main() {
	std::cout << "Welcome to Blackjack!\n" 
	<< "How many players? (1-7): ";
	int number_of_players;
	std::cin >> number_of_players;
	std::vector<std::string> players(0);
	for (int i=0; i < number_of_players; ++i){
		std::cout << "Player " << i << ": ";
		std::string player_name;
		std::cin >> player_name;
		players.push_back(player_name);
	}
	Deck new_deck = Deck();
	std::cout << '\n';
	new_deck.printDeck();
return 0;
}