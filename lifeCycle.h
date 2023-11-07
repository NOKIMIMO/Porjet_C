
#ifndef PORJET_C_LIFECYCLE_H
#define PORJET_C_LIFECYCLE_H
#include "struct.h"
#include "destroy.h"
#include "setGet.h"
#include "func.h"
#include <math.h>

void kill(Monster * monster, Player * player);

void level_up_P(Player * player);
void refresh_stat_armor_P(Player * player);

void refresh_stat_lvl_P(Player * player);


#endif //PORJET_C_LIFECYCLE_H
