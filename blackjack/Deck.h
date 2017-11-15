#ifndef DECK_H
#define DECK_H

class Deck {
	public:
		std::vector<Card> _deck;
		Deck();
		void shuffleDeck();
		void printDeck();	
};

#endif