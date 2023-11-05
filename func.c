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