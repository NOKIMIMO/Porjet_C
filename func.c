//
// Created by ACER PREDATOR on 29/09/2023.
//
#include "func.h"

int get_RNG_int(int min, int max){
    unsigned int seed = (unsigned int)clock(); // Utilisez clock() pour obtenir une graine basée sur le temps actuel
    srand(seed);
    wait(2);
    return (rand() % (max - min + 1)) + min;
}
void wait(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + (CLOCKS_PER_SEC * milliseconds / 1000));
}

void mofidyMapAtPos(int x,int y,int ** map,int value){
    map[y][x]=value;
}
void give_hp_P(Player * player,int hp){
    if (get_vie_P(player)+hp> get_og_vie_P(player)){
        set_vie_P(player,get_og_vie_P(player));
    }else{
        set_vie_P(player,get_vie_P(player)+hp);
    }
}
void give_mana_P(Player * player,int hp){
    if (get_mana_P(player)+hp> get_og_mana_P(player)){
        set_mana_P(player,get_og_mana_P(player));
    }else{
        set_mana_P(player,get_mana_P(player)+hp);
    }
}
/////ITEM
void use_potion(Player *player,int type){
    if (type == 0){
        //vie
        give_hp_P(player,40);
        remove_potion(player,type);
    }else if(type == 1){
        //mana
        give_mana_P(player,30);
        remove_potion(player,type);
    }else if(type == 2){
        //double
        give_hp_P(player,20);
        give_mana_P(player,10);
        remove_potion(player,type);
    }
}
int * searchEntry(int ** map, int rows, int cols){
    int * entry = (int *)malloc(2 * sizeof(int));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(map[i][j] == 2){
                entry[0] = j;
                entry[1] = i;
                return entry;
            }
        }
    }
    return NULL;
}
void remove_potion(Player *player,int type){
    switch (type){
        case 0:
            player->inventory->listItem->potion_hp--;
            break;
        case 1:
            player->inventory->listItem->potion_mana--;
            break;
        case 2:
            player->inventory->listItem->potion_double--;
            break;
        default:
            return;
    }
}
void add_potion(Player *player,int type,int quantity){
    for (int i = 0; i < quantity; i++) {
        switch (type){
            case 0:
                player->inventory->listItem->potion_hp++;
                break;
            case 1:
                player->inventory->listItem->potion_mana++;
                break;
            case 2:
                player->inventory->listItem->potion_double++;
                break;
            default:
                return;
        }
    }
}
//////WEAPON
// Function to remove an item at index n from ListItem
void removeWeaponFromListItem(ListWeapon* list, int index) {
    if (index >= 0 && index < list->size) {
        //free(list->weapon[index]);
        for (int i = index; i < list->size - 1; i++) {
            list->weapon[i] = list->weapon[i + 1];
        }
        list->size--;
    }
}
void swapWeaponFromListWeaponWithPlayer(ListWeapon* list, int index,Player * player) {
    if (index >= 0 && index < list->size) {
        Weapon * tmp = list->weapon[index];
        list->weapon[index] = player->weapon;
        player->weapon = tmp;
    }
}


// Function to get the pointer to the item at index n in ListItem
Weapon* getWeaponFromListItem(ListWeapon* list, int index) {
    if (index >= 0 && index < list->size) {
        return list->weapon[index];
    }
    return NULL; // Index out of bounds
}
void addWeaponToListWeapon(ListWeapon* list, Weapon* weapon) {
    if (list->size >= list->capacity) {
        // If the current size equals or exceeds the capacity, double the capacity.
        list->capacity *= 2;
        list->weapon = (Weapon **)realloc(list->weapon, list->capacity * sizeof(Weapon*));
        if (list->weapon == NULL) {
            // Handle memory allocation failure
            // You can add your error-handling logic here.
            exit(1);
        }
    }
    list->weapon[list->size] = weapon;
    list->size++;
}
// Function to add a new item to the player's inventory
void addWeaponToPlayerInventory(Player* player, Weapon* weapon) {
    addWeaponToListWeapon(player->inventory->listWeapon, weapon);
}
// Function to remove an item at index n from the player's inventory
void removeWeaponFromPlayerInventory(Player* player, int index) {
    removeWeaponFromListItem(player->inventory->listWeapon, index);
}
// Function to get the pointer to the item at index n in the player's inventory
Weapon* getWeaponFromPlayerInventory(Player* player, int index) {
    return getWeaponFromListItem(player->inventory->listWeapon, index);
}

