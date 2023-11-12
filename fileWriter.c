//
// Created by alexis on 12/11/23.
//
#include "fileWriter.h"

FILE * write_file(char * path){
    char * full_path = malloc(sizeof (char)*255);
    strcpy(full_path,"../files/");
    strcat(full_path,path);
    FILE * file = fopen(full_path, "w");
    free(full_path);
    if(file==NULL){
        printf("Erreur d'ouverture du fichier");
    }
    return file;
}

void write_player(Player * player){
    char * full_path = malloc(sizeof (char)*255);
    //printf("Nom du joueur : %s\n", get_name_P(player));
    strcpy(full_path,"players/");
    strcat(full_path,"save1");
    FILE * file = write_file(full_path);
    free(full_path);

    fprintf(file,"-name:%s\r\n  level:%d\n  exp:%d\n  pos_x:%d\n  pos_y:%d\n  og_vie:%d\n  og_mana:%d\n  vie:%d\n  mana:%d\n  weapon:%s\n  head_piece:%s\n  chest_piece:%s\n  leg_piece:%s\n  ring:%s\n  mana_potion:%d\n  vie_potion:%d\n  double_potion:%d\n  skill1:%s\n  skill2:%s"
                 ,get_name_P(player)
                 ,get_level_P(player)
                 ,player->exp
                 ,get_pos_x_P(player)
                 ,get_pos_y_P(player)
                 ,get_og_vie_P(player)
                 ,get_og_mana_P(player)
                 ,get_vie_P(player)
                 ,get_mana_P(player)
                 , get_name_W(get_weapon_P(player))
                 ,player->head_piece == NULL ? "null" : get_name_A(player->head_piece)
                 ,player->chest_piece == NULL ? "null" : get_name_A(player->chest_piece)
                 ,player->leg_piece == NULL ? "null" : get_name_A(player->leg_piece)
                 ,player->ring == NULL ? "null" : get_name_A(player->ring)
                 ,player->inventory == NULL ? 0 : player->inventory->listItem == NULL ? 0 : player->inventory->listItem->potion_mana
                 ,player->inventory == NULL ? 0 : player->inventory->listItem == NULL ? 0 : player->inventory->listItem->potion_hp
                 ,player->inventory == NULL ? 0 : player->inventory->listItem == NULL ? 0 : player->inventory->listItem->potion_double
                 ,player->skill1 == NULL ? "null" : get_name_S(player->skill1)
                 ,player->skill2 == NULL ? "null" : get_name_S(player->skill2)
                 );
    fprintf(file,"\n-inventory:\n");
    if(player->inventory != NULL){
        for (int i = 0; i < player->inventory->listWeapon->size ; ++i) {
            fprintf(file, "  -weapon:%s\n",get_name_W(player->inventory->listWeapon->weapon[i]));
        }
        for (int i = 0; i < player->inventory->listArmor->size ; ++i) {
            fprintf(file, "  -armor:%s\n",get_name_A(player->inventory->listArmor->armor[i]));
        }
        for (int i = 0; i < player->inventory->listSkill->size ; ++i) {
            fprintf(file, "  -skill:%s\n",get_name_S(player->inventory->listSkill->skill[i]));
        }
    }
    //write maps
    fprintf(file,"-map:\n");
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            fprintf(file,"%d",player->map[i][j]);
        }
        fprintf(file,"\n");
    }
    fclose(file);
}




