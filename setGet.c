//
// Created by ACER PREDATOR on 29/09/2023.
//
#include "setGet.h"
////Player stats
// get
int get_vie_P(Player * player){
    return player->vie;
}
int get_mana_P(Player * player){
    return player->mana;
}
int get_def_P(Player * player){
    return player->def;
}
int get_speed_P(Player * player){
    return player->speed;
}
int get_momentum_P(Player * player){
    return player->momentum;
}

int get_xp_P(Player * player) {
    return player->exp;
}
int get_level_P(Player * player){
    return player->level;
}


//set
void set_vie_P(Player * player, int vie){
    player->vie = vie;
}
void set_mana_P(Player * player, int mana){
    player->mana = mana;
}
void set_def_P(Player * player, int def){
    player->def = (def<0)?0:def;
}
void set_speed_P(Player * player, int speed){
    player->speed = (speed<0)?0:speed;
}
void set_momentum_P(Player * player, int momentum){
    player->momentum = (momentum<0)?0:momentum;
}
void set_xp_P(Player * player,int xp){
    player->exp = xp;
}
void set_level_P(Player * player,int level){
    player->level = level;
}
//Player Equip
void set_weapon_P(Player * player, Weapon * weapon){
    player->weapon = weapon;
}

void set_head_piece_P(Player * player, Armor * head_piece){
    player->head_piece = head_piece;
}

void set_chest_piece_P(Player * player, Armor * chest_piece){
    player->chest_piece = chest_piece;
}

void set_leg_piece_P(Player * player, Armor * leg_piece){
    player->leg_piece = leg_piece;
}

void set_ring_P(Player * player, Armor * ring){
    player->ring = ring;
}

Weapon * get_weapon_P(Player * player){
    return player->weapon;
}
Armor * get_head_piece_P(Player * player){
    return player->head_piece;
}
Armor * get_chest_piece_P(Player * player){
    return player->chest_piece;
}
Armor * get_leg_piece_P(Player * player){
    return player->leg_piece;
}
Armor * get_ring_P(Player * player){
    return player->ring;
}
////Monster
//getters
int get_vie_M(Monster * monster) {
    return monster->vie;
}
int get_def_M(Monster * monster) {
    return monster->def;
}
int get_speed_M(Monster * monster) {
    return monster->speed;
}
int get_level_M(Monster * monster){
    return monster->level;
}
int get_momentum_M(Monster * monster){
    return monster->momentum;
}

//setters
void set_vie_M(Monster * monster, int vie) {
    monster->vie = vie;
}
void set_def_M(Monster * monster,int def) {
    monster->def = (def<0)?0:def;
}
void set_speed_M(Monster * monster,int speed) {
    monster->speed = (speed<0)?0:speed;
}

void set_momentum_M(Monster * monster, int momentum){
    monster->momentum = (momentum<0)?0:momentum;
}