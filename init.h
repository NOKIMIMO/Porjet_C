#ifndef PORJET_C_INIT_H
#define PORJET_C_INIT_H
#include "struct.h"
#include "func.h"
#include "setGet.h"

Monster create_monster();
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

Weapon * create_weapon(int dmg, int speed);
Armor * create_armor(int name, int mana, int def, int speed, enum Armor_type armor_type);


#endif //PORJET_C_INIT_H
