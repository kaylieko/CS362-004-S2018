/* -----------------------------------------------------------------------
 * 	CS362 Assignment 3, Hyejin Ko
 *	Unittest 2: whoseTurn Function
 *
 *	unittest2: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
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

int main(){
	int player1 = 0;
	int player2 = 1;
	int player3 = 2;
	int player4 = 3;
	int seed = 1000;
	int numPlayer = 4;
	int k[10] = {adventurer, smithy, council_room, village, great_hall, gardens, steward, feast, minion, embargo};
	
	struct gameState G;

	printf ("\n===============================================================\n");
	printf ("	  		UNITTEST #2 whoseTurn():		\n");
	printf ("===============================================================\n");
    
	memset(&G, 23, sizeof(struct gameState));		// clear the game state
	initializeGame(numPlayer, k, seed, &G);			// initialize a new game

	printf("\n[Test2-1] First player should be player1.\n");
	asserttrue (whoseTurn(&G), player1);

	endTurn(&G);

	printf("[Test2-2] After player1's turn ends, its player2's turn.\n");
	asserttrue (whoseTurn(&G), player2);

	endTurn(&G);

	printf("[Test2-3] After player2's turn ends, its player3's turn.\n");
	asserttrue (whoseTurn(&G), player3);

	endTurn(&G);

	printf("[Test2-4] After player3's turn ends, its player4's turn.\n");
	asserttrue (whoseTurn(&G), player4);

	endTurn(&G);

	printf("[Test2-5] After the first round, now its player1's turn again.\n");
	asserttrue (whoseTurn(&G), player1);

	return 0;
}