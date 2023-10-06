//
// Created by ACER PREDATOR on 29/09/2023.
//
#include "init.h"


Monster create_monster(){
    Monster monstre = {
            // a changer le systeme pour que le niveaux soit basé sur le turn
            .level = get_RNG_int(1,3),
            //
            .vie = get_RNG_int(80,100),
            .def = get_RNG_int(2,10),
            .dmg = get_RNG_int(8,16),
            .speed = get_RNG_int(1,5)
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