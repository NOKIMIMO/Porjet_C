//
// Created by alexis on 07/11/23.
//

#ifndef PORJET_C_FILEREADER_H
#define PORJET_C_FILEREADER_H
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "init.h"

FILE * open_file(char * path);
Monster read_monster(char * path);
Weapon * read_weapon(char * path);
Skill * read_skill(char * path);
Armor * read_armor(char * path);
Player * read_player(char * path);

#endif //PORJET_C_FILEREADER_H
