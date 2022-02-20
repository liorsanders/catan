#ifndef BOARD_H 
#define BOARD_H 

#include "DevelopmentCard.h"
#include "Hexagon.h"
#include "Player.h"
#include "Resource.h"

#define NUM_OF_HEXES 19
#define NUM_OF_RESOURCES 95
#define NUM_OF_NUMBERS 18
#define NUM_OF_DEV_CARDS 25
#define DEFAULT_RESOURCE_COUNT 20

typedef struct {
    Hexagon* hexes[NUM_OF_HEXES]; //from top to bottom
    unsigned int wheat_count;
    unsigned int wood_count;
    unsigned int ore_count;
    unsigned int sheep_count;
    unsigned int brick_count;
    DevelopmentCard devCards[NUM_OF_DEV_CARDS];
}Board;

Board* createBoard();
void shuffleCards(DevelopmentCard* devCards);
void shuffleHexes(Hexagon* hexes[NUM_OF_HEXES]);
void shuffleNumbers(int* numbers);
void destructBoard(Board* board);

#endif 