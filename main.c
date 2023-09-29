#include "monstres.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Monstre *tableauDeMonstre;
    int nombreMonstre = generationNombreAleatoire(10);

    tableauDeMonstre = malloc(sizeof(Monstre) * nombreMonstre);

    for(int i = 0; i < nombreMonstre;i++)
    {
        tableauDeMonstre[i] = creationMonstre();
    }

    return  0;
}