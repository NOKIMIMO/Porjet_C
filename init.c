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
                     Weapon * weapon,
                     Armor * head_piece,
                     Armor * chest_piece,
                     Armor * leg_piece,
                     Armor * ring,
                     Skill * skill1,
                     Skill * skill2){
    Player *player = malloc(sizeof(Player));
    if (player != NULL) {
        player->og_vie = og_vie;
        player->og_mana = og_mana;
        player->pos_x = pos_x;
        player->pos_y = pos_y;
        player->vie = vie;
        player->mana = mana;
        player->og_def = 0;
        player->weapon = weapon;
        player->head_piece = head_piece;
        player->chest_piece = chest_piece;
        player->leg_piece = leg_piece;
        player->ring = ring;
        player->ac = 1;
        player->inventory = NULL;
        player->skill1 = skill1;
        player->skill2 = skill2;
    }
    return player;
}

Weapon *create_weapon(int dmg,char * name) {
    Weapon *weapon = (Weapon *)malloc(sizeof(Weapon));
    if (weapon == NULL) {
        // Handle allocation failure, for example, return NULL or exit the program
        return NULL;
    }

    weapon->name = name;
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


int ** initMap(int rows, int cols, int x_depart, int y_depart){
    int ** map = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        map[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialisation de la map de départ
    map[x_depart][y_depart] = 2;
    //xBas permet de parcourir toutes les lignes en dessous de la case de départ
    //initialisé à x_depart pour parcourir la ligne du depart
    //yBas permet de parcourir toutes les colonnes en dessous de la case de départ  initialisé à y_depart
    //initialisé à y_depart pour parcourir la colonne du depart
    //xHaut permet de parcourir toutes les lignes en dessous de la case de départ  initialisé à x_depart+1
    //initialisé à x_depart+1 pour parcourir seulement les lignes au dessus du depart
    //yHaut permet de parcourir toutes les colonnes en dessous de la case de départ  initialisé à y_depart+1
    //initialisé à y_depart+1 pour parcourir seulement les colonnes au dessus du depart
    int xBas = x_depart, yBas = y_depart, xHaut = x_depart + 1, yHaut = y_depart + 1;
    int ** recupPointeur = (int **)malloc(20 * sizeof(int *));
    for (int i = 0; i < 20; i++) {
        recupPointeur[i] = (int *)malloc(10 * sizeof(int));
    }
    int indexPointeur = 0;

    while(xBas >= 0)
    {
        // Permet de ne pas écraser la première case
        if(xBas == x_depart)
        {
            yBas--;
        }

        while(yBas >= 0)
        {
            if(verifPresenceSalle(map,xBas,yBas) == 1)
            {
                int salleGeneree = generationSalle(map,xBas,yBas);
                if(salleGeneree == 0)
                {
                    map[xBas][yBas] = 0;
                    recupPointeur[indexPointeur] = &map[xBas][yBas];
                    indexPointeur++;
                }
                else
                {
                    map[xBas][yBas] = salleGeneree;
                }
            }
            else
            {
                map[xBas][yBas] = 0;
            }
            yBas--;
        }
        while(yHaut < cols)
        {
            if(verifPresenceSalle(map,xBas,yHaut) == 1)
            {
                int salleGeneree = generationSalle(map,xBas,yHaut);
                if(salleGeneree == 0)
                {
                    map[xBas][yHaut] = 0;
                    recupPointeur[indexPointeur] = &map[xBas][yHaut];
                    indexPointeur++;
                }
                else
                {
                    map[xBas][yHaut] = salleGeneree;
                }
            }
            else
            {
                map[xBas][yHaut] = 0;
            }
            yHaut++;
        }
        yBas = y_depart;
        yHaut = y_depart + 1;
        xBas--;
    }

    while(xHaut < rows)
    {
        if(xHaut == x_depart)
        {
            xHaut++;
        }

        while(yBas >= 0)
        {
            if(verifPresenceSalle(map,xHaut,yBas) == 1)
            {
                int salleGeneree = generationSalle(map,xHaut,yBas);
                if(salleGeneree == 0)
                {

                    map[xHaut][yBas] = 0;
                    recupPointeur[indexPointeur] = &map[xHaut][yBas];
                    indexPointeur++;
                }
                else
                {
                    map[xHaut][yBas] = salleGeneree;
                }
            }
            else
            {
                map[xHaut][yBas] = 0;
            }
            yBas--;
        }
        while(yHaut < cols)
        {
            if(verifPresenceSalle(map,xHaut,yHaut))
            {
                int salleGeneree = generationSalle(map,xHaut,yHaut);
                if(salleGeneree == 0)
                {
                    map[xHaut][yHaut] = 0;
                    recupPointeur[indexPointeur] = &map[xHaut][yHaut];
                    indexPointeur++;
                }
                else
                {
                    map[xHaut][yHaut] = salleGeneree;
                }
            }
            else
            {
                map[xHaut][yHaut] = 0;
            }
            yHaut++;
        }
        yBas = y_depart;
        yHaut = y_depart + 1;
        xHaut++;
    }

    int salleBoss = get_RNG_int(0,indexPointeur);

    *recupPointeur[salleBoss] = 3;

    //Permet de calculer le nombre de salles créées
    int compteurSalle = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(map[i][j] != 0){
                compteurSalle++;
            }
        }
    }

    //Si le nombre de salles est inférieur à 7, on récréé la map
    if(compteurSalle < 7){
        return initMap(7,7,x_depart,y_depart);
    }
    else{
        return map;
    }
}
// Constructor for ListItemcreate_list_item
ListItem* create_list_item(const int capacity[3]) {
    ListItem* list = (ListItem*)malloc(sizeof(ListItem));
    list->potion_hp = capacity[0];
    list->potion_mana = capacity[1];
    list->potion_double = capacity[2];

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
ListSkill * create_list_skill(int capacity){
    ListSkill * list = (ListSkill *)malloc(sizeof(ListSkill));
    list->skill = (Skill **)malloc(capacity * sizeof(Skill*));
    list->size = 0;
    list->capacity = capacity;
    return list;
}

Inventory* create_inventory(int const listItemValue[3], int listWeaponCapacity, int listArmorCapacity,int listSkillCapacity) {
    Inventory* inventory = (Inventory*)malloc(sizeof(Inventory));

    if (inventory == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    inventory->listItem = create_list_item(listItemValue);
    inventory->listWeapon = create_list_weapon(listWeaponCapacity);
    inventory->listArmor = create_list_armor(listArmorCapacity);
    inventory->listSkill = create_list_skill(listSkillCapacity);

    if (inventory->listItem == NULL || inventory->listWeapon == NULL || inventory->listArmor == NULL) {
        // Handle memory allocation failure
        free(inventory->listItem);
        free(inventory->listWeapon);
        free(inventory->listArmor);
        free(inventory->listSkill);
        free(inventory);
        return NULL;
    }

    return inventory;
}