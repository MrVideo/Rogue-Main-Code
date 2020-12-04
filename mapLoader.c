#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //Dichiarazione variabili
    FILE *map = fopen("map1.txt", "r");
    int dim, i, j, k = 0;
    char currentLine[100], mapMatrix[100][100];

    //Inizializzazione array e matrice
    for(i = 0; i < 100; i++)
    {
        *(currentLine + i) = '\0';

        for(j = 0; j < 100; j++)
            mapMatrix[i][j] = '\0';
    }

    //Gestione errore di assenza file
    if(map == NULL)
    {
        printf("File error: file doesn't exist\n");
        return 0;
    }

    //Assegnamento dimensione mappa
    fscanf(map, "%d", &dim);

    //Torna all'inizio e si sposta di 3 caratteri in avanti per saltare la dimensione
    fseek(map, sizeof(char) * 3, SEEK_SET);

    //Stampa la mappa in valori numerici se non è la fine del file
    for(i = 0; i < dim * 2; i++)
    {   
        if(!feof(map)) //Controlla se è alla fine del file
        {
            fgets(currentLine, dim * 2 + 1, map);

            for(j = 0; j < dim * 2 + 1; j++)
            {
                printf("%c", *(currentLine + j));
            }
        }
    }

    //Debug
    for(i = 0; i < dim * 2 + 1; i++)
    {
        for(j = 0; j < dim * 2 + 1; j++)
            printf("%c", mapMatrix[i][j]);
        
        printf("\n");
    }
    //Debug end

    printf("\n"); //A capo per la formattazione

    fclose(map); //Chiusura file

    return 0; //Termine programma
}