//
// Created by ACER PREDATOR on 01/11/2023.
//
#include "deathScreen.h"
//affiche monstre tué / équipement / level

void deathPlayer(Player * player)
{
    char str[100];
    killVisual();
    buildBoxInteraction(50,10,5,5);
    printStrAt(7,7,"Vous êtes mort");
    sprintf(str,"Vous avez accumulé %d xp, votre niveau était %d", (get_level_P(player)-1) * 100 + get_xp_P(player), get_level_P(player));
    printStrAt(7,8,str);
    fflush(stdout);
    wait(5000);
}