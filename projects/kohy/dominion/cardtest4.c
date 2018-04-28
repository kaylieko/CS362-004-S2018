/************************************************************************
*	Assignment3 Hyejin Ko
*	cardtest4.c
* 
*	cardtest4: cardtest4.c dominion.o rngs.o
*		gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "great_hall"

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
	int numAction;
	int seed = 1000;
	int numPlayer = 2;
	int thisPlayer = 0;
	int handPos = 0;

	int k[10] = {adventurer, smithy, council_room, village, great_hall, gardens, steward, feast, minion, embargo};
	
	int playedCard = 1;		// 1 Village card will be played
	int drawCard = 1;		// increase player's handsize by drawing 1 card

	struct gameState G;
	initializeGame(numPlayer, k, seed, &G);			// initialize a new game

	printf ("\n=====================================================\n");
	printf ("	  CARDTEST #3 Great Hall		\n");
	printf ("=====================================================\n");

	int beforeGH = G.handCount[thisPlayer];				// check num of cards in this player's hand
	printf ("This player has %i starting card(s) in hand.\n", beforeGH);	

	G.hand[thisPlayer][G.handCount[thisPlayer]] = great_hall;			// add 'Smithy' card for current player:
	G.handCount[thisPlayer]++;						// now currentPlayer has +1 card (=6) in hand

	int afterGH = G.handCount[thisPlayer];				// check num of cards in this player's hand
	printf ("This player gained a village card, now he has %i card(s) in hand.\n", afterGH);	
	deckCardsNum = 	G.deckCount[thisPlayer];
	printf("Number of cards in this player's deck: %i\n", deckCardsNum);	// check number of cards in this player's deck
	numAction = G.numActions;
	printf("Number of actions this player has: %i\n\n", numAction);



	printf("[CardTest3-1] Number of cards in player's HAND.\n");
	villageEffect(thisPlayer, &G, handPos);					// play the great_hall card
	expectedResult = afterGH + drawCard - playedCard;			// expect to have 6 cards in hand (+1drawed - 1played): 6+1-1=6
	testedResult = G.handCount[thisPlayer];							
	if (testedResult != expectedResult) {
		printf ("(This player supposed to have %i cards in hand, but he has %i cards in hand instead...)\n --> ", expectedResult, testedResult);
	} else {
		printf ("(This player has %i cards in hand as expected.)\n --> ", testedResult);
	}
	asserttrue(testedResult, expectedResult); 

	printf("[CardTest3-2] Number of cards in player's DECK.\n");
	expectedResult = deckCardsNum - 1;					// great_hall: player gets 1 card in hand from his deck, so now it should be 4=5-1
	testedResult = G.deckCount[thisPlayer];					// test number of cards in player's deck
	if (testedResult != expectedResult) {
		printf ("(This player supposed to have %i cards in deck, but he has %i cards in deck instead...)\n --> ", expectedResult, testedResult);
	} else {
		printf ("(This player has %i cards in deck as expected.)\n --> ", testedResult);
	}
	asserttrue(expectedResult, testedResult);

	printf("[CardTest3-3] Great_hall card gives the player +1 actions. \n");
	expectedResult = numAction + 1;				// great_hall: gets +1 action
	testedResult = G.numActions;
	if (testedResult != expectedResult) {
		printf ("(This player supposed to have %i actions now, but he has %i action instead...)\n --> ", expectedResult, testedResult);
	} else {
		printf ("(This player has %i actions as expected.)\n --> ", testedResult);
	}
	asserttrue(expectedResult, testedResult);




	return 0;
}

