#ifndef PORJET_C_FUNC_H
#define PORJET_C_FUNC_H
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "init.h"
#include "combat.h"
#include "lifeCycle.h"

int get_RNG_int(int min, int max);
void wait(int milliseconds);
void mofidyMapAtPos(int x,int y,int ** map,int value);
//Item
void addItemToListItem(ListItem* list, Item* item);
void removeItemFromListItem(ListItem* list, int index);
Item* getItemFromListItem(ListItem* list, int index);
void addItemToPlayerInventory(Player* player, Item* item);
void removeItemFromPlayerInventory(Player* player, int index);
Item* getItemFromPlayerInventory(Player* player, int index);
//Weapon
void addWeaponToListWeapon(ListWeapon* list, Weapon* weapon);
void removeWeaponFromListItem(ListWeapon* list, int index);
Weapon* getWeaponFromListItem(ListWeapon* list, int index);
void addWeaponToPlayerInventory(Player* player, Weapon* weapon);
void removeWeaponFromPlayerInventory(Player* player, int index);
Weapon* getWeaponFromPlayerInventory(Player* player, int index);
void swapWeaponFromListWeaponWithPlayer(ListWeapon* list, int index,Player * player);
void swapArmorFromListArmorWithArmor(ListArmor *listArmor,enum Armor_type type,Player * player,char * name);
//Armor
void addArmorToListArmor(ListArmor* list, Armor* armor);
void removeArmorFromListItem(ListArmor* list, int index);
Armor* getArmorFromListItem(ListArmor* list, int index);
void addArmorToPlayerInventory(Player* player, Armor* armor);
void removeArmorFromPlayerInventory(Player* player, int index);
Armor* getArmorFromPlayerInventory(Player* player, int index);
int getIndexArmorFromListArmor(ListArmor * list,enum Armor_type type,char * name);

#endif //PORJET_C_FUNC_H
