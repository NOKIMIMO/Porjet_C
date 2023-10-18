#ifndef PORJET_C_VISUAL_H
#define PORJET_C_VISUAL_H
#include "func.h"
void printAt(int x, int y, char *str);
void clearAll();
void moveCursor(int x, int y);
void buildBoxInteraction(int width, int height,int x, int y);
void buildInteraction(int x, int y, char **str, int selectedIndex, int itemCount);
void printLife(int x, int y, int currentLife, int maxLife);
//retourne 1 si tout c'est bien passé
int visual();

#endif //PORJET_C_VISUAL_H
