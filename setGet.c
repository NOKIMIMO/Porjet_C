//
// Created by ACER PREDATOR on 29/09/2023.
//
#include "setGet.h"
////Player stats
// get
int get_vie_P(Player * player){
    return player->vie;
}
int get_mana_P(Player * player){
    return player->mana;
}
int get_og_mana_P(Player * player){
    return player->og_mana;
}
int get_og_vie_P(Player * player){
    return player->og_vie;
}
int get_def_P(Player * player){
    return player->def;
}
int get_ac_P(Player * player){
    return player->ac;
}

int get_xp_P(Player * player) {
    return player->exp;
}
int get_level_P(Player * player){
    return player->level;
}
int get_pos_x_P(Player * player){
    return player->pos_x;
}
int get_pos_y_P(Player * player){
    return player->pos_y;
}

//set
void set_vie_P(Player * player, int vie){
    player->vie = vie;
}
void set_mana_P(Player * player, int mana){
    player->mana = mana;
}
void set_og_mana_P(Player * player,int mana){
    player->og_mana = mana;
}
void set_og_vie_P(Player * player,int vie){
    player->og_vie = vie;
}
void set_def_P(Player * player, int def){
    player->def = (def<0)?0:def;
}
void set_xp_P(Player * player,int xp){
    player->exp = xp;
}
void set_level_P(Player * player,int level){
    player->level = level;
}
void set_ac_P(Player * player,int ac){
    player->ac = ac;
}
void set_pos_x_P(Player * player,int pos_x){
    player->pos_x = pos_x;
}
void set_pos_y_P(Player * player,int pos_y){
    player->pos_y = pos_y;
}
//Player Equip
void set_weapon_P(Player * player, Weapon * weapon){
    player->weapon = weapon;
}

void set_head_piece_P(Player * player, Armor * head_piece){
    player->head_piece = head_piece;
}

void set_chest_piece_P(Player * player, Armor * chest_piece){
    player->chest_piece = chest_piece;
}

void set_leg_piece_P(Player * player, Armor * leg_piece){
    player->leg_piece = leg_piece;
}

void set_ring_P(Player * player, Armor * ring){
    player->ring = ring;
}
void set_armor_P(Player * player, Armor * armor, enum Armor_type armor_type){
    printf("%d",armor_type);
    switch (armor_type){
        case head_piece:
            set_head_piece_P(player,armor);
            break;
        case chest_piece:
            set_chest_piece_P(player,armor);
            break;
        case leg_piece:
            set_leg_piece_P(player,armor);
            break;
        case ring:
            set_ring_P(player,armor);
            break;
        default:
            break;
    }
}
Weapon * get_weapon_P(Player * player){
    return player->weapon;
}
Armor * get_head_piece_P(Player * player){
    return player->head_piece;
}
Armor * get_chest_piece_P(Player * player){
    return player->chest_piece;
}
Armor * get_leg_piece_P(Player * player){
    return player->leg_piece;
}
Armor * get_ring_P(Player * player){
    return player->ring;
}
Armor * get_armor_P(Player * player, enum Armor_type armor_type){
    switch (armor_type){
        case head_piece:
            return get_head_piece_P(player);
        case chest_piece:
            return get_chest_piece_P(player);
        case leg_piece:
            return get_leg_piece_P(player);
        case ring:
            return get_ring_P(player);
        default:
            return NULL;
    }
};
void set_inventory_P(Player * player, Inventory * inventory){
    player->inventory = inventory;
}

////Monster
//getters
int get_vie_M(Monster * monster) {
    return monster->vie;
}
int get_def_M(Monster * monster) {
    return monster->def;
}
int get_level_M(Monster * monster){
    return monster->level;
}

char * get_name_M(Monster * monster){
    return monster->name;
}

//setters
void set_vie_M(Monster * monster, int vie) {
    monster->vie = vie;
}
void set_def_M(Monster * monster,int def) {
    monster->def = (def<0)?0:def;
}

int get_size_LI(ListItem * list){
    return list->size;
}

ListItem * get_listItem_P(Player * player){
    return player->inventory->listItem;
}

ListWeapon * get_listWeapon_P(Player * player){
    return player->inventory->listWeapon;
}

ListArmor * get_listArmor_P(Player * player){
    return player->inventory->listArmor;
}

int get_size_LW(ListWeapon * list){
    return list->size;
}

int get_size_LA(ListArmor * list){
    return list->size;
}
//SKILL
int get_mana_S(Skill * skill){
    return skill->mana;
}
int get_dmg_S(Skill * skill){
    return skill->dmg;
}
char * get_name_S(Skill * skill){
    return skill->name;
}


//ITEM

int get_mana_I(Item * item){
    return item->mana;
}

int get_hp_I(Item * item){
    return item->hp;
}

char * get_name_I(Item * item){
    return item->name;
}

//WEAPON

int get_dmg_W(Weapon * weapon){
    return weapon->dmg;
}

//ARMOR

int get_mana_A(Armor * armor){
    return armor->mana;
}

int get_def_A(Armor * armor){
    return armor->def;
}

char * get_name_A(Armor * armor){
    return armor->name;
}

enum Armor_type get_armor_type_A(Armor * armor){
    return armor->armor_type;
}

////LIST

//ITEM

Item * get_item_LI(ListItem * list, int index){
    return list->item[index];
}

int get_potion_type_I(Player  * player,char * type){
    int size = get_size_LI(get_listItem_P(player));
    int cpt=0;
    if(size>0){
        for (int i = 0; i < size; ++i) {
            if(strcmp(get_name_I(getItemFromListItem(get_listItem_P(player),i)),type)==0){
                cpt++;
            }
        }
    }
    return cpt;
}

//WEAPON

Weapon * get_weapon_LW(ListWeapon * list, int index){
    return list->weapon[index];
}

//ARMOR

Armor * get_armor_LA(ListArmor * list, int index){
    return list->armor[index];
}

////INVENTORY

//LIST


int get_capacity_LI(ListItem * list){
    return list->capacity;
}
int get_capacity_LW(ListWeapon * list){
    return list->capacity;
}
int get_capacity_LA(ListArmor * list){
    return list->capacity;
}

