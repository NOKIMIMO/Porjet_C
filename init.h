#ifndef PORJET_C_INIT_H
#define PORJET_C_INIT_H
#include "struct.h"
#include "func.h"
#include "setGet.h"

Monster create_monster();
Monster dead_monster();
Player * create_player(int og_vie,
                     int pos_x,
                     int pos_y,
                     int og_mana,
                     int vie,
                     int mana,
                     int og_def,
                     Weapon * weapon,
                     Armor * head_piece,
                     Armor * chest_piece,
                     Armor * leg_piece,
                     Armor * ring);

Weapon * create_weapon(int dmg);
Armor * create_armor(int name, int mana, int def, enum Armor_type armor_type);

Item * create_item(int name, int mana, int hp);
Skill * create_skill(int name, int mana, int dmg);
int ** initMap(int rows, int cols);

#endif //PORJET_C_INIT_H
