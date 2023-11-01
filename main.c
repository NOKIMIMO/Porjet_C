#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "visual.h"

//gcc -o hello_sdl hello_sdl.c
int main(int argc, char *argv[]){

    int ret = visual();
    if (ret==1){
        //le joueur est mort
        return 0;
    }else if(ret == 0){
        //Exit normal du joueur
        return 0;
    }else{
        printf("Erreur");
        return -1;
    }
}