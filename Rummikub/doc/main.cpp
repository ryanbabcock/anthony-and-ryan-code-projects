#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Deck.h"

/// Code for a deck of cards using generic deck files; user can input number of cards to be drawn.

int main()
{
	srand(time(NULL));
	Deck A;
	A.Menu();
	return 0;
}