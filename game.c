//
// Created by ACER PREDATOR on 01/11/2023.
//

#include "game.h"

int game(){
    Player * player= create_player(100,
                                   4,
                                   7,
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
    set_vie_P(player,10);
    set_mana_P(player,20);
    set_inventory_P(player,create_inventory((int[]){0, 0, 0},10,10,10));
    add_potion(player,0,7);
    add_potion(player,1,5);
    add_potion(player,2,2);
    addWeaponToPlayerInventory(player, create_weapon(10,"épée de test"));
    addArmorToListArmor(get_listArmor_P(player),create_armor("casque",0,5,head_piece));
    addArmorToListArmor(get_listArmor_P(player),create_armor("plastron_test",0,5,chest_piece));
    addArmorToListArmor(get_listArmor_P(player),create_armor("plastron_test2",0,10,chest_piece));
    addSkillToPlayerInventory(player,create_skill("fireball",10,10));
    refresh_stat_armor_P(player);
    int ** map = initMap(7,7);

//    int ret = visual(player);
    int ret=0;
    if (ret==1){
        //le joueur est mort
        return 0;
    }else if(ret == 0){
        //Exit normal du joueur / fin de combat
        buildMapGraph(3,5,*player,map);
    }else{
        printf("Erreur");
        return -1;
    }
}