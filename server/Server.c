#include "DevelopmentCard.h"
#include "Piece.h"
#include "Player.h"
#include "Resource.h"
#include "SpecialCard.h"

#include <stdlib.h>
#include <stdio.h>

int main() {
    Resource* resources = (Resource*)malloc(sizeof(Resource)*3);
    resources[0] = wheat;
    resources[1] = sheep;
    resources[2] = ore;
    printf("created\n");
    Player* redPlayer = createPlayer(red, resources, 3);
    Player* bluePlayer = createPlayer(blue, resources, 3);
    printf("adding\n");
    addAvailablePiece(redPlayer, settlement_piece);
    discardAvailablePiece(redPlayer, settlement_piece);
    addResource(redPlayer, wheat);
    addResource(redPlayer, wood);
    discardResource(redPlayer, wood);
    addSpecialCard(bluePlayer, longest_road);
    discardSpecialCard(bluePlayer, longest_road);
    addDevelopmentCard(bluePlayer, knight);
    discardDevelopmentCard(bluePlayer, knight);

    free(resources);
    destructPlayer(redPlayer);
    destructPlayer(bluePlayer);
    free(redPlayer);
    free(bluePlayer);
    printf("destroyed\n");
}