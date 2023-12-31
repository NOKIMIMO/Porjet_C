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
#include "fileReader.h"

int get_RNG_int(int min, int max);
void wait(int milliseconds);
void mofidyMapAtPos(int x,int y,int ** map,int value);
//Player
void give_mana_P(Player * player,int hp);
void give_hp_P(Player * player,int hp);
//Item
void use_potion(Player *player,int type);
void remove_potion(Player *player,int type);
void add_potion(Player *player,int type,int quantity);
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
//Skill
void addSkillToListSkill(ListSkill* list, Skill* skill);
void removeSkillFromListSkill(ListSkill* list, int index);
Skill* getSkillFromListSkill(ListSkill* list, int index);
void addSkillToPlayerInventory(Player* player, Skill* skill);
void removeSkillFromPlayerInventory(Player* player, int index);
Skill* getSkillFromPlayerInventory(Player* player, int index);
void swapSkillFromListSkillWithPlayer(ListSkill* list, int index,Player * player,int skillIndex);
int verifPresenceSalle(int **map,int x, int y);
int generationSalle(int **map,int x,int y);
int * searchEntry(int ** map, int rows, int cols);
int creationRoomBoss(int** map,int x,int y);
//get random X
char * get_random_weapon();
char * get_random_armor();
char * get_random_monster();
#endif //PORJET_C_FUNC_H
