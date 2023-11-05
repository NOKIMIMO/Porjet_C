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
                     Armor * ring){
    Player *player = malloc(sizeof(Player));
    if (player != NULL) {
        player->og_vie = og_vie;
        player->og_mana = og_mana;
        player->pos_x = pos_x;
        player->pos_y = pos_y;
        player->vie = vie;
        player->mana = mana;
        player->og_def = og_def;
        player->weapon = weapon;
        player->head_piece = head_piece;
        player->chest_piece = chest_piece;
        player->leg_piece = leg_piece;
        player->ring = ring;
        player->ac = 1;
        player->inventory = NULL;
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

Armor *create_armor(char * name, int mana, int def, enum Armor_type armor_type) {
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

Item * create_item(char * name, int mana, int hp){
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
Skill * create_skill(char * name, int mana, int dmg){
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

int ** initMap(int rows, int cols){
    int ** map = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        map[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialisation des valeurs du tableau temporaire
    //TODO: changer pour la version algo
    map[0][0] = 0; map[0][1] = 0; map[0][2] = 0; map[0][3] = 0; map[0][4] = 0; map[0][5] = 0; map[0][6] = 0;
    map[1][0] = 0; map[1][1] = 0; map[1][2] = 1; map[1][3] = 1; map[1][4] = 3; map[1][5] = 0; map[1][6] = 0;
    map[2][0] = 0; map[2][1] = 0; map[2][2] = 1; map[2][3] = 0; map[2][4] = 0; map[2][5] = 0; map[2][6] = 0;
    map[3][0] = 0; map[3][1] = 0; map[3][2] = 1; map[3][3] = 1; map[3][4] = 1; map[3][5] = 0; map[3][6] = 0;
    map[4][0] = 0; map[4][1] = 0; map[4][2] = 0; map[4][3] = 1; map[4][4] = 0; map[4][5] = 0; map[4][6] = 0;
    map[5][0] = 0; map[5][1] = 0; map[5][2] = 0; map[5][3] = 2; map[5][4] = 2; map[5][5] = 0; map[5][6] = 0;
    map[6][0] = 0; map[6][1] = 0; map[6][2] = 0; map[6][3] = 2; map[6][4] = 0; map[6][5] = 0; map[6][6] = 0;

    return map;
}
// Constructor for ListItemcreate_list_item
ListItem* create_list_item(int capacity) {
    ListItem* list = (ListItem*)malloc(sizeof(ListItem));
    list->item = (Item**)malloc(capacity * sizeof(Item*));
    list->size = 0;
    list->capacity = capacity;
    return list;
}

// Constructor for ListWeapon

ListWeapon* create_list_weapon(int capacity) {
    ListWeapon* list = (ListWeapon*)malloc(sizeof(ListWeapon));
    list->weapon = (Weapon**)malloc(capacity * sizeof(Weapon*));
    list->size = 0;
    list->capacity = capacity;
    return list;
}

// Constructor for ListArmor
ListArmor* create_list_armor(int capacity) {
    ListArmor* list = (ListArmor*)malloc(sizeof(ListArmor));
    list->armor = (Armor**)malloc(capacity * sizeof(Armor*));
    list->size = 0;
    list->capacity = capacity;
    return list;
}

Inventory* create_inventory(int listItemCapacity, int listWeaponCapacity, int listArmorCapacity) {
    Inventory* inventory = (Inventory*)malloc(sizeof(Inventory));

    if (inventory == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    inventory->listItem = create_list_item(listItemCapacity);
    inventory->listWeapon = create_list_weapon(listWeaponCapacity);
    inventory->listArmor = create_list_armor(listArmorCapacity);

    if (inventory->listItem == NULL || inventory->listWeapon == NULL || inventory->listArmor == NULL) {
        // Handle memory allocation failure
        free(inventory->listItem);
        free(inventory->listWeapon);
        free(inventory->listArmor);
        free(inventory);
        return NULL;
    }

    return inventory;
}