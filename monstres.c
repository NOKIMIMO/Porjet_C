#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int vie;
    int puissance;
    int defense;
}Monstre;

int generationNombreAleatoire(int max)
{
    srand( time(NULL));
    return rand() % max;
}

Monstre creationMonstre()
{
    Monstre monstre;
    monstre.vie = generationNombreAleatoire(100);
    monstre.puissance = generationNombreAleatoire(10);
    monstre.defense = generationNombreAleatoire(10);

    return monstre;
}