/////ARMOR
// Function to remove an item at index n from ListItem
void removeArmorFromListItem(ListArmor * list, int index) {
    if (index>=0 && index < get_size_LA(list)){
        for (int i = index; i < get_size_LA(list)-1; i++) {
            list->armor[i] = list->armor[i + 1];
        }
        list->size--;
    }
}
int getIndexArmorFromListArmor(ListArmor * list,enum Armor_type type,char * name){
    int size = get_size_LA(list);
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if(strcmp(get_name_A(getArmorFromListItem(list,i)),name)==0 && get_armor_type_A(getArmorFromListItem(list,i))==type){
            index = i;
        }
    }
    return index;
}
void swapArmorFromListArmorWithArmor(ListArmor *listArmor,enum Armor_type type,Player * player,char * name) {
    //search for armor with type and name
    int indexArmor = getIndexArmorFromListArmor(listArmor,type,name);
    if (get_armor_P(player,type) == NULL) {
        set_armor_P(player, listArmor->armor[indexArmor], type);
        removeArmorFromPlayerInventory(player, indexArmor);
    }else{
        Armor * tmp = get_armor_P(player,type);
        set_armor_P(player,listArmor->armor[indexArmor],type);
        listArmor->armor[indexArmor] = tmp;
    }

}
// Function to get the pointer to the item at index n in ListItem
Armor * getArmorFromListItem(ListArmor * list, int index) {
    if (index >= 0 && index < list->size) {
        return list->armor[index];
    }
    return NULL; // Index out of bounds
}
void addArmorToListArmor(ListArmor * list, Armor * armor) {
    if (list->size >= list->capacity) {
        // If the current size equals or exceeds the capacity, double the capacity.
        list->capacity *= 2;
        list->armor = (Armor **)realloc(list->armor, list->capacity * sizeof(Armor*));
        if (list->armor == NULL) {
            // Handle memory allocation failure
            // You can add your error-handling logic here.
            exit(1);
        }
    }
    list->armor[list->size] = armor;
    list->size++;
}
// Function to add a new item to the player's inventory
void addArmorToPlayerInventory(Player* player, Armor * armor) {
    addArmorToListArmor(player->inventory->listArmor, armor);
}
// Function to remove an item at index n from the player's inventory
void removeArmorFromPlayerInventory(Player* player, int index) {
    removeArmorFromListItem(player->inventory->listArmor, index);
}
// Function to get the pointer to the item at index n in the player's inventory
Armor * getArmorFromPlayerInventory(Player* player, int index) {
    return getArmorFromListItem(player->inventory->listArmor, index);
}
/////SKILL
// Function to remove an item at index n from ListItem
void removeSkillFromListSkill(ListSkill * list, int index) {
    if (index >= 0 && index < list->size) {
        //free(list->weapon[index]);
        for (int i = index; i < list->size - 1; i++) {
            list->skill[i] = list->skill[i + 1];
        }
        list->size--;
    }
}
// Function to get the pointer to the item at index n in ListItem
Skill * getSkillFromListSkill(ListSkill * list, int index) {
    if (index >= 0 && index < list->size) {
        return list->skill[index];
    }
    return NULL; // Index out of bounds
}
void addSkillToListSkill(ListSkill * list, Skill * skill) {
    if (list->size >= list->capacity) {
        // If the current size equals or exceeds the capacity, double the capacity.
        list->capacity *= 2;
        list->skill = (Skill **)realloc(list->skill, list->capacity * sizeof(Skill*));
        if (list->skill == NULL) {
            // Handle memory allocation failure
            // You can add your error-handling logic here.
            exit(1);
        }
    }
    list->skill[list->size] = skill;
    list->size++;
}
// Function to add a new item to the player's inventory
void addSkillToPlayerInventory(Player* player, Skill * skill) {
    addSkillToListSkill(player->inventory->listSkill, skill);
}
// Function to remove an item at index n from the player's inventory
void removeSkillFromPlayerInventory(Player* player, int index) {
    removeSkillFromListSkill(player->inventory->listSkill, index);
}
// Function to get the pointer to the item at index n in the player's inventory
Skill * getSkillFromPlayerInventory(Player* player, int index) {
    return getSkillFromListSkill(player->inventory->listSkill, index);
}
void swapSkillFromListSkillWithPlayer(ListSkill* list, int index,Player * player,int skillIndex) {
    //only 2 skill
    if (get_skill_P(player,skillIndex) == NULL) {
        set_skill_P(player, list->skill[index], skillIndex);
        removeSkillFromPlayerInventory(player, index);
    }else{
        Skill * tmp = get_skill_P(player,skillIndex);
        set_skill_P(player,list->skill[index],skillIndex);
        list->skill[index] = tmp;
    }

}
//void swapWeaponFromListWeaponWithPlayer(ListWeapon* list, int index,Player * player) {
//    if (index >= 0 && index < list->size) {
//        Weapon * tmp = list->weapon[index];
//        list->weapon[index] = player->weapon;
//        player->weapon = tmp;
//    }
//}

