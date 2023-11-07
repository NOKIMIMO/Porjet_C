
#ifndef PORJET_C_SETGET_H
#define PORJET_C_SETGET_H
#include "struct.h"
#include "func.h"
//Player
int get_vie_P(Player * player);
int get_mana_P(Player * player);
int get_og_mana_P(Player * player);
int get_og_vie_P(Player * player);
int get_def_P(Player * player);
int get_xp_P(Player * player);
int get_level_P(Player * player);
int get_ac_P(Player * player);
int get_pos_x_P(Player * player);
int get_pos_y_P(Player * player);

void set_vie_P(Player * player,int vie);
void set_mana_P(Player * player,int mana);
void set_og_mana_P(Player * player,int mana);
void set_og_vie_P(Player * player,int vie);
void set_def_P(Player * player,int def);
void set_xp_P(Player * player,int xp);
void set_level_P(Player * player,int level);
void set_ac_P(Player * player,int ac);
void set_pos_x_P(Player * player,int pos_x);
void set_pos_y_P(Player * player,int pos_y);
void set_inventory_P(Player * player, Inventory * inventory);

void set_weapon_P(Player * player, Weapon * weapon);
void set_head_piece_P(Player * player, Armor * head_piece);
void set_chest_piece_P(Player * player, Armor * chest_piece);
void set_leg_piece_P(Player * player, Armor * leg_piece);
void set_ring_P(Player * player, Armor * ring);
void set_armor_P(Player * player, Armor * armor, enum Armor_type armor_type);

Weapon * get_weapon_P(Player * player);
Armor * get_head_piece_P(Player * player);
Armor * get_chest_piece_P(Player * player);
Armor * get_leg_piece_P(Player * player);
Armor * get_ring_P(Player * player);
Armor * get_armor_P(Player * player, enum Armor_type armor_type);

//Monster
int get_vie_M(Monster * monster);
int get_def_M(Monster * monster);
int get_level_M(Monster * monster);
char * get_name_M(Monster * monster);

void set_vie_M(Monster * monster, int vie);
void set_def_M(Monster * monster, int def);

//LIST
int get_size_LI(ListItem * list);
int get_size_LW(ListWeapon * list);
int get_size_LA(ListArmor * list);
ListItem * get_listItem_P(Player * player);
ListWeapon * get_listWeapon_P(Player * player);
ListArmor * get_listArmor_P(Player * player);
Armor * get_ring_P(Player * player);

//ITEM
int get_mana_I(Item * item);
int get_hp_I(Item * item);
char * get_name_I(Item * item);
int get_potion_type_I(Player  * player,char * type);

//WEAPON
int get_dmg_W(Weapon * weapon);

//ARMOR
int get_mana_A(Armor * armor);
int get_def_A(Armor * armor);
char * get_name_A(Armor * armor);
enum Armor_type get_armor_type_A(Armor * armor);

//SKILL
int get_mana_S(Skill * skill);
int get_dmg_S(Skill * skill);
char * get_name_S(Skill * skill);

Item * get_item_LI(ListItem * list, int index);
Weapon * get_weapon_LW(ListWeapon * list, int index);
Armor * get_armor_LA(ListArmor * list, int index);

//LIST
//ListItem * get_listItem_I(Inventory * inventory);
//ListWeapon * get_listWeapon_I(Inventory * inventory);
//ListArmor * get_listArmor_I(Inventory * inventory);

int get_size_LI(ListItem * list);
int get_size_LW(ListWeapon * list);
int get_size_LA(ListArmor * list);

int get_capacity_LI(ListItem * list);
int get_capacity_LW(ListWeapon * list);
int get_capacity_LA(ListArmor * list);

#endif //PORJET_C_SETGET_H
