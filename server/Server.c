#include "Board.h"
#include "Color.h"
#include "Player.h"
#include "Helper.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

Color* getOrder(Player** players, int len);
Player** getPlayers(int numOfPlayers);
void destructPlayers(Player** players, int len);

int main() {
    srand(time(NULL));
    Board* board = createBoard();
    int numOfPlayers = 0;
    while(numOfPlayers < 2 || numOfPlayers > 4) {
        numOfPlayers = getNumber("enter number of players: ");
    }
    Player** players = getPlayers(numOfPlayers);
    Color* order = getOrder(players, numOfPlayers);



    destructPlayers(players, numOfPlayers);
    destructBoard(board);
    free(players);
    free(board);
    free(order);
}

Player** getPlayers(int numOfPlayers) {
    Player** players = (Player**)malloc(sizeof(Player*) * numOfPlayers);
    for(int i=0;i<numOfPlayers;i++) {
        printColors();
        Color color = (Color)getNumber("enter color: ");
        players[i] = createPlayer(color, NULL, 0);
    }
    return players;
}

void destructPlayers(Player** players, int len) {
    for(int i=0;i<len;i++) {
        destructPlayer(players[i]);
        free(players[i]);
    }
}


//get random color order ex: {blue, red, white}
Color* getOrder(Player** players, int len) {
    // rollednt* getOrde
    Color* order = (Color*)malloc(sizeof(Color)*len);
    for(int i=0;i<len;i++) order[i] = players[i]->color;
    shuffleNumbers((int*)order);
    return order;
}