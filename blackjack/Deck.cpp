#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <algorithm> /* shuffle */

#include <iostream>
#include <vector>

#include "card.h"
#include "deck.h"

const int all_suits = 4 - 1;
const int all_values = 14;

Deck::Deck(){
	 _deck.reserve(51);
	int i = 0;
	for (int j = 0; j <= all_suits; ++j) {
		//begin with 2 because card can't have value 0
		for (int k = 2; k <= all_values; ++k) {
			_deck.push_back(Card(j, k));
			++i;
		}
	}
}	
void Deck::shuffleDeck(){
	random_shuffle(_deck.begin(), _deck.end());
}

void Deck::printDeck(){
	for (int i = 0; i < _deck.size(); ++i){
		std::cout << _deck[i]._suit << ' ' << _deck[i]._value << '\n';
	}	
}
