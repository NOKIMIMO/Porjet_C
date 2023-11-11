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
                     Weapon * weapon,
                     Armor * head_piece,
                     Armor * chest_piece,
                     Armor * leg_piece,
                     Armor * ring,
                     Skill * skill1,
                     Skill * skill2);

Weapon *create_weapon(int dmg,char * name);
Armor * create_armor(char * name, int mana, int def, enum Armor_type armor_type);

Skill * create_skill(char * name, int mana, int dmg);
int ** initMap(int rows, int cols, int x_depart, int y_depart);

ListArmor* create_list_armor(int capacity);
ListWeapon* create_list_weapon(int capacity);
ListItem* create_list_item(const int capacity[3]);
ListSkill * create_list_skill(int capacity);
Inventory* create_inventory(int const listItemValue[], int listWeaponCapacity, int listArmorCapacity,int listSkillCapacity);
#endif //PORJET_C_INIT_H
