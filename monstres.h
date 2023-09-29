//
// Created by Romain on 29/09/2023.
//

#ifndef PROJET_C_MONSTRES_H
#define PROJET_C_MONSTRES_H

#endif //PROJET_C_MONSTRES_H

typedef struct
{
    int vie;
    int puissance;
    int defense;
}Monstre;

int generationNombreAleatoire(int max);

Monstre creationMonstre();