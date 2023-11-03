//
// Created by ACER PREDATOR on 29/09/2023.
//
#include "func.h"

int get_RNG_int(int min, int max){
    unsigned int seed = (unsigned int)clock(); // Utilisez clock() pour obtenir une graine basée sur le temps actuel
    srand(seed);
    wait(2);
    return (rand() % (max - min + 1)) + min;
}
void wait(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + (CLOCKS_PER_SEC * milliseconds / 1000));
}

void mofidyMapAtPos(int x,int y,int ** map,int value){
    map[y][x]=value;
}