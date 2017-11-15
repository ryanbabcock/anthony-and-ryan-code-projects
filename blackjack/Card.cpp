#include "card.h"

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