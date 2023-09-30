#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"
#include "init.h"

//gcc -o hello_sdl hello_sdl.c
int main(int argc, char *argv[]) {
    unsigned int seed = (unsigned int)clock(); // Utilisez clock() pour obtenir une graine basée sur le temps actuel
    srand(seed);
    for (int i = 0; i < 5; ++i) {
        printf("%d\n",rand()%100);
    }




    printf("Hello, World!\n");
    return 0;
}