#include "Player.h"
#include "Piece.h"
#include <stdlib.h>

Player* createPlayer(Color color, Resource* resources, unsigned int numResources) {
    Player* player = (Player*)malloc(sizeof(Player));
    
    player->color = color;

    player->availablePiecesLen = 0;
    player->developmentCardsLen = 0;
    player->specialCardsLen = 0;
    player->resourcesLen = 0;

    player->availablePieces = NULL;
    player->specialCards = NULL;
    player->developmentCards = NULL;
    player->resources = NULL;

    //5 settlements
    for(unsigned int i=0;i<5;i++) addAvailablePiece(player, settlement_piece); 
    // 4 cities
    for(unsigned int i=0;i<4;i++) addAvailablePiece(player, city_piece);
    // 15 roads
    for(unsigned int i=0;i<15;i++) addAvailablePiece(player, road_piece);
    // initialize resources
    for(unsigned int i=0;i<numResources;i++) addResource(player, resources[i]);

    return player;
}