
#ifndef PORJET_C_LIFECYCLE_H
#define PORJET_C_LIFECYCLE_H
#include "struct.h"
#include "destroy.h"
#include "setGet.h"
#include "func.h"
#include <math.h>
int get_XP(Player * player,int nb_monster,int iteration);
void level_up_P(Player * player);
void refresh_stat_armor_P(Player * player);

void refresh_stat_lvl_P(Player * player);


#endif //PORJET_C_LIFECYCLE_H
