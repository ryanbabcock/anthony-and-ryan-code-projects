#include "Deck.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

/// The generic deck files (alter for other uses)

int Deck::getrandom(int n)
{
	return rand() % n;
}

void Deck::Drawcard(int number)
{
	int a,b;

	while(number > 0)
	{
		a = getrandom(numCards);    //get a random card type
		b = getrandom(numSuits);    //and a random suit
		if(!isdrawn[a][b])          //if it's not already drawn
		{
			Printcard(a,b);         //print the value
			isdrawn[a][b]=true;     //and mark it off as true
			number--;               //then go again with one card less
		}
		else                        //if the card was drawn before
			Checkdeck();            //see whether there's any other valid cards left
	}
	return;
}

void Deck::Printcard(int card, int suit)
{
	if(card==0 || card ==7)//if it starts with a vowel (assuming generic deck)
		std::cout << "You drew an " << cards[card] << " of " << suits[suit] << ".\n";
	else                   //otherwise
		std::cout << "You drew a " << cards[card] << " of " << suits[suit] << ".\n";
	return;
}

bool Deck::Sortdeck()
{
	bool a=false;
	for(int n=0; n<numSuits; n++)
	{
		for(int i=0; i<numCards; i++)
		{
		   if(!isdrawn[i][n])       //if there's a single card in the deck not drawn
				a=true;             //make a note of it in a
		}
	}
	return a;                       //then return a
}

void Deck::Checkdeck()
{
	if(!Sortdeck())                 //if there are no cards left
	{
		Shuffle();                  //shuffle
	}
	return;
}

void Deck::Shuffle()
{
	std::cout << "Shuffling...\n";
	for(int n=0;n<numSuits;n++)
		for(int i=0;i<numCards;i++)
		{
			isdrawn[i][n]=false;    //sets the isdrawn array to be false
		}
	return;
}

void Deck::Menu()
{
	unsigned int amount = 1;
	while(amount > 0)          //this statement also prevents non-integer input from going through
	{
		std::cout << "How many cards would you like to draw? Type \"0\" to exit.\n";
		std::cin >> amount;    //if it's negative, the loop will just repeat itself
		Drawcard(amount);
	}
	return;
}