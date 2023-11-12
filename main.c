#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "visual.h"
#include "game.h"
#include "splashScreen.h"
#include "deathScreen.h"


int main(int argc, char *argv[]){
    int ret = splashScreen();
    if (ret ==0){
        return 0;
    }else if (ret == 1) {
        game();
    }else if (ret == 2){
        printf("Saves\n");
    }
}