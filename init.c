//
// Created by ACER PREDATOR on 29/09/2023.
//
#include "init.h"

Monster dead_monster(){
    Monster monstre = {
            // a changer le systeme pour que le niveaux soit basé sur le turn
            .name = "###DEAD###",
            .level = 0,
            //
            .vie = 0,
            .def = 0,
            .dmg = 0,
    };
    return monstre;
}

Monster create_monster(){
    Monster monstre = {
            // a changer le systeme pour que le niveaux soit basé sur le turn
            .name = "truc",
            .level = get_RNG_int(1,3),
            //
            .vie = get_RNG_int(10,20),
            .def = get_RNG_int(2,10),
            .dmg = get_RNG_int(8,16),
    };
    return monstre;
}

Player* create_player(int og_vie,
                     int og_mana,
                     int vie,
                     int mana,
                     int og_def,
                     Weapon * weapon,
                     Armor * head_piece,
                     Armor * chest_piece,
                     Armor * leg_piece,
                     Armor * ring){
    Player *player = malloc(sizeof(Player));
    if (player != NULL) {
        player->og_vie = og_vie;
        player->og_mana = og_mana;
        player->vie = vie;
        player->mana = mana;
        player->og_def = og_def;
        player->weapon = weapon;
        player->head_piece = head_piece;
        player->chest_piece = chest_piece;
        player->leg_piece = leg_piece;
        player->ring = ring;
        player->ac = 1;
    }
    return player;
}

Weapon *create_weapon(int dmg) {
    Weapon *weapon = (Weapon *)malloc(sizeof(Weapon));
    if (weapon == NULL) {
        // Handle allocation failure, for example, return NULL or exit the program
        return NULL;
    }

    weapon->dmg = dmg;
    return weapon;
}

Armor *create_armor(int name, int mana, int def, enum Armor_type armor_type) {
    Armor *armor = (Armor *)malloc(sizeof(Armor));
    if (armor == NULL) {
        // Handle allocation failure, for example, return NULL or exit the program
        return NULL;
    }

    armor->name = name;
    armor->mana = mana;
    armor->def = def;
    armor->armor_type = armor_type;
    return armor;
}

Item * create_item(int name, int mana, int hp){
    Item * item = (Item *)malloc(sizeof(Item));
    if (item == NULL) {
        // Handle allocation failure, for example, return NULL or exit the program
        return NULL;
    }

    item->name = name;
    item->mana = mana;
    item->hp = hp;
    return item;
}
Skill * create_skill(int name, int mana, int dmg){
    Skill * skill = (Skill *)malloc(sizeof(Skill));
    if (skill == NULL) {
        // Handle allocation failure, for example, return NULL or exit the program
        return NULL;
    }

    skill->name = name;
    skill->mana = mana;
    skill->dmg = dmg;
    return skill;
}