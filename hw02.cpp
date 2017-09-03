/********************************
 * STUDENT NAME : Yuliy Dubovyk
 * STUDENT ID   : 1073327
 * CLASS        : 1C
 * ASSIGNMENT   : HW01
 * PROFESSOR    : John Kath
 * DUE DATE     : 8/31
 ********************************/

#include "hw02.h"

int main()
{
	DeckOfCards deck1;
	DeckOfCards deck2;

	//initialization - all ranks are shuffles by suit
	//deck1.initialization();
	deck1.printDeck();

	//1st shuffle works
	deck1.perfectShuffle();
	deck1.printDeck();

/*	deck1.perfectShuffle();
	deck1.printDeck();*/



/*	bool compResult = compareTwoDecks(deck1, deck2);
	if(compResult)
	{
		cout << "\n***These two decks ARE different\n";
	}
	else
	{
		cout << "\n***These two decks are the same\n";
	}*/

	//returnToOriginal();

	return 0;
}

