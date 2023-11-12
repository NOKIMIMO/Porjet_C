#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "visual.h"
#include "game.h"
#include "splashScreen.h"

int main(int argc, char *argv[]){
    int sScrn = splashScreen();
    int endScrn=0;
    if(sScrn == 0)
    {
        return 0;
    }
    else if(sScrn == 1){
        endScrn =game(0);
    }
    else if(sScrn == 2){
        endScrn =game(1);
    }else{
        exit(-1);
    }
    if ( endScrn == 0){
        printf("Vous avez perdu\n");
        return 0;
    }
    else if(endScrn == 2){
        printf("Bye bye\n");
        return 0;
    }
    else{
        exit(-1);
    }
}