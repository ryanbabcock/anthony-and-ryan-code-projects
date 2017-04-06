#ifndef DECK_H
#define DECK_H
#include <iostream>

/// The generic deck header (alter for other uses)

class Deck
{
		static const int numSuits = 4;     //a standard deck of cards has four suits
		static const int numCards = 13;    //and 13 card types. Can be changed if you wanted to play Uno or somesuch

		std::string suits[numSuits]= {"hearts","spades","clubs","diamonds"};   //the array of suits
		std::string cards[numCards]= {"ace","two","three","four",
																	"five","six","seven","eight",
																	"nine","ten","jack","queen","king"};    //the array pf card values
		bool isdrawn[numCards][numSuits];        //an array to keep track of whether the cards are drawn

		void Printcard(int, int);   //prints the cards drawn
		int getrandom(int);         //produces a random number
		bool Sortdeck();            //determines whether the deck has been entirely drawn or not
		void Checkdeck();           //check whether a card is drawn
		void Shuffle();             //if the whole deck is drawn, set all of isdrawn to false
		void Drawcard(int);         //draw the card, marking it off in isdrawn

		public:
		void Menu();
};

#endif // DECK_H 