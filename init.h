#ifndef PORJET_C_INIT_H
#define PORJET_C_INIT_H
#include "struct.h"
#include "init.h"
#include "func.h"
#include "setGet.h"

Monster createMonster();
Player create_player(int og_vie,
                     int og_mana,
                     int vie,
                     int mana,
                     int og_def,
                     int og_speed,
                     Weapon * weapon,
                     Armor * head_piece,
                     Armor * chest_piece,
                     Armor * leg_piece,
                     Armor * ring);



#endif //PORJET_C_INIT_H