int verifPresenceSalle(int **map,int x, int y)
{
    int indiceEnXAdd = 0, indiceEnXRemove = 0, indiceEnYAdd = 0, indiceEnYRemove = 0;

    if(x == 0){
        indiceEnXAdd = 1;
        indiceEnXRemove = 0;
    }
    else if (x == 6) {
        indiceEnXAdd = 0;
        indiceEnXRemove = 1;
    }
    else{
        indiceEnXAdd++;
        indiceEnXRemove++;
    }

    if(y == 0){
        indiceEnYAdd = 1;
        indiceEnYRemove = 0;
    }
    else if(y == 6){
        indiceEnYAdd = 0;
        indiceEnYRemove = 1;
    }
    else{
        indiceEnYAdd++;
        indiceEnYRemove++;
    }

    if(map[x+indiceEnXAdd][y] != 0 || map[x][y+indiceEnYAdd] != 0 || map[x][y-indiceEnYRemove] != 0 || map[x-indiceEnXRemove][y] != 0){
        return 1;
    }
    else{
        return 0;
    }
}

int generationSalle(int **map,int x,int y)
{
    int isSalle = 0;

    isSalle = get_RNG_int(0,2);

    if(isSalle == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int creationRoomBoss(int** map,int x,int y)
{
    int indiceEnXAdd = 0, indiceEnXRemove = 0, indiceEnYAdd = 0, indiceEnYRemove = 0;

    if(x == 0){
        indiceEnXAdd = 1;
        indiceEnXRemove = 0;
    }
    else if (x == 6) {
        indiceEnXAdd = 0;
        indiceEnXRemove = 1;
    }
    else{
        indiceEnXAdd++;
        indiceEnXRemove++;
    }

    if(y == 0){
        indiceEnYAdd = 1;
        indiceEnYRemove = 0;
    }
    else if(y == 6){
        indiceEnYAdd = 0;
        indiceEnYRemove = 1;
    }
    else{
        indiceEnYAdd++;
        indiceEnYRemove++;
    }

    if(map[x+indiceEnXAdd][y] == 0){
        map[x+indiceEnXAdd][y] = 3;
        return 1;
    }
    else if (map[x][y+indiceEnYAdd] == 0) {
        map[x][y+indiceEnYAdd] = 3;
        return 1;
    }
    else if(map[x][y-indiceEnYRemove] == 0){
        map[x][y-indiceEnYRemove] = 3;
        return 1;
    }
    else if(map[x-indiceEnXRemove][y] == 0){
        map[x-indiceEnXRemove][y] = 3;
        return 1;
    }
    else{
        return 0;
    }
}