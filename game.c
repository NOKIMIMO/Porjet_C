//
// Created by ACER PREDATOR on 01/11/2023.
//

#include "game.h"

int game(){
    Player * player= create_player(100,100,100,100,10,create_weapon( 100),
                                 NULL,
                                 create_armor( 10, 5, 5, chest_piece),
                                 NULL,
                                 NULL);

    int ret = visual(player);
    if (ret==1){
        //le joueur est mort
        return 0;
    }else if(ret == 0){
        //Exit normal du joueur / fin de combat
        buildMap(3,5,15,57,*player);
    }else{
        printf("Erreur");
        return -1;
    }
}