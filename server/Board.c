#include "Board.h"
#include "DevelopmentCard.h"
#include "Hexagon.h"
#include "Resource.h"
#include "Helper.h"

#include <stdlib.h>

Board* createBoard() {

    Board* board = (Board*)malloc(sizeof(Board));
    board->sheep_count = DEFAULT_RESOURCE_COUNT;
    board->brick_count = DEFAULT_RESOURCE_COUNT;
    board->wood_count = DEFAULT_RESOURCE_COUNT;
    board->ore_count = DEFAULT_RESOURCE_COUNT;
    board->wheat_count = DEFAULT_RESOURCE_COUNT;
    //14 knights, 5 victory points, 2 road building, 2 year of plenty, 2 monopoly
    for(int i=0;i<14;i++) board->devCards[i] = knight;
    for(int i=14;i<19;i++) board->devCards[i] = victory_point;
    for(int i=19;i<21;i++) board->devCards[i] = road_building;
    for(int i=21;i<23;i++) board->devCards[i] = year_of_plenty;
    for(int i=23;i<25;i++) board->devCards[i] = monopoly;
    shuffleCards(board->devCards);

    //3 brick, 3 ore, 4 wheat, 4 wood, 4 sheep 1 desert
    for(int i=0;i<3;i++) board->hexes[i] = createHexagon(brick, 0);
    for(int i=3;i<6;i++) board->hexes[i] = createHexagon(ore, 0);
    for(int i=6;i<10;i++) board->hexes[i] = createHexagon(wheat, 0);
    for(int i=10;i<14;i++) board->hexes[i] = createHexagon(wood, 0);
    for(int i=14;i<18;i++) board->hexes[i] = createHexagon(sheep, 0);
    board->hexes[18] = createHexagon(desert, 0);
    //assign numbers randomly
    int numbers[] = {8, 8, 6, 6, 9, 9, 5, 5, 10, 10, 4, 4, 11, 11, 3, 3, 12, 2};
    shuffleNumbers(numbers);
    for(int i=0;i<NUM_OF_HEXES-1;i++) board->hexes[i]->number = numbers[i];
    shuffleHexes(board->hexes);
    //assign robber to desert
    for(int i=0;i<NUM_OF_HEXES;i++) {
        if(board->hexes[i]->resource == desert) {
            board->hexes[i]->isRobbed = true;
            return board;
        }
    }
}

void destructBoard(Board* board) {
    for(int i=0;i<NUM_OF_HEXES;i++) {
        destructHexagon(board->hexes[i]);
        free(board->hexes[i]);
    }
}

void shuffleCards(DevelopmentCard* devCards) {
    size_t i;
    for(i=0;i<NUM_OF_DEV_CARDS;i++) {
        size_t j = i + rand() / (RAND_MAX / (NUM_OF_DEV_CARDS -1 ) + 1);
        DevelopmentCard t = devCards[j];
        devCards[j] = devCards[i];
        devCards[i] = t;
    }
}

void shuffleHexes(Hexagon* hexes[NUM_OF_HEXES]) {
    size_t i;
    for(i=0;i<NUM_OF_HEXES;i++) {
        size_t j = i + rand() / (RAND_MAX / (NUM_OF_HEXES -1 ) + 1);
        Resource temp_r = hexes[j]->resource;
        int num = hexes[j]->number;
        hexes[j]->resource = hexes[i]->resource;
        hexes[j]->number = hexes[i]->number;
        hexes[i]->resource = temp_r;
        hexes[i]->number = num;
        
    }
}

void shuffleNumbers(int* numbers) {
    size_t i;
    for(i=0;i<NUM_OF_NUMBERS;i++) {
        size_t j = i + rand() / (RAND_MAX / (NUM_OF_DEV_CARDS -1 ) + 1);
        int t = numbers[j];
        numbers[j] = numbers[i];
        numbers[i] = t;
    }
}