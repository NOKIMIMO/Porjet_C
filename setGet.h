
#ifndef PORJET_C_SETGET_H
#define PORJET_C_SETGET_H
#include "struct.h"
//Player
int get_vie_P(Player * player);
int get_mana_P(Player * player);
int get_def_P(Player * player);
int get_momentum_P(Player * player);
int get_speed_P(Player * player);

void set_vie_P(Player * player,int vie);
void set_mana_P(Player * player,int mana);
void set_def_P(Player * player,int def);
void set_speed_P(Player * player,int speed);
void set_momentum_P(Player * player,int momentum);

void set_weapon_P(Player * player, Weapon * weapon);
void set_head_piece_P(Player * player, Armor * head_piece);
void set_chest_piece_P(Player * player, Armor * chest_piece);
void set_leg_piece_P(Player * player, Armor * leg_piece);
void set_ring_P(Player * player, Armor * ring);

Weapon * get_weapon_P(Player * player);
Armor * get_head_piece_P(Player * player);
Armor * get_chest_piece_P(Player * player);
Armor * get_leg_piece_P(Player * player);


//Monster
int get_vie_M(Monster * monster);
int get_def_M(Monster * monster);
int get_speed_M(Monster * monster);

void set_vie_M(Monster * monster, int vie);
void set_def_M(Monster * monster, int def);
void set_speed_M(Monster * monster, int speed);


#endif //PORJET_C_SETGET_H
