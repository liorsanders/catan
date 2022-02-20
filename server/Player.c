#include "Player.h"
#include "DevelopmentCard.h"
#include "Piece.h"
#include "Resource.h"
#include "SpecialCard.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

void addResource(Player* player, Resource resource) {
    player->resources = (Resource*)realloc(player->resources, 
    sizeof(Resource)*(player->resourcesLen+1));
    player->resources[player->resourcesLen] = resource;
    player->resourcesLen++;
}

void addSpecialCard(Player* player, SpecialCard card) {
    player->specialCards = (SpecialCard*)realloc(player->specialCards, 
    sizeof(SpecialCard) * (player->specialCardsLen+1));
    player->specialCards[player->specialCardsLen] = card;
    player->specialCardsLen++;
}

void addDevelopmentCard(Player* player, DevelopmentCard card) {
    player->developmentCards = (DevelopmentCard*)realloc(player->developmentCards, 
    sizeof(DevelopmentCard) * (player->developmentCardsLen+1));
    player->developmentCards[player->developmentCardsLen] = card;
    player->developmentCardsLen++;
}

void addAvailablePiece(Player* player, Piece piece) {
    player->availablePieces = (Piece*)realloc(player->availablePieces, 
    sizeof(Piece) * (player->availablePiecesLen+1));
    player->availablePieces[player->availablePiecesLen] = piece;
    player->availablePiecesLen++;
}

void discardDevelopmentCard(Player* player, DevelopmentCard card) {
    bool wasFound = false;
    DevelopmentCard* cards = (DevelopmentCard*)malloc(
        sizeof(DevelopmentCard) * (player->developmentCardsLen-1)
    );
    int currLen = 0;

    for(int i=0;i<player->developmentCardsLen;i++) {
        if(!wasFound && card == player->developmentCards[i]) {
            wasFound = true;
        }
        else {
            cards[currLen] = player->developmentCards[i];
            currLen++;
        }
    }
    free(player->developmentCards);
    player->developmentCards = (DevelopmentCard*)malloc(
        sizeof(DevelopmentCard) * (player->developmentCardsLen-1)
    );
    memcpy(player->developmentCards, cards, sizeof(DevelopmentCard)*currLen);
    free(cards);
}

void discardAvailablePiece(Player* player, Piece piece) {
    bool wasFound = false;
    Piece* pieces = (Piece*)malloc(
        sizeof(Piece) * (player->availablePiecesLen-1)
    );
    int currLen = 0;

    for(int i=0;i<player->availablePiecesLen;i++) {
        if(!wasFound && piece == player->availablePieces[i]) {
            wasFound = true;
        }
        else {
            pieces[currLen] = player->availablePieces[i];
            currLen++;
        }
    }
    free(player->availablePieces);
    player->availablePieces = (Piece*)malloc(
        sizeof(Piece) * (player->availablePiecesLen-1)
    );
    memcpy(player->availablePieces, pieces, sizeof(Piece)*currLen);
    free(pieces);
}

void discardResource(Player* player, Resource resource) {
    bool wasFound = false;
    Resource* resources = (Resource*)malloc(
        sizeof(Resource) * (player->resourcesLen-1)
    );
    int currLen = 0;

    for(int i=0;i<player->resourcesLen;i++) {
        if(!wasFound && resource == player->resources[i]) {
            wasFound = true;
        }
        else {
            resources[currLen] = player->resources[i];
            currLen++;
        }
    }
    free(player->resources);
    player->resources = (Resource*)malloc(
        sizeof(Resource) * (player->resourcesLen-1)
    );
    memcpy(player->resources, resources, sizeof(Resource)*currLen);
    free(resources);
}

void discardSpecialCard(Player* player, SpecialCard card) {
    bool wasFound = false;
    SpecialCard* cards = (SpecialCard*)malloc(
        sizeof(SpecialCard) * (player->specialCardsLen-1)
    );
    int currLen = 0;

    for(int i=0;i<player->specialCardsLen;i++) {
        if(!wasFound && card == player->specialCards[i]) {
            wasFound = true;
        }
        else {
            cards[currLen] = player->specialCards[i];
            currLen++;
        }
    }
    free(player->specialCards);
    player->specialCards = (SpecialCard*)malloc(
        sizeof(SpecialCard) * (player->specialCardsLen-1)
    );
    memcpy(player->specialCards, cards, sizeof(SpecialCard)*currLen);
    free(cards);
}

void destructPlayer(Player* player) {
    if(player->availablePiecesLen) free(player->availablePieces);
    if(player->developmentCardsLen) free(player->developmentCards);
    if(player->specialCardsLen) free(player->specialCards);
    if(player->resourcesLen) free(player->resources);
}