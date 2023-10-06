#ifndef PORJET_C_COMBAT_H
#define PORJET_C_COMBAT_H

#include "struct.h"
#include "setGet.h"

void advance_turn(Player * player, Monster * monster);

int get_player_dmg(Player * player,Monster * monster);

int get_monster_dmg(Player * player,Monster * monster);


#endif //PORJET_C_COMBAT_H
