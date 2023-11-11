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

// Function to remove an item at index n from ListItem
void removeItemFromListItem(ListItem* list, int index) {
    if (index >= 0 && index < list->size) {
        free(list->item[index]);
        for (int i = index; i < list->size - 1; i++) {
            list->item[i] = list->item[i + 1];
        }
        list->size--;
    }
}
// Function to get the pointer to the item at index n in ListItem
Item* getItemFromListItem(ListItem* list, int index) {
    if (index >= 0 && index < list->size) {
        return list->item[index];
    }
    return NULL; // Index out of bounds
}
void addItemToListItem(ListItem* list, Item* item) {
    if (list->size >= list->capacity) {
        // If the current size equals or exceeds the capacity, double the capacity.
        list->capacity *= 2;
        list->item = (Item**)realloc(list->item, list->capacity * sizeof(Item*));
        if (list->item == NULL) {
            // Handle memory allocation failure
            // You can add your error-handling logic here.
            exit(1);
        }
    }
    list->item[list->size] = item;
    list->size++;
}
// Function to add a new item to the player's inventory
void addItemToPlayerInventory(Player* player, Item* item) {
    addItemToListItem(player->inventory->listItem, item);
}
// Function to remove an item at index n from the player's inventory
void removeItemFromPlayerInventory(Player* player, int index) {
    removeItemFromListItem(player->inventory->listItem, index);
}
// Function to get the pointer to the item at index n in the player's inventory
Item* getItemFromPlayerInventory(Player* player, int index) {
    return getItemFromListItem(player->inventory->listItem, index);
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
        list->weapon = (Weapon **)realloc(list->weapon, list->capacity * sizeof(Item*));
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
        list->armor = (Weapon **)realloc(list->armor, list->capacity * sizeof(Item*));
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
        list->skill = (Skill **)realloc(list->skill, list->capacity * sizeof(Item*));
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