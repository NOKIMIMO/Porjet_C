//
// Created by ACER PREDATOR on 29/09/2023.
//
#include "func.h"

int get_RNG_int(int min, int max){
    unsigned int seed = (unsigned int)clock(); // Utilisez clock() pour obtenir une graine basée sur le temps actuel
    srand(seed);
    return (rand() % (max - min + 1)) + min;
}
