#include "lifeCycle.h"

int get_XP(Player * player,int nb_monster,int iteration){
    int xp = 0;
    for(int i = 0;i<nb_monster;i++){
        xp += get_RNG_int(10,30) *iteration;
    }
    set_xp_P(player,get_xp_P(player)+xp);
    level_up_P(player);
    return xp;
}

void level_up_P(Player * player){
    while(get_xp_P(player)>=100){
        set_xp_P(player,get_xp_P(player)-100);
        set_level_P(player,get_level_P(player)+1);
        refresh_stat_lvl_P(player);
    }
}
void refresh_stat_armor_P(Player * player){
    int def = 0;
    int mana= get_og_mana_P(player);
    if(get_head_piece_P(player)!=NULL){
        def += get_def_A(get_head_piece_P(player));
        mana+= get_mana_A(get_head_piece_P(player));
    }
    if(get_chest_piece_P(player)!=NULL){
        def += get_def_A(get_chest_piece_P(player));
        mana+= get_mana_A(get_chest_piece_P(player));
    }
    if(get_leg_piece_P(player)!=NULL){
        def += get_def_A(get_leg_piece_P(player));
        mana+= get_mana_A(get_leg_piece_P(player));
    }
    if(get_ring_P(player)!=NULL){
        def += get_def_A(get_ring_P(player));
        mana+= get_mana_A(get_ring_P(player));
    }
    set_def_P(player,def);
    set_og_mana_P(player,mana);
}
void refresh_stat_lvl_P(Player * player){
    //sensé arriver a chaque level up
    int vie = get_vie_P(player);
    int og_vie = get_og_vie_P(player);
    int mana = get_mana_P(player);
    int og_mana = get_og_mana_P(player);
    int added_vie = get_RNG_int(5,10);
    int added_mana = get_RNG_int(5,10);
    set_vie_P(player,vie+added_vie);
    set_og_vie_P(player,og_vie+added_vie);
    set_mana_P(player,mana+added_mana);
    set_og_mana_P(player,og_mana+added_mana);
    refresh_stat_armor_P(player);

}