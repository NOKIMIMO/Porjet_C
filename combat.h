#ifndef PORJET_C_COMBAT_H
#define PORJET_C_COMBAT_H

#include "func.h"
#include "struct.h"
#include "setGet.h"

int get_player_dmg(Player * player,Monster * monster);

int get_monster_dmg(Player * player,Monster * monster);
int monster_attack(Player * player,Monster * monster);

int is_monster_list_empty(Monster * monster_list,int nb_monster);

#endif //PORJET_C_COMBAT_H
