#include "DevelopmentCard.h"
#include "Piece.h"
#include "Player.h"
#include "Resource.h"
#include "SpecialCard.h"
#include "Hexagon.h"
#include "Board.h"
#include "Helper.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
    srand(time(NULL));
    Board* board = createBoard();
    int numOfPlayers;
    while(true) {
        numOfPlayers = getNumber("enter number of players (between 2 to 4): ");
        if(numOfPlayers >= 2 && numOfPlayers <= 4) break;
    }
    Player** players = (Player**)malloc(sizeof(Player*)*numOfPlayers);


    free(players);
    destructBoard(board);
    free(board);
    return 0;
}