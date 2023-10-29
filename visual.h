#ifndef PORJET_C_VISUAL_H
#define PORJET_C_VISUAL_H
#include "func.h"
void printAt(int x, int y, char *str);
void clearAll();
void clearAt(int x, int y);
void clearFromTo(int x1, int y1, int x2, int y2);
void moveCursor(int x, int y);
void buildBoxInteraction(int width, int height,int x, int y);
void buildInteraction(int x, int y, char **str, int selectedIndex, int itemCount);
void printLife(int x, int y, int currentLife, int maxLife);
void killVisual();
void buildBasic(Player player);
void printMana(int x, int y, int currentMana, int maxMana);
int attackVisual(Monster ** monster,Player * player, int nb_monster);
int itemVisual(Monster ** monster,Player * player);
int skillVisual(Monster ** monster,Player * player);
//retourne 1 si tout c'est bien passé
int visual();

#endif //PORJET_C_VISUAL_H
