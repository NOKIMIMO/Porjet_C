//
// Created by ACER PREDATOR on 29/09/2023.
//
#include "struct.h"
#include "init.h"
#include "func.h"

Monster create_monster(){
    Monster monstre = {
            .vie = getRNGint(80,100),
            .def = getRNGint(2,10),
            .dmg = getRNGint(8,16),
            .speed = getRNGint(1,5)
    };
    return monstre;
}

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
                     Armor * ring){
    Player player ={
            .og_vie = og_vie,
            .og_mana= og_mana,
            .vie = vie,
            .mana = mana,
            .og_def= og_def,
            .og_speed = og_speed,
            .weapon = weapon,
            .head_piece = head_piece,
            .chest_piece = chest_piece,
            .leg_piece = leg_piece,
            .ring = ring
    };
    return player;
}