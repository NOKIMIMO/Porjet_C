//
// Created by ACER PREDATOR on 29/09/2023.
//
#include "combat.h"

void advance_turn(Player * player, Monster * monster){
    //player refresh en premier, balec
    set_momentum_P(player,get_momentum_P(player)+get_speed_P(player));
    if(get_momentum_P(player)>=100){
        set_momentum_P(player,get_momentum_P(player)-100);
        //player action
    }
    set_momentum_M(monster,get_momentum_M(monster)+get_speed_M(monster));
    if(get_momentum_M(monster)>=100){
        set_momentum_M(monster,get_momentum_M(monster)-100);
        //monster action
    }

}

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