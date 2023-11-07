//
// Created by ACER PREDATOR on 29/09/2023.
//
#include "destroy.h"
#include "stdlib.h"

void destroyPlayer(Player * player){
    free(player->weapon);
    free(player->head_piece);
    free(player->chest_piece);
    free(player->leg_piece);
    free(player->ring);
    if (player->inventory != NULL){
        if (player->inventory->listWeapon != NULL){
            free(player->inventory->listWeapon);
        }
        if (player->inventory->listArmor != NULL){
            free(player->inventory->listArmor);
        }
        if (player->inventory->listItem != NULL){
            free(player->inventory->listItem);
        }
        free(player->inventory);
    }
    free(player);
}

void destroyMonster(Monster * monster){
    free(monster);
}