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

Weapon *create_weapon(int dmg, int speed) {
    Weapon *weapon = (Weapon *)malloc(sizeof(Weapon));
    if (weapon == NULL) {
        // Handle allocation failure, for example, return NULL or exit the program
        return NULL;
    }

    weapon->dmg = dmg;
    weapon->speed = speed;
    return weapon;
}

Armor *create_armor(int name, int mana, int def, int speed, enum Armor_type armor_type) {
    Armor *armor = (Armor *)malloc(sizeof(Armor));
    if (armor == NULL) {
        // Handle allocation failure, for example, return NULL or exit the program
        return NULL;
    }

    armor->name = name;
    armor->mana = mana;
    armor->def = def;
    armor->speed = speed;
    armor->armor_type = armor_type;
    return armor;
}