//
// Created by Alexis on 14/10/2023.
//
#include "fileReader.h"
#include "func.h"
#include <string.h>

FILE * open_file(char * path){
    char * full_path = malloc(sizeof (char)*255);
    strcpy(full_path,"../files/");
    strcat(full_path,path);
    FILE * file = fopen(full_path, "r");
    free(full_path);
    if(file==NULL){
        printf("Erreur d'ouverture du fichier");
        exit(-1);
    }
    return file;
}

int read_line(FILE * file, int * index){
    fseek(file, *index, SEEK_SET);
    char * buffer = malloc(sizeof (char)*20);
    char c = fgetc(file);
    int i =0;
    while (c!=':') {
        c= fgetc(file);
    }
    while (c!=' ' && c!=EOF && c!='\n') {
        c = fgetc(file);
        buffer[i] = c;
        ++i;
    }
    int ret = atoi(buffer);
    free(buffer);
    *index = ftell(file);
    return ret;
}

int find_key(FILE * file, char * key){
    fseek(file, 0, SEEK_SET);
    char * cur_key = malloc(sizeof (char)*50);
    int i = 0;
    char c = fgetc(file);
    while (strcmp(cur_key,key)!=0 && c!=EOF){
        while (c==' ' || c=='\n' || c=='-') {
            c= fgetc(file);
        }
        while (c!=':') {
            cur_key[i] = c;
            ++i;
            c= fgetc(file);
        }
        cur_key[i]='\0';
        i=0;
        c= fgetc(file);
        while (c!='\n' && c!=EOF) {
            c= fgetc(file);
        }
    }
    if(c ==EOF){
        return -1;
    }
    free(cur_key);
    return ftell(file);
}

char * read_ascii(FILE * file, int * index){

    fseek(file, *index, SEEK_SET);

    char * buffer = malloc(sizeof (char)*200);
    char c = fgetc(file);
    int i =0;
    while (c!=':'){
        c= fgetc(file);
    }
    while (c!=EOF) {
        c = fgetc(file);
        buffer[i] = c;
        if(buffer[i]=='\n')
            buffer[i]='&';
        ++i;
    }
    *index = ftell(file);
    buffer[i-1]='\0';
    buffer = realloc(buffer, sizeof (char)* strlen(buffer)+1);
    return buffer;
}

char * read_str(FILE * file, int * index){
    fseek(file, *index, SEEK_SET);
    char * name = malloc(sizeof (char)*50);
    char c= fgetc(file);
    int i =0;
    while (c!=':') {
        c= fgetc(file);
    }

    while (c!='\n'&& c!=EOF) {
        c = fgetc(file);
        name[i] = c;
        ++i;
    }
    name[i-1]='\0';
    *index = ftell(file);
    return name;
}

int read_inventory_line(FILE * file, int * position, char ** key, char ** value){
    fseek(file, *position, SEEK_SET);
    char * buffer = malloc(sizeof (char)*50);
    char c = fgetc(file);
    int i =0;
    char * newKey = malloc(sizeof (char)*50);
    while (c!='-') {
        c= fgetc(file);
    }
    c= fgetc(file);
    while (c!=':') {
        newKey[i] = c;
        ++i;
        c= fgetc(file);
    }

    strcpy(*key,newKey);
    i=0;
    while (c!='\n'&& c!=EOF) {
        c = fgetc(file);
        buffer[i] = c;
        ++i;
    }

    if(strcmp(*key,"map")==0){
        return -1;
    }
    buffer[i-1]='\0';
    strcpy(*value,buffer);
    *position = ftell(file);
    return 0;
}

int ** read_map(FILE * file, int *position){
    fseek(file, *position-2, SEEK_SET);
    char * buffer = malloc(sizeof (char)*50);
    char c = fgetc(file);
    int i =0;
    int ** map = malloc(sizeof(int*)*7);
    for (int j = 0; j < 7; ++j) {
        map[j] = malloc(sizeof(int)*7);
    }
    c= fgetc(file);
    while (c!=EOF) {
        c = fgetc(file);
        buffer[i] = c;
        ++i;
    }

    buffer[i-1]='\0';
    printf("\n%s\n",buffer);
    int k = 0;
    for (int j = 0; j < 7; ++j) {
        for (int l = 0; l < 7; ++l) {
            map[j][l] = buffer[k+j]-'0';
            ++k;
        }
    }
    *position = ftell(file);
    return map;
}

Monster read_monster(char * path){
    char * full_path = malloc(sizeof (char)*255);
    strcpy(full_path,"monsters/");
    strcat(full_path,path);
    FILE * file = open_file(full_path);
    free(full_path);
    int hp, def, atk;
    int position = (int) ftell(file);
    char * name = read_str(file, &position);
    char temp[strlen(name)-4];
    for (int i = 0; i < strlen(name)-1; ++i) {
        temp[i] = name[i];
    }
    strcpy(name,temp);
    hp= read_line(file, &position);
    atk= read_line(file, &position);
    def= read_line(file, &position);
    char * ascii = read_ascii(file, &position);

    Monster * newMonster = malloc(sizeof(Monster));
    *newMonster = create_monster(name,
                                 hp,
                                 atk,
                                 def,
                                 ascii
    );
    return *newMonster;

}

Weapon * read_weapon(char * path){
    char * full_path = malloc(sizeof (char)*255);
    strcpy(full_path,"weapons/");
    strcat(full_path,path);
    FILE * file = open_file(full_path);
    free(full_path);
    int atk;
    int position = ftell(file);
    char * name = read_str(file, &position);
    atk= read_line(file, &position);

    Weapon * newWeapon = create_weapon(atk,name);
    return newWeapon;
}

Skill * read_skill(char * path){
    char * full_path = malloc(sizeof (char)*255);
    strcpy(full_path,"skills/");
    strcat(full_path,path);
    FILE * file = open_file(full_path);
    free(full_path);
    int atk, mana;
    int position = ftell(file);
    char * name = read_str(file, &position);
    atk= read_line(file, &position);
    mana= read_line(file, &position);

    Skill * newSkill = create_skill(name,mana,atk);
    return newSkill;
}

Armor * read_armor(char * path) {
    char * full_path = malloc(sizeof (char)*255);
    strcpy(full_path,"armors/");
    strcat(full_path,path);
    FILE * file = open_file(full_path);
    free(full_path);

    int mana, def;
    int position = ftell(file);
    char * name = read_str(file, &position);
    mana= read_line(file, &position);
    def= read_line(file, &position);
    char * armor_type = read_str(file, &position);


    int armor_t;
    if(strcmp(armor_type,"head_piece")==0)
        armor_t = head_piece;
    if(strcmp(armor_type,"chest_piece")==0)
        armor_t = chest_piece;
    if(strcmp(armor_type,"leg_piece")==0)
        armor_t = leg_piece;
    if(strcmp(armor_type,"ring")==0)
        armor_t = ring;
    Armor * newArmor = create_armor(name,mana,def,armor_t);

    return newArmor;
}

Player * read_player(char * path){
    char * full_path = malloc(sizeof (char)*255);
    strcpy(full_path,"players/");
    strcat(full_path,path);
    FILE * file = open_file(full_path);
    free(full_path);


    int level,exp,og_vie,og_mana,vie,mana, pos_x, pos_y,mana_potion, hp_potion, double_potion;
    int position = ftell(file);
    char * name = read_str(file, &position);
    level= read_line(file, &position);
    exp= read_line(file, &position);
    pos_x =read_line(file, &position);
    pos_y =read_line(file, &position);
    og_vie= read_line(file, &position);
    og_mana= read_line(file, &position);
    vie= read_line(file, &position);
    mana= read_line(file, &position);

    char * weapon_str = malloc(sizeof (char)*50);
    char * head_piece_str = malloc(sizeof (char)*50);
    char * chest_piece_str = malloc(sizeof (char)*50);
    char * leg_piece_str = malloc(sizeof (char)*50);
    char * ring_str = malloc(sizeof (char)*50);

    weapon_str = read_str(file, &position);
    head_piece_str = read_str(file, &position);
    chest_piece_str = read_str(file, &position);
    leg_piece_str = read_str(file, &position);
    ring_str= read_str(file, &position);

    mana_potion = read_line(file, &position);
    hp_potion = read_line(file, &position);
    double_potion = read_line(file, &position);

    char * skill1 = malloc(sizeof (char)*50);
    char * skill2 = malloc(sizeof (char)*50);

    skill1 = read_str(file, &position);
    skill2 = read_str(file, &position);

    Weapon * weapon = read_weapon(weapon_str);
    Armor * head = read_armor(head_piece_str);
    Armor * chest = read_armor(chest_piece_str);
    Armor * leg = read_armor(leg_piece_str);
    Armor * player_ring = read_armor(ring_str);

    if(head->armor_type != head_piece)
        head = NULL;
    if(chest->armor_type != chest_piece)
        chest = NULL;
    if(leg->armor_type != leg_piece)
        leg = NULL;
    if(player_ring->armor_type != ring)
        player_ring = NULL;

    Skill * player_skill1 = NULL;
    Skill * player_skill2 = NULL;
    if(strcmp("null",skill1))
        player_skill1 = read_skill(skill1);
    if(strcmp("null",skill2))
        player_skill2 = read_skill(skill2);

    Player * newPlayer = create_player(name,
                                       og_vie,
                                       pos_x,
                                       pos_y,
                                       og_mana,
                                       vie,
                                       mana,
                                       weapon,
                                       head,
                                       chest,
                                       leg,
                                       player_ring,
                                       player_skill1,
                                       player_skill2);


    position = find_key(file,"inventory");
    int items[3] = {hp_potion,mana_potion,double_potion};

    ListArmor * list_armor = create_list_armor(10);
    ListWeapon *  list_weapon = create_list_weapon(10);
    ListSkill * list_skill = create_list_skill(10);

    if(position != -1){
        char ** key = malloc(sizeof(char));
        char **value = malloc(sizeof(char));
        *key = malloc(sizeof(char)*50);
        *value = malloc(sizeof(char)*50);
        read_inventory_line(file, &position, key, value);
        while(read_inventory_line(file, &position, key, value ) != -1){

            if(strcmp(*key,"armor")==0) {
                Armor *armor = read_armor(*value);
                addArmorToListArmor(list_armor, armor);
            }
            if(strcmp(*key,"weapon")==0) {
                Weapon *weapon = read_weapon(*value);
                addWeaponToListWeapon(list_weapon, weapon);
            }
            if(strcmp(*key,"skill")==0) {
                Skill *skill = read_skill(*value);
                addSkillToListSkill(list_skill, skill);
            }

        }
        Inventory * inventory = create_inventory(items, 10,10,10);
        inventory->listArmor = list_armor;
        inventory->listWeapon = list_weapon;
        inventory->listSkill = list_skill;
        newPlayer->inventory = inventory;
    }

    position = find_key(file,"map");
    if(position != -1){
        int ** map = read_map(file, &position);
        newPlayer->map= map;

    }
    return newPlayer;

}
