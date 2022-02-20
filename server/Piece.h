#ifndef PIECE_H
#define PIECE_H 

#include "Color.h"

typedef enum {
    road_piece,
    city_piece,
    settlement_piece
}Piece;

typedef struct {
    Piece board_placement;
    Color color;
}Placement;

#endif 