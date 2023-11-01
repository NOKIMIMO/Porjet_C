#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "visual.h"


int main(int argc, char *argv[]){
    unsigned int seed = (unsigned int)clock(); // Utilisez clock() pour obtenir une graine basée sur le temps actuel
    srand(seed);
    for (int i = 0; i < 5; ++i) {
        printf("%d\n",rand()%100);
    }
    return visual();
}