#include "lifeCycle.h"

void kill(Monster * monster, Player * player){
    int xp_P = get_xp_P(player);
    xp_P+= get_level_M(monster)*get_RNG_int(1,10);
    set_xp_P(player,xp_P);
    //a check comment gerer les levels up
    if(get_xp_P(player)>=100){
        level_up_P(player);
    }

    destroyMonster(monster);
}

void level_up_P(Player * player){
    while(get_xp_P(player)>=100){
        set_xp_P(player,get_xp_P(player)-100);
        set_level_P(player,get_level_P(player)+1);
        refresh_stat_P(player);
    }
}

void refresh_stat_P(Player * player){
    //sensé arriver a chaque level up
    int vie = get_vie_P(player);
    int mana = get_mana_P(player);
    int def = get_def_P(player);
    int speed = get_speed_P(player);

    vie += get_level_P(player)+get_RNG_int(4+get_level_P(player),10+get_level_P(player));
    mana += get_level_P(player)+get_RNG_int(4+get_level_P(player),10+get_level_P(player));
    def += get_level_P(player)+get_RNG_int(4+get_level_P(player),10+get_level_P(player));
    speed += get_level_P(player)+get_RNG_int(0,1);

    set_vie_P(player,vie);
    set_mana_P(player,mana);
    set_def_P(player,def);
    set_speed_P(player,speed);
}