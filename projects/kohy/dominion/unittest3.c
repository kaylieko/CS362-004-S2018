/* -----------------------------------------------------------------------
 * 	CS362 Assignment 3, Hyejin Ko
 *	Unittest 3: isGameOver Function
 *
 *	unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
 * ---------------------------------------------------------------------*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

void asserttrue (int test, int expect){
	if (test == expect){
		printf("Test PASSED! \n\n");
	} 
	else {
		printf("Test FAILED!\n\n");
	}
}

int main(){
	int seed = 1000;
	int numPlayer = 2;
	int returnStatus;
	int k[10] = {adventurer, smithy, council_room, village, great_hall, gardens, steward, feast, minion, embargo};
	
	struct gameState G;

	printf ("\n====================================================================\n");
	printf ("	  		UNITTEST #3 isGameOver():		\n");
	printf ("====================================================================\n");
    
	memset(&G, 23, sizeof(struct gameState));		// clear the game state
	initializeGame(numPlayer, k, seed, &G);			// initialize a new game

	printf("[Test3-1] If stack of Province cards is NOT empty and one supply pile is at 0, the game Not ends.\n");
	G.supplyCount[province] = 1;
	G.supplyCount[smithy] = 0;
	returnStatus = 0;
	if(isGameOver(&G) == returnStatus) {
		printf ("The game keeps going.");
	}
	asserttrue(isGameOver(&G), returnStatus);
	

	printf("[Test3-2] If stack of Province cards is empty, the game ends.\n");
	G.supplyCount[province] = 0;
	returnStatus = 1;
	if(isGameOver(&G) == returnStatus) {
		printf ("The game ends successfully.");
	}
	asserttrue(isGameOver(&G), returnStatus);

	printf("[Test3-3] If three supply piles are at 0, the game ends.\n");
  	G.supplyCount[province] = 2;
  	G.supplyCount[village] = 0;
  	G.supplyCount[smithy] = 0;
  	G.supplyCount[adventurer] = 0;
    returnStatus = 1;
	if(isGameOver(&G) == returnStatus) {
		printf ("The game ends successfully.");
	}
	asserttrue(isGameOver(&G), returnStatus);


	return 0;
}