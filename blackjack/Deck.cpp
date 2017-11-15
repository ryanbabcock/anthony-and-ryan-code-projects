#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <algorithm> /* shuffle */

using namespace std;

#include "Card.h"
#include "Deck.h"

const int all_suits = 4 - 1;
const int all values = 52 - 1;

Deck::Deck(){
	int i = 0;
	for (int j = 0; j <= all_suits; ++j) const{
		//begin with 1 because card cant have value 0
		for (int k = 1; k <= all_values; ++k) {
			_current_deck[i] = Card(j, k);
			++i;
		}
	}
}	

void Deck::shuffleDeck(){
	random_shuffle(_current_deck.begin(), _current_deck.end());
}

void Deck::printDeck(){
	for (int i = 0; i < current_deck.size(); ++i){
		cout << current_deck[i].suit << ' ' << current_deck[i].value << '\n';
	}	
}
