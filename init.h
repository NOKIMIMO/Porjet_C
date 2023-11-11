#ifndef PORJET_C_INIT_H
#define PORJET_C_INIT_H
#include "struct.h"
#include "func.h"
#include "setGet.h"

Monster create_monster(char *name,
                       int vie,
                       int dmg,
                       int def,
                       char * sprite);
Monster dead_monster();
Player * create_player(int og_vie,
                     int pos_x,
                     int pos_y,
                     int og_mana,
                     int vie,
                     int mana,
                     Weapon * weapon,
                     Armor * head_piece,
                     Armor * chest_piece,
                     Armor * leg_piece,
                     Armor * ring);

Weapon *create_weapon(int dmg,char * name);
Armor * create_armor(char * name, int mana, int def, enum Armor_type armor_type);

Item * create_item(char * name, int mana, int hp);
Skill * create_skill(char * name, int mana, int dmg);
int ** initMap(int rows, int cols);
ListArmor* create_list_armor(int capacity);
ListWeapon* create_list_weapon(int capacity);
ListItem* create_list_item(int capacity);
Inventory* create_inventory(int listItemCapacity, int listWeaponCapacity, int listArmorCapacity);

#endif //PORJET_C_INIT_H
