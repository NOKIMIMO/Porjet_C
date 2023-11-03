#ifndef PORJET_C_FUNC_H
#define PORJET_C_FUNC_H
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "init.h"
#include "combat.h"
#include "lifeCycle.h"

int get_RNG_int(int min, int max);
void wait(int milliseconds);
void mofidyMapAtPos(int x,int y,int ** map,int value);
#endif //PORJET_C_FUNC_H
