#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //Dichiarazione variabili
    FILE *map = fopen("map1.txt", "r");
    int dim, i, j, k;
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
    for(i = 0; i < dim; i++)
    {   
        if(!feof(map)) //Controlla se è alla fine del file
        {
            fgets(currentLine, dim * 2, map);
            fseek(map, sizeof(char) * 2, SEEK_CUR);
            
            for(j = 0; j < dim * 2; j++)
            {
                if(currentLine[j] != ' ')
                {   
                    mapMatrix[i][j] = currentLine[j];
                }
            }
        }
    }

    fclose(map); //Chiusura file

    return 0; //Termine programma
}