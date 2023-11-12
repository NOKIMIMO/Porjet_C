#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "visual.h"
#include "game.h"
#include "splashScreen.h"

int main(int argc, char *argv[]){
    int sScrn = splashScreen();

    if(sScrn == 0)
    {
        return 0;
    }
    else if(sScrn == 1){
        game();
    }

}