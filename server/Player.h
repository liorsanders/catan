#ifndef PLAYER_H
#define PLAYER_H

#include "DevelopmentCard.h"
#include "Resource.h"
#include "SpecialCard.h"
#include "Piece.h"

typedef enum {
    red,
    blue,
    orange,
    white
}Color;

typedef struct {
    Color color;
    Resource* resources;
    DevelopmentCard* developmentCards;
    SpecialCard* specialCards;
    Piece* availablePieces;
    unsigned int availablePiecesLen;
    unsigned int specialCardsLen;
    unsigned int developmentCardsLen;
    unsigned int resourcesLen;
}Player;

Player* createPlayer(Color color, Resource* resources, unsigned int numResources);
void addResource(Player* player, Resource resource);
void addSpecialCard(Player* player, SpecialCard card);
void addDevelopmentCard(Player* player, DevelopmentCard card);
void discardDevelopmentCard(Player* player, DevelopmentCard card);
void discardResource(Player* player, Resource resource);
void discardSpecialCard(Player* player, SpecialCard card);
void addAvailablePiece(Player* player, Piece piece);
void discardAvailablePiece(Player* player, Piece piece);

#endif