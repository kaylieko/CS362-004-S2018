/************************************************************************
*	Assignment3 Hyejin Ko
*	cardtest3.c
* 
*	cardtest3: cardtest3.c dominion.o rngs.o
*		gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"

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
	int handCardsNum;
	int numAction;	
	int deckTreasureCounter = 0;
	int handTreasureCounter = 0;
	int card;
	int i;

	int seed = 1000;
	int numPlayer = 2;
	int thisPlayer = 0;

	int handPos = 0;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;

	int k[10] = {adventurer, smithy, council_room, village, great_hall, gardens, steward, feast, minion, embargo};
	
	int playedCard = 1;		// 1 village card will be played
	int drawCard = 1;		// increase player's handsize by drawing 1 card

	struct gameState G;
	memset(&G,23,sizeof(struct gameState));

	initializeGame(numPlayer, k, seed, &G);			// initialize a new game

	printf ("\n=====================================================\n");
	printf ("	  CARDTEST #3 Village		\n");
	printf ("=====================================================\n");

	printf("******* [CardTest3] Check Initial Game Status *******\n");

	// check num of cards in this player's default hand
	handCardsNum = G.handCount[thisPlayer];							
	printf ("This player has %i starting card(s) in HAND. \n", handCardsNum);	

	// check number of cards in this player's default deck
	deckCardsNum = 	G.deckCount[thisPlayer];
	printf("his player has %i starting card(s) in DECK.\n", deckCardsNum);	

	// check num of treasure cards in this player's default hand
    for (i = 0; i < G.handCount[thisPlayer]; i++) {							
        card = G.hand[thisPlayer][i];
        if (card == copper || card == silver || card == gold) {
            handTreasureCounter++;
        }
        //printf ("hand: %i\n", card);
    }
    printf("Number of TREASURE cards in player's default HAND: %i\n", handTreasureCounter);

    // check num of treasure cards in this player's default deck
    for (i = 0; i < G.deckCount[thisPlayer]; i++) {							
        card = G.deck[thisPlayer][i];
        if (card == copper || card == silver || card == gold) {
            deckTreasureCounter++;
        }
        //printf ("deck: %i\n", card);
    }
    printf("Number of TREASURE cards in player's default DECK: %i\n", deckTreasureCounter);

    // check default num of actions
	numAction = G.numActions;
	printf("Number of ACTIONS this player has: %i\n\n", numAction);
    



	// Village card effect,	
	cardEffect(village, choice1, choice2, choice3, &G, handPos, 0);




	printf("*******CardTest3-1] Number of cards in player's HAND.*******\n");
	// expect to have 5 cards in hand (+1drawed - 1played): 5+1-1=5			
	expectedResult = handCardsNum + drawCard - playedCard;			
	testedResult = G.handCount[thisPlayer];							
	if (testedResult != expectedResult) {
		printf ("(This player supposed to have %i cards in hand, but he has %i cards in hand instead...)\n --> ", expectedResult, testedResult);
	} else {
		printf ("(This player has %i cards in hand as expected.)\n --> ", testedResult);
	}
	asserttrue(testedResult, expectedResult); 


	printf("*******[CardTest3-2] Number of cards in player's DECK.*******\n");
	// village: player gets 1 card in hand from his deck, so now it should be 4=5-1
	expectedResult = deckCardsNum - 1;
	// test number of cards in player's deck					
	testedResult = G.deckCount[thisPlayer];					
	if (testedResult != expectedResult) {
		printf ("(This player supposed to have %i cards in deck, but he has %i cards in deck instead...)\n --> ", expectedResult, testedResult);
	} else {
		printf ("(This player has %i cards in deck as expected.)\n --> ", testedResult);
	}
	asserttrue(expectedResult, testedResult);


	printf("*******[CardTest3-3] Village card gives the player +2 actions.*******\n");
	// village: gets +2 actions
	expectedResult = numAction + 2;				
	testedResult = G.numActions;
	if (testedResult != expectedResult) {
		printf ("(This player supposed to have %i actions now, but he has %i action instead...)\n --> ", expectedResult, testedResult);
	} else {
		printf ("(This player has %i actions as expected.)\n --> ", testedResult);
	}
	asserttrue(expectedResult, testedResult);




	return 0;
}

