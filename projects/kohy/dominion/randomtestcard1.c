/************************************************************************
*	Assignment4 Hyejin Ko
*	randomtestcard1.c Great Hall
* 
*	randomtestcard1: randomtestcard1.c dominion.o rngs.o
*		gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

#define TESTCARD "great_hall"
#define NUM_TESTS 1000

void asserttrue (int test, int expect){
	if (test == expect){
		printf("--> [Test PASSED!]\n");
	} 
	else {
		printf("--> [Test FAILED!]\n");
	}
}

int main(){
	int thisPlayer = 0;
	int handPos = 0;
	int discardedCard = 1;		// 1 Great_hall card will be played
	int drawnCard = 1;		// increase player's handsize by drawing 1 card

	int k[10] = {adventurer, smithy, council_room, village, great_hall, gardens, steward, feast, minion, embargo};
	
	struct gameState G, testG;

	int i;
	int numPlayers;
	int seed;
	int numDeck;
	int expectedResult;

	printf ("\n=====================================================\n");
	printf ("	  RANDOM CARD TEST 1 Great Hall		\n");
	printf ("=====================================================\n");

	srand(time(NULL));
	for (i = 0; i < NUM_TESTS; i++){
		//random numPlayers (min.2 to max.4)
		numPlayers = rand() % 3 + 2;
		//random seed (0 to 999)
		seed = rand() % 1000; 

		//initialize the game
		initializeGame (numPlayers, k, seed, &G);

		thisPlayer = rand() % numPlayers;
		G.deckCount[thisPlayer] = rand() % MAX_DECK;
		G.handCount[thisPlayer] = rand() % MAX_HAND;

		//copy original gameState G to testG
		memcpy(&test, &G, sizeof(struct gameState));
		//decide the random current player
		
		
		// add a great_hall card to current player's hand
		//testG.hand[thisPlayer][testG.handCount[thisPlayer]] = great_hall;
		//testG.handCount[thisPlayer]++;
		//asserttrue(G.handCount[thisPlayer] + 1, testG.handCount[thisPlayer]);

		//call the card function to test
		great_HallEffect(thisPlayer, &testG, handPos);
	
		

		//check num of cards in hand, supposed to get +1(drawn)-1(played) after great_hall
		expectedResult = G.handCount[thisPlayer] + drawnCard - discardedCard;
		printf ("[Test1] Expected cards in HAND: %d vs. Tested cards in HAND: %d ", expectedResult, testG.handCount[thisPlayer]);
		asserttest(testG.handCount[thisPlayer], expectedResult);

		//check num of cards in deck, supposed to have -1
		//great_hall: player gets 1 card in hand from his deck
		printf ("[Test2] Expected cards in DECK: %d vs. Tested cards in DECK: %d ", G.deckCount[thisPlayer] - 1, testG.deckCount[thisPlayer]);
		asserttest(testG.handCount[thisPlayer], G.deckCount[thisPlayer] - 1);

		//check num of actions, supposed to get +1 after great_hall
		printf ("[Test3] Expected numActions: %d vs. Tested numActions: %d ", G.numActions + 1, testG.numActions);
		asserttrue(testG.numActions, G.numActions+ 1);

		//check num of actions, supposed to get +1 after great_hall
		printf ("[Test4] Expected discard: %d vs. Tested discard: %d ", G.playedCardCount + discardedCard, testG.playedCardCount);
		asserttrue(testG.playedCardCount, G.playedCardCount + discardedCard);
	}

	return 0;
}

/* Great Hall in Dominion
int great_HallEffect(int currentPlayer, struct gameState *state, int handPos){
	//+1 Card
  	drawCard(currentPlayer, state); 

  	//+1 Actions
  	//*Introduce a Bug: gain +2 actions instead of +1
  	state->numActions = state->numActions + 2;     

  	//discard card from hand
  	discardCard(handPos, currentPlayer, state, 0);
  	return 0;
}*/

