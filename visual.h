#ifndef PORJET_C_VISUAL_H
#define PORJET_C_VISUAL_H
#include "func.h"

#define interaction_x 7
#define interaction_y 22

#define mob_pos_x 5
#define mob_pos_y 5


void printStrAt(int x, int y, char *str);
void printCharAt(int x, int y, char str);
void printIntAt(int x, int y, int val);
void clearAll();
void clearAt(int x, int y);
void clearFromTo(int x1, int y1, int x2, int y2);
void moveCursor(int x, int y);
void buildBoxInteraction(int width, int height,int x, int y);
void buildInteraction(int x, int y, char **str, int selectedIndex, int itemCount);
void printLife(int x, int y, int currentLife, int maxLife);
void killVisual();
void printFromToShape(int x1,int y1,int x2,int y2,char * str);
void printFromToLine(int x,int y,int width,char str);
void buildBasic(Player player);
void printMana(int x, int y, int currentMana, int maxMana);
int attackVisual(Monster * monster,Player * player, int nb_monster);
int itemVisual(Monster * monster,Player * player);
int skillVisual(Monster * monster,Player * player);
void showHPReceived(int value, int x, int y);
void buildMapGraph(int x,int y,Player player,int ** map);
void showDMGReceived(int value, int x,Monster * monster, int y);
//retourne 0 si tout c'est bien passé et exit normal, 1 si le joueur est mort, 2 si autre (bug)
int visual(Player * player);

#endif //PORJET_C_VISUAL_H
