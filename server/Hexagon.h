#ifndef HEXAGON_H 
#define HEXAGON_H 

#include "Resource.h"
#include "Piece.h"
#include <stdbool.h>

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
    Placement* placement;
}HexSide;

typedef struct {
    Port port;
    Placement* placement;
}HexCorner;

//order (sides): top, top right, bottom right, bottom, bottom left, top left
//order (corners): top right, right, bottom right, bottom left, left, top left
typedef struct {
    HexCorner* corners[6];
    HexSide* sides[6];
    Resource resource;
    unsigned int number;
    bool isRobbed;
}Hexagon;

Hexagon* createHexagon(Resource resource, unsigned int number); 
void addPlacement(Hexagon* hex, unsigned int cornerIndex, Placement placement); //to corner
void addRoad(Hexagon* hex, unsigned int sideIndex, Color color); // to side
void placeRobber(Hexagon* hex);
void removeRobber(Hexagon* hex);
void destructHexagon(Hexagon* hex);


#endif 