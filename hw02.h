/********************************
 * STUDENT NAME : Yuliy Dubovyk
 * STUDENT ID   : 1073327
 * CLASS        : 1C
 * ASSIGNMENT   : HW02
 * PROFESSOR    : John Kath
 * DUE DATE     : 8/31
 ********************************/


#ifndef HW02_H_
#define HW02_H_

#include <iostream>
#include <string>


using namespace std;

const int DECK_SIZE = 52;
const int NO_OF_SUITS = 4;
const int NO_OF_RANKS = 13;

enum suits {CLUBS, DIAMONDS, HEARTS, SPADES};
enum ranks {TWO, THREE, FOUR, FIVE, SIX,
	   	   SEVEN, EIGHT, NINE, TEN, JACK,
		   QUEEN, KING, ACE};

class Card {
	private:
		string suit;
		string rank;
	public:
		Card();
		Card(suits, ranks);//that's why there's a duplicate after 2nd shuffle
		~Card();
		void print();
		string getSuit();
		string getRank();
};

class DeckOfCards
{
	private:
		Card *newCard; //need this
		Card *ar[NO_OF_SUITS][NO_OF_RANKS];
		Card *temp[NO_OF_SUITS][NO_OF_RANKS];

	public:
		DeckOfCards(); //initialize a deck of cards
		~DeckOfCards();
		//void initialization();
		void printDeck();
		void perfectShuffle(); //shuffles the deck once
		Card *getCard(int, int);

};

bool compareTwoDecks(DeckOfCards, DeckOfCards);
void returnToOriginal();

#endif /* HW02_H_ */
