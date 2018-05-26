/* -----------------------------------------------------------------------
 * 	CS362 Assignment 3, Hyejin Ko
 *	Unittest 1: supplyCount Function
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 * ---------------------------------------------------------------------*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"


void asserttrue (int test, int expect){
	if (test == expect){
		printf("Test PASSED! Supply counted correctly.\n\n");
	} 
	else {
		printf("Test FAILED! Supply counted incorrectly.\n\n");
	}
}

int main () {

	int numPlayer = 2;
	int seed = 1000; 
	int returnStatus;
	int k[10] = {adventurer, smithy, council_room, village, great_hall, gardens, steward, feast, minion, embargo};

	struct gameState G;

	printf ("\n====================================================================\n");
	printf ("	  	UNITTEST #1 supplyCount():		\n");
	printf ("====================================================================\n");

	printf("\n[Test1-1] Supply count of a Province card when 2 players play a game\n");
	memset(&G, 23, sizeof(struct gameState));		// clear the game state
	initializeGame(numPlayer, k, seed, &G);			// initialize a new game
	returnStatus = G.supplyCount[province];
	asserttrue(supplyCount(province, &G), returnStatus);

	printf("[Test1-2] Supply count of a Province card when 3 players play a game\n");
	numPlayer = 3;
	initializeGame(numPlayer, k, seed, &G);		// initialize a new game
	returnStatus = G.supplyCount[province];
	asserttrue(supplyCount(province, &G), returnStatus);
	return 0;
}