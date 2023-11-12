//
// Created by ACER PREDATOR on 01/11/2023.
//

#include "game.h"


int game(int save_flag){
    Player * player;
    int x_depart = 0, y_depart = 0;
    int ** map;
    if(save_flag == 1){
       player = read_player("save1");
       map = player->map;
    }else{
        x_depart = get_RNG_int(1,7);
        y_depart = get_RNG_int(1,7);
        map = initMap(7,7,x_depart-1,y_depart-1);
        int *temp=searchEntry(map,7,7);
        x_depart = temp[0]+1;
        y_depart = temp[1]+1;
        player= create_player("save1",
                                       100,
                                       x_depart,
                                       y_depart,
                                       100,
                                       100,
                                       100,
                                       create_weapon(100,"épet des vents"),
                                       NULL,
                                       create_armor( "plastron", 5, 5, chest_piece),
                                       NULL,
                                       create_armor("anno",20,0,ring),
                                       create_skill("nuke",60,40),
                                       create_skill("Ice pick",10,10));

    int ** map = initMap(7,7,x_depart-1,y_depart-1);
    int *temp=searchEntry(map,7,7);
    x_depart = temp[0]+1;
    y_depart = temp[1]+1;
    Player * player= create_player("save1",
                                   100,
                                   x_depart,
                                   y_depart,
                                   100,
                                   100,
                                   100,
                                   create_weapon(100,"épet des vents"),
                                   NULL,
                                   create_armor( "plastron", 5, 5, chest_piece),
                                   NULL,
                                   create_armor("anno",20,0,ring),
                                   create_skill("nuke",60,40),
                                   create_skill("Ice pick",10,10));

    int ret=0;
    while(1){
        int cpt= 0;
        ret = buildMapGraph(3,5,player,map,cpt);
        if (ret==1){
            //le joueur est mort
            return 0;
        }else if(ret == 0){
            //Exit normal du joueur / fin de combat
            write_player(player);
            cpt++;
            map = initMap(7,7,x_depart-1,y_depart-1);
            int *temp2=searchEntry(map,7,7);
            x_depart = temp2[0]+1;
            y_depart = temp2[1]+1;
            set_pos_x_P(player,x_depart);
            set_pos_y_P(player,y_depart);
        }else if(ret == 2){
            //Exit complete du jeu
            return 2;
        }else{
            printf("Erreur");
            return -1;
        }
    }

}