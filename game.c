//
// Created by ACER PREDATOR on 01/11/2023.
//

#include "game.h"

int game(){
    Player * player= create_player(100,4,7,100,100,100,10,create_weapon( 100),
                                 NULL,
                                 create_armor( "plastron", 5, 5, chest_piece),
                                 NULL,
                                 NULL);
    set_vie_P(player,10);
    set_mana_P(player,20);
    set_inventory_P(player,create_inventory(10,10,10));
    for (int i = 0; i < 4; ++i) {
        addItemToPlayerInventory(player, create_item("Potion de vie",0,20));
    }
    addItemToPlayerInventory(player, create_item("Potion de mana",20,0));
    addItemToPlayerInventory(player, create_item("Potion double",10,10));
    int ** map = initMap(7,7);

//    int ret = visual(player);
    int ret=0;
    if (ret==1){
        //le joueur est mort
        return 0;
    }else if(ret == 0){
        //Exit normal du joueur / fin de combat
        buildMapGraph(3,5,*player,map);
    }else{
        printf("Erreur");
        return -1;
    }
}