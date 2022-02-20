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
}Player;

#endif