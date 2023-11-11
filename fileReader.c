//
// Created by Alexis on 14/10/2023.
//
#include "fileReader.h"
#include <string.h>

FILE * open_file(char * path){
    char * full_path = malloc(sizeof (char)*255);
    strcpy(full_path,"./files/");
    strcat(full_path,path);
    printf("\n%s",full_path);
    FILE * file = fopen(full_path, "r");
    printf("\n%s",full_path);
    free(full_path);
    if(file==NULL){
        printf("Erreur d'ouverture du fichier");
    }
    return file;
}

int read_line(FILE * file, int * index){
    fseek(file, *index, SEEK_SET);
    char * buffer = malloc(sizeof (char)*20);
    char c = fgetc(file);
    int i =0;
    while (c!=':') {
        //printf("%c",c);
        c= fgetc(file);
    }
    while (c!=' ' && c!=EOF && c!='\n') {
        //printf("%c",c);
        c = fgetc(file);
        buffer[i] = c;
        ++i;
    }
    int ret = atoi(buffer);
    free(buffer);
    *index = ftell(file);
//    printf("\n%d",ret);
    return ret;
}
int find_key(char * key){
    return 0;
}
char * read_ascii(FILE * file, int * index){
    fseek(file, *index, SEEK_SET);

    char * buffer = malloc(sizeof (char)*200);
    char c = fgetc(file);
    int i =0;
    while (c!='-' && c!=EOF){
        c= fgetc(file);
    }

    while (c!=':'){
        c= fgetc(file);
    }
    while (c!=EOF) {
        c = fgetc(file);
        buffer[i] = c;
        ++i;
    }
    *index = ftell(file);
    buffer[i-2]='\0';
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

Monster * read_monster(char * path){
    char * full_path = malloc(sizeof (char)*255);
    strcpy(full_path,"monsters/");
    strcat(full_path,path);
    FILE * file = open_file(full_path);
    free(full_path);
    int hp, def, atk;
    char c= fgetc(file);
    int position = ftell(file);
    char * name = read_str(file, &position);
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
    return newMonster;
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

Item * read_item(char * path){
    char * full_path = malloc(sizeof (char)*255);
    strcpy(full_path,"items/");
    strcat(full_path,path);
    FILE * file = open_file(full_path);
    free(full_path);
    int hp, mana;
    int position = ftell(file);
    char * name = read_str(file, &position);
    hp= read_line(file, &position);
    mana= read_line(file, &position);

    Item * newItem = create_item(name,mana,hp);
    return newItem;
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
    printf("\n%s",full_path);
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

    Player * newPlayer = create_player(og_vie,
                                       pos_x,
                                       pos_y,
                                       og_mana,
                                       vie,
                                       mana,
                                       weapon,
                                       head,
                                       chest,
                                       leg,
                                       player_ring

                                       );
    //print player
    printf("\n%d",newPlayer->vie);
    //scanf("%d",&level);
    return newPlayer;

}
