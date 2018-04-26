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
#include "rngs.h"


void asserttrue (int test, int expect){
	if (test == expect){
		printf("Supply counted correctly. Test PASSED!\n\n");
	} 
	else {
		printf("Test FAILED!\n\n");
	}
}

int main () {

	int numPlayer = 2;
	int seed = 1000; 
	int returnStatus;
	int k[10] = {adventurer, smithy, council_room, village, great_hall, gardens, steward, feast, minion, embargo};

	struct gameState G1;
	struct gameState G2;

	printf ("\n=====================================================\n");
	printf ("	  UNITTEST #1 supplyCount():		\n");
	printf ("=====================================================\n");

	printf("[Test1-1] Supply count of a Province card when 2 players play a game\n");
	memset(&G1, 23, sizeof(struct gameState));		// clear the game state
	initializeGame(numPlayer, k, seed, &G1);		// initialize a new game
	G1.supplyCount[province] = 8;
	returnStatus = 8;
	asserttrue(supplyCount(province, &G1), returnStatus);

	printf("[Test1-2] Supply count of a Province card when 3 players play a game\n");
	numPlayer = 3;
	memset(&G2, 23, sizeof(struct gameState));		// clear the game state
	initializeGame(numPlayer, k, seed, &G2);		// initialize a new game
	G2.supplyCount[province] = 12;
	returnStatus = 12;
	asserttrue(supplyCount(province, &G2), returnStatus);

  return 0;
}