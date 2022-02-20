#ifndef HEXAGON_H 
#define HEXAGON_H 

#include "Resource.h"
#include "Piece.h"

typedef enum {
    wood_port,
    sheep_port,
    brick_port,
    ore_port,
    wheat_port,
    three_port,
    no_port
}Port;

typedef struct {
    Port port;
    Placement placement;
}HexSide;

typedef struct {
    Placement placement;
}HexCorner;

//order (sides): top, top right, bottom right, bottom, bottom left, top left
//order (corners): top right, right, bottom right, bottom left, left, top left
typedef struct {
    HexCorner corners[6];
    HexSide sides[6];
}Hexagon;

#endif 