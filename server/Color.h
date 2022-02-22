#ifndef COLOR_H
#define COLOR_H 

#include <stdio.h>

typedef enum {
    red,
    blue,
    orange,
    white,
    none
}Color;

void printColors() {
    printf("%d for red\n%d for blue\n%d for orange\n%d for white\n",
    red, blue, orange, white);
}

#endif 