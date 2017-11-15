using namespace std;

#include "Card.h"

//define suits
const int spades = 0;
const int clubs = 1;
const int hearts = 2;
const int diamonds = 3;
//define face cards
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

Card::Card(int suit, int value){
	_suit = suit;
	_value = value;
}
/*
Card::Card createCard(int card_suit, int card_value){
	Card created_card(card_suit, card_value);
	return created_card;
}
*/
int Card::getSuit() const{
	return _suit;
}

int Card::getValue() const{
	return _value;
}