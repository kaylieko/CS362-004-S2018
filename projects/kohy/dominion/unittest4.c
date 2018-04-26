/* -----------------------------------------------------------------------
 * 	CS362 Assignment 3, Hyejin Ko
 *	Unittest 4: numHandCards Function
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
 * ---------------------------------------------------------------------*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"


void asserttrue (int test, int expect){
	if (test == expect){
		printf("Test PASSED!\n\n");
	} 
	else {
		printf("Test FAILED!\n\n");
	}
}

int main () {
	int returnStatus;
	int numPlayer = 3;
	int player;
	int thisPlayer = 0;
	int seed = 1000; 
	int k[10] = {adventurer, smithy, council_room, village, great_hall, gardens, steward, feast, minion, embargo};

	struct gameState G;

	printf ("\n=====================================================\n");
	printf ("	  UNITTEST #4 numHandCards():		\n");
	printf ("=====================================================\n");

	memset(&G, 23, sizeof(struct gameState));		// clear the game state
	initializeGame(numPlayer, k, seed, &G);			// initialize a new game
	int currentPlayer = whoseTurn(&G);			// determining the player

	printf("[Test4-1] Beginning of the game, Every player has 5 cards in hand \n\n");
	for (player = 0; player < 3; player++){
		returnStatus = G.handCount[player];
		if (numHandCards(&G) == returnStatus){
			printf ("Player%i", player);
			printf (" has 5 cards in hand. ");
		}
		asserttrue(numHandCards(&G), returnStatus);
		G.whoseTurn = currentPlayer + 1;
	}
	
	printf("\n[Test4-2] Testing a player's numHandCards after add/subtract of a card. \n\n");
	memset(&G, 23, sizeof(struct gameState));		// clear the game state
	initializeGame(numPlayer, k, seed, &G);			// initialize a new game
	G.handCount[thisPlayer]--;
	returnStatus = 4;
	if (numHandCards(&G) == returnStatus){
		printf ("Subtract 1 card: this player now has %i", returnStatus);
		printf (" cards in hand. ");
	}
	asserttrue(numHandCards(&G), returnStatus);
	G.handCount[thisPlayer]++;
	returnStatus = 5;
	if (numHandCards(&G) == returnStatus){
		printf ("Add 1 card: this player now has %i", returnStatus);
		printf (" cards in hand. ");
	}
	asserttrue(numHandCards(&G), returnStatus);

	printf("\n[Test4-3] Testing a player's numHandCards after drawCard. \n\n");
	memset(&G, 23, sizeof(struct gameState));		// clear the game state
	initializeGame(numPlayer, k, seed, &G);			// initialize a new game
	drawCard(thisPlayer, &G);			// to draw is to take a card from your deck and put it into your hand.
	returnStatus = 6;			// so now, thisPlayer has 6 cards
	if (numHandCards(&G) == returnStatus){
		printf ("Draw card: this player now has %i", returnStatus);
		printf (" cards in hand. ");
	}								
	asserttrue(numHandCards(&G), returnStatus);


  return 0;
}