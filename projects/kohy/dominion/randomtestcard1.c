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
#include <time.h>

#define TESTCARD "great_hall"
#define NUM_TESTS 10

void asserttrue (int test, int expect){
	if (test == expect){
		printf("--> [Test PASSED!]\n");
	} 
	else {
		printf("--> [Test FAILED!]\n");
	
	}
}

int main(){
	int seed = 1000;
	int thisPlayer = 0;
	int handPos = 0;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int playedCard = 1;		// 1 Great_hall card will be played
	int drawnCard = 1;		// increase player's handsize by drawing 1 card

	int k[10] = {adventurer, smithy, council_room, village, great_hall, gardens, steward, feast, minion, embargo};
	
	struct gameState G, testG;

	int i;
	int numPlayers;
	int expectedResult;
	//int numDeckCards;
	

	printf ("\n=====================================================\n");
	printf ("	  RANDOM CARD TEST 1 Great Hall		\n");
	printf ("=====================================================\n");

	srand(time(NULL));
	for (i = 0; i < NUM_TESTS; i++){
		//random numPlayers (min.2 to max.4)
		numPlayers = rand() % 3 + 2;

		//initialize the game
		initializeGame (numPlayers, k, seed, &G);

		//random current player
		thisPlayer = rand() % numPlayers;
		//printf("%d\n", thisPlayer);

		//random number of cards in deck
		G.deckCount[thisPlayer] = rand() % (MAX_DECK - 3 + 1) + 3;

		//random number of cards in hand
		G.handCount[thisPlayer] = rand() % MAX_HAND;

		//copy gameState
		memcpy(&testG, &G, sizeof(struct gameState));

		printf ("------------------------------------------------------------------------------------\n");
		//printf("Number of Actions this player originally has: %i\n", G.numActions);
		printf("Deck1: %i \n", G.deckCount[thisPlayer]);
		//great_hall card effect	
		cardEffect(great_hall, choice1, choice2, choice3, &testG, handPos, 0);

		printf("Deck2: %i \n", testG.deckCount[thisPlayer]);
		//check num of cards in hand, supposed to get +1(drawn)-1(played) after great_hall
		expectedResult = G.handCount[thisPlayer] + drawnCard - playedCard;
		printf ("[Test1] Expected cards in HAND: %d vs. Tested cards in HAND: %d ", expectedResult, testG.handCount[thisPlayer]);
		asserttrue(testG.handCount[thisPlayer], expectedResult);

		//check num of cards in deck, supposed to have -1
		//great_hall: player gets 1 card in hand from his deck
		expectedResult = G.deckCount[thisPlayer] - 1;
		printf ("[Test2] Expected cards in DECK: %d vs. Tested cards in DECK: %d ", expectedResult, testG.deckCount[thisPlayer]);
		asserttrue(testG.deckCount[thisPlayer], expectedResult);

		//check num of actions, supposed to get +1 after great_hall
		printf ("[Test3] Expected numActions: %d vs. Tested numActions: %d ", G.numActions + 1, testG.numActions);
		asserttrue(testG.numActions, G.numActions+ 1);

		//check num of played card
		printf ("[Test4] Expected playedCard: %d vs. Tested playedCard: %d ", G.playedCardCount + playedCard, testG.playedCardCount);
		asserttrue(testG.playedCardCount, G.playedCardCount + playedCard);



	}
	return 0;
}

