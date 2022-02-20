#include "Hexagon.h"
#include "Color.h"
#include "Piece.h"
#include <stdlib.h>
#include <stdbool.h>

Hexagon* createHexagon(Resource resource, unsigned int number) {
    Hexagon* hex = (Hexagon*)malloc(sizeof(Hexagon));
    hex->resource = resource;
    hex->number = number;
    hex->isRobbed = false;
    for(int i=0;i<6;i++) {
        //init side
        hex->sides[i] = (HexSide*)malloc(sizeof(HexSide));
        hex->sides[i]->placement = (Placement*)malloc(sizeof(Placement));
        hex->sides[i]->placement->board_placement = no_piece;
        hex->sides[i]->placement->color = none;
        //init corner
        hex->corners[i] = (HexCorner*)malloc(sizeof(HexCorner));
        hex->corners[i]->port = no_port;
        hex->corners[i]->placement = (Placement*)malloc(sizeof(Placement));
        hex->corners[i]->placement->board_placement = no_piece;
        hex->corners[i]->placement->color = none;

    } 
    return hex;
}

void addRoad(Hexagon* hex, unsigned int sideIndex, Color color) {
    hex->sides[sideIndex]->placement->board_placement = road_piece;
    hex->sides[sideIndex]->placement->color = color;
}

void addPlacement(Hexagon* hex, unsigned int cornerIndex, Placement placement) {
    hex->corners[cornerIndex]->placement->board_placement = placement.board_placement;
    hex->corners[cornerIndex]->placement->color = placement.color;
}

void placeRobber(Hexagon* hex) {
    hex->isRobbed = true;
}

void removeRobber(Hexagon* hex) {
    hex->isRobbed = false;
}

void destructHexagon(Hexagon* hex) {
    for(int i=0;i<6;i++) {
        free(hex->sides[i]->placement);
        free(hex->sides[i]);
        free(hex->corners[i]->placement);
        free(hex->corners[i]);
    }
}