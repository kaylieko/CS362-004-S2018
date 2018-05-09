/************************************************************************
*	Assignment4 Hyejin Ko
*	randomtestadventurer.c Adventurer
* 
*	randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
*		gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
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

#define TESTCARD "adventurer"
#define NUM_TESTS 1000
#define NUM_CARDS 27


int main(){
	int seed = 1000;
	int thisPlayer = 0;
	int handPos = 0;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;

	int k[10] = {adventurer, smithy, council_room, village, great_hall, gardens, steward, feast, minion, embargo};

	struct gameState G;

	int i, j, m;
	int numPlayers;
	int treasureHand;
	int postTreasureHand;
	int error = 0;

	printf ("\n===============================================================\n");
	printf ("	  	RANDOMTEST Adventurer		\n");
	printf ("===============================================================\n");

	srand(time(NULL));

	for (i = 0; i < NUM_TESTS; i++){
		numPlayers = rand() % 3 + 2;	//random numPlayers (min.2 to max.4)

		initializeGame (numPlayers, k, seed, &G);	//initialize the game

		//set random gamestate
		thisPlayer = rand() % numPlayers;
		G.whoseTurn = thisPlayer;
		G.handCount[thisPlayer] = rand() % MAX_HAND;
		G.deckCount[thisPlayer] = rand() % MAX_DECK;
	
		//set player's deck with random cards
		for(j = 0; j < G.deckCount[thisPlayer]; j++){			
			//put 25% random chance of random treasure cards (#4copper, 5silver, 6gold) in deck
			if (rand() % 4 == 0){
				G.deck[thisPlayer][j] = rand() % 3 + 4;
			} 
			//put cards from k[10] array into the deck
			else {
				G.deck[thisPlayer][j] = k[rand()%10];
			}
		}

		//set player's hand with random cards
		treasureHand = 0;
		for(m = 0; m < G.handCount[thisPlayer]; m++){
			G.hand[thisPlayer][m] = rand() % NUM_CARDS;
            if(G.hand[thisPlayer][m] == copper || G.hand[thisPlayer][m] == silver || G.hand[thisPlayer][m] == gold){
                treasureHand++;
            }
        }
		// at least one adventurer is present in current player's hand
    	G.hand[thisPlayer][0] = adventurer;


		//adventurer card effect	
		cardEffect(adventurer, choice1, choice2, choice3, &G, handPos, 0);



		postTreasureHand = 0;
		for(m = 0; m < G.handCount[thisPlayer]; m++){
            if(G.hand[thisPlayer][m] == copper || G.hand[thisPlayer][m] == silver || G.hand[thisPlayer][m] == gold){
                postTreasureHand++;
            }
        }

		printf ("[Result] Expected treasures in HAND: %d vs. Tested treasures in HAND: %d ", treasureHand + 2, postTreasureHand);
		//asserttrue(postTreasureHand, treasureHand + 2);
		if (postTreasureHand != treasureHand + 2){
			error++;
			printf("[Error]");
		} 
		printf("\n");
	}
	printf("Total Errors: %d \n", error);
	return 0;
}

