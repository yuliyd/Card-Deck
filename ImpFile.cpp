/********************************
 * STUDENT NAME : Yuliy Dubovyk
 * STUDENT ID   : 1073327
 * CLASS        : 1C
 * ASSIGNMENT   : HW02
 * PROFESSOR    : John Kath
 * DUE DATE     : 8/31
 ********************************/

#include "hw02.h"

Card :: Card()
{

}

//that's why there's a duplicate after the 2nd shuffle. They pass in the coordinates.
Card :: Card(suits cardSuit, ranks cardRank)
{
	switch(cardSuit)
	{
		case CLUBS:
			suit = "Clubs";
			break;
		case DIAMONDS:
			suit = "Diamonds";
			break;
		case HEARTS:
			suit = "Hearts";
			break;
		case SPADES:
			suit = "Spades";
			break;
		default:
			cout << "\n***Default Constructor Error, Suits***\n";
			break;
	}

	switch(cardRank)
	{
		case TWO:
			rank = "Two";
			break;
		case THREE:
			rank = "Three";
			break;
		case FOUR:
			rank = "Four";
			break;
		case FIVE:
			rank = "Five";
			break;
		case SIX:
			rank = "Six";
			break;
		case SEVEN:
			rank = "Seven";
			break;
		case EIGHT:
			rank = "Eight";
			break;
		case NINE:
			rank = "Nine";
			break;
		case TEN:
			rank = "Ten";
			break;
		case JACK:
			rank = "Jack";
			break;
		case QUEEN:
			rank = "Queen";
			break;
		case KING:
			rank = "King";
			break;
		case ACE:
			rank = "Ace";
			break;

		default:
			cout << "\n***Default Constructor Error, Ranks***\n";
			break;
	}
}

Card :: ~Card()
{

}

string Card :: getSuit()
{
	return suit;
}

string Card :: getRank()
{
	return rank;
}

void Card :: print()
{
	string suitVal = getSuit();
	string rankVal = getRank();

	cout << rankVal << " of " << suitVal;
}

DeckOfCards :: DeckOfCards()
{
	for(int i=0;i<NO_OF_SUITS;i++) //for card suits
	{
		for(int j=0;j<NO_OF_RANKS;j++)//for card ranks
		{
			suits suitsVar = (suits)i; //converts counter i to enum and assigns its value to suitsObj
			ranks ranksVar = (ranks)j; //converts counter j to enum and assigns its value to ranksObj

			 /* w/each iteration of the for loop creates a new object and
			 * passes in suitsVar and ranksVar*/
			Card *newCard = new Card(suitsVar, ranksVar); //!!!!!!!POSSIBLE ERROR SOURCE
			ar[i][j] = newCard; //assigns the newCard pointer to an array of pointers
		}
	}
}

DeckOfCards :: ~DeckOfCards()
{
/*	for(int i=0;i<NO_OF_SUITS;i++) //for card suits
	{
		for(int j=0;j<NO_OF_RANKS;j++)//for card ranks
		{
			delete ar[i][j];
			delete temp[i][j];
		}
	}
	delete newCard;
	newCard = NULL;*/
}

/*void DeckOfCards :: initialization()
{

}*/

Card* DeckOfCards :: getCard(int i, int j)
{
	Card *newCard = new Card;
	newCard = ar[i][j];
	return newCard;
}

void DeckOfCards :: printDeck()
{
	for(int i=0;i<NO_OF_SUITS;i++) //for card suits
	{
		for(int j=0;j<NO_OF_RANKS;j++)//for card ranks
		{
			cout << "#" << i*NO_OF_RANKS + j +1 << '('
				 << i << ',' << j << "): "; //outputs the order of the card in the deck
			ar[i][j]->print(); //prints the card
			cout << endl;
		}
		cout << endl;
	}
}

/************************************************************************************
 * In a perfect shuffle, the deck is broken exactly in half and rearranged
 * so that the first card is followed by the 27th card, followed by the second card,
 * followed by the 28th card, and so on.
 * **********************************************************************************/
void DeckOfCards :: perfectShuffle() //Duplicate issue has to do with the "ar" array not saving progress.
{
	int a = 6;
	int b = 6;
	int c = 2;
	int d = 0;
	cout << "\n\n***A Perfect Shuffle Took Place...***\n\n";
	for(int i = 0; i < NO_OF_SUITS; i++) //not (/2)
	{
		for(int j = 0; j < NO_OF_RANKS; j++)
		{
			cout << '(' << i << ',' << j << "): ";

			//todo !!!check for 2 - out of bounds
			if(i%2 == 0)//to work on even rows and capture 13 numbers from 0,0-0,6 and 2,0-2,6 into a single array
			{
				//adjusting
				if(i==2)
				{
					c=1;
				}
				else
				{
					c=i;
				}
				//end adjusting

				if(j%2 == 0)//if rank is even  //<<--look into the mod formula
				{

					temp[i][j] = ar[c][j/2];
				}
				else //if odd
				{
					//!!!the error is here because when i=2 -> it's trying to take from ar[4][j]
					temp[i][j] = ar[c+2][(j-1)/2];//i+2 to adjust for the rows, (j-1)/2 is a brilliant formula
				}
			}
			else
			{
				//adjusting
				if(i==2)
				{
					d=1;
				}
				else
				{
					d=i;
				}
				//end adjusting

				if(j%2 == 0)//if rank is even  //<<--look into the mod formula
				{
					temp[i][j] = ar[i+1][(j+(a--))];
				}
				else //if odd
				{
					temp[i][j] = ar[i-1][(j+(b--))];//i+2 to adjust for the rows, (j-1)/2 is a brilliant formula
				}
			}
			temp[i][j]->print(); //THE ERROR occurs at the TEMP array level.
			//cout << endl;
		}
		cout << "\n***i++***\n";
	}

	//populates the default array from the temporary array;
	for(int i = 0; i < NO_OF_SUITS; i++) //maybe this step isn't saving progress
	{
		for(int j = 0; j < NO_OF_RANKS; j++)
		{
			ar[i][j] = temp[i][j];
		}
	}
}

//compares two decks, if there's at least 1 instance of repective suit&rank not matching - returns false
bool compareTwoDecks(DeckOfCards deck1, DeckOfCards deck2)
{
	bool areDifferent = false;
	Card *card1 = new Card;
	Card *card2 = new Card;

	for(int i = 0; i < NO_OF_SUITS; i++)
	{
		for(int j = 0; j < NO_OF_RANKS; j++)
		{
			card1 = deck1.getCard(i,j);
			card2 = deck2.getCard(i,j);

			string card1Suit = card1->getSuit();
			string card1Rank = card1->getRank();
			string card2Suit = card2->getSuit();
			string card2Rank = card2->getRank();

			if(card1Suit != card2Suit || card1Rank != card2Rank)
			{
				areDifferent = true;
			}
		}
	}
	return areDifferent;
}

void returnToOriginal()
{
	int count = 0; //counter of shuffles
	bool isDiff = false;
	DeckOfCards original;
	DeckOfCards testDeck;


	do
	{
		testDeck.perfectShuffle();
		testDeck.printDeck();
		isDiff = compareTwoDecks(original, testDeck);
		++count;
	}while(isDiff || count == 10);
	cout << "Takes this many tries: " << count;
}
