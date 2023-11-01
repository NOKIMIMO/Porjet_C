//
// Created by ACER PREDATOR on 29/09/2023.
//
#include "combat.h"

int get_player_dmg(Player * player,Monster * monster){
    if(!player->weapon){
        //coup de poing
        return 1;
    }
    else{
        return player->weapon->dmg - (monster->def/2);
    }
}

int get_monster_dmg(Player * player,Monster * monster){
    return monster->dmg - player->def;
}

int monster_attack(Player * player,Monster * monster){
    int dmg = get_monster_dmg(player,monster);
    if(dmg<0){
        dmg = 0;
    }
    set_vie_P(player,get_vie_P(player)-dmg);
    return dmg;
}

int is_monster_list_empty(Monster * monster_list,int nb_monster){
    for (int i = 0; i < nb_monster; ++i) {
        if(strcmp(get_name_M(&monster_list[i]),"###DEAD###")!=0){
            return 0;
        }
    }
    return 1;
}