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
void addItemToListItem(ListItem* list, Item* item);
void removeItemFromListItem(ListItem* list, int index);
Item* getItemFromListItem(ListItem* list, int index);
void addItemToPlayerInventory(Player* player, Item* item);
void removeItemFromPlayerInventory(Player* player, int index);
Item* getItemFromPlayerInventory(Player* player, int index);
#endif //PORJET_C_FUNC_H
