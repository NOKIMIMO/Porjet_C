#ifndef PORJET_C_VISUAL_H
#define PORJET_C_VISUAL_H
#include "func.h"
#include "deathScreen.h"

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
void buildInteraction(int x, int y,int x2,int y2, char **str, int selectedIndex, int itemCount);
void printLife(int x, int y, int currentLife, int maxLife);
void printXP(int x, int y, int currentXP, int maxXP);
void killVisual();
void printFromToShape(int x1,int y1,int x2,int y2,char * str);
void printFromToLine(int x,int y,int width,char str);
void buildBasic(Player player);
void printDmg(int x, int y, int currentDmg);
void printDef(int x, int y, int currentDef);
void printMana(int x, int y, int currentMana, int maxMana);
int attackVisual(Monster * monster,Player * player, int nb_monster,int value);
int itemVisual(Monster * monster,Player * player);
int skillVisual(Monster * monster,int nb_monster,Player * player);
void showHPReceived(int value, int x, int y);
void showManaReceived(int value, int x, int y);
void showXPReceived(int value, int x, int y);
void showBothReceived(int value1,int value2, int x, int y);
void showDmgReceived(int value,Monster * monster,int x, int y);
int buildMapGraph(int x,int y,Player *player,int ** map,int iteration);
void printMap(int x,int y, int ** map);
int skillInteraction(int x,int y,Player * player,int skill_number);
void itemInteraction(int x,int y, Player * player);
int weaponInteraction(int x,int y,Player * player);
int armorInteraction(int x,int y, Player *player ,int type);
void buildInventory(int x, int y, Player * player);
void buildEnnemies(int x, int y, Monster * monster);
//retourne 0 si tout c'est bien passé et exit normal, 1 si le joueur est mort, 2 si autre (bug)
int visual(Player * player,int boss_flag,int iteration);
void lootRoll(Player * player,int x,int y);


#endif //PORJET_C_VISUAL_H
