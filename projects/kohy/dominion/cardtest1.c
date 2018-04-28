/************************************************************************
*	Assignment3 Hyejin Ko
*	cardtest1.c
* 
*	cardtest1: cardtest1.c dominion.o rngs.o
*		gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

void asserttrue (int test, int expect){
	if (test == expect){
		printf("Test PASSED!\n\n");
	} 
	else {
		printf("Test FAILED!\n\n");
	}
}

int main(){
	int expectedResult;
	int testedResult;
	int deckCardsNum;
	int seed = 1000;
	int numPlayer = 2;
	int thisPlayer = 0;
	int handPos = 0;

	int k[10] = {adventurer, smithy, council_room, village, great_hall, gardens, steward, feast, minion, embargo};
	
	int playedCard = 1;		// a smithy card will be played
	int drawCards = 3;		// increase player's handsize by drawing 3 cards

	struct gameState G;
	initializeGame(numPlayer, k, seed, &G);			// initialize a new game

	printf ("\n=====================================================\n");
	printf ("	  CARDTEST #1 Smithy		\n");
	printf ("=====================================================\n");

	int beforeSmithy = G.handCount[thisPlayer];						// check num of cards in this player's hand
	printf ("This player has %i card(s) in hand.\n", beforeSmithy);	

	G.hand[thisPlayer][G.handCount[thisPlayer]] = smithy;			// add 'Smithy' card for current player:
	G.handCount[thisPlayer]++;										// now currentPlayer has +1 card (=6) in hand

	int afterSmithy = G.handCount[thisPlayer];						// check num of cards in this player's hand
	printf ("This player gained a smithy card, now he has %i card(s) in hand.\n", afterSmithy);	
	deckCardsNum = 	G.deckCount[thisPlayer];
	printf("Number of cards in this player's deck: %i\n\n", deckCardsNum);	// check number of cards in this player's deck

	printf("[CardTest1-1] Number of cards in player's HAND.\n");
	smithyEffect(thisPlayer, &G, handPos);							// play the smithy card
	expectedResult = afterSmithy + drawCards - playedCard;			// expect to have +2 cards (+3drawed - 1played): 6+3-1=8
	testedResult = G.handCount[thisPlayer];							
	if (testedResult != expectedResult) {
		printf ("(This player supposed to have %i cards in hand, but he has %i cards in hand instead...)\n --> ", expectedResult, testedResult);
	} else {
		printf ("(This player has %i cards in hand as expected.)\n --> ", testedResult);
	}
	asserttrue(testedResult, expectedResult); 
		

	printf("[CardTest1-2] Number of cards in player's DECK.\n");
	expectedResult = deckCardsNum - 3;							// smithy: player gets 3 cards in hand from his deck
	testedResult = G.deckCount[thisPlayer];						// test number of cards in player's deck
	if (testedResult != expectedResult) {
		printf ("(This player supposed to have %i cards in deck, but he has %i cards in deck instead...)\n --> ", expectedResult, testedResult);
	} else {
		printf ("(This player has %i cards in deck as expected.)\n --> ", testedResult);
	}
    asserttrue(expectedResult, testedResult);


	return 0;
}

