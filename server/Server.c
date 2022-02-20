#include "DevelopmentCard.h"
#include "Piece.h"
#include "Player.h"
#include "Resource.h"
#include "SpecialCard.h"
#include "Hexagon.h"


#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main() {
    srand(time(NULL));
    Placement place;
    place.board_placement = settlement_piece;
    place.color = blue;
    Hexagon* hex = createHexagon(wood, 6);
    printf("created\nadding...\n");
    addPlacement(hex, 0, place);
    place.board_placement = city_piece;
    addPlacement(hex, 0, place);
    printf("done\n");
    free(hex);

    return 0;
}