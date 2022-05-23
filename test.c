#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mapLoader(char **mapMatrix, int *size, char *filename);

int main()
{
    int *size, i, j, mapSize;
    char filename[20], **mapMatrix, map[100][100];

    mapMatrix = calloc(100, sizeof(int));
    for(i = 0; i < 100; i++)
        mapMatrix[i] = calloc(1, sizeof(int));

    size = &mapSize;
    *mapMatrix = &map[0][0];

    system("clear");

    printf("Inserisci il nome della mappa: ");
    scanf("%s", filename);
    
    mapLoader(mapMatrix, size, filename);

    printf("\nLa mappa è:\n");
    
    for(i = 0; i < *size; i++)
    {
        for(j = 0; j < *size; j++)
        {
            printf("%d ", mapMatrix[i][j]);
        }

        printf("\n");
    }

    return 0;
}

void mapLoader(char **mapMatrix, int *size, char *filename)
{
    FILE *mapFile = fopen(filename, "r");
    int i, j;

    printf("\nPosizione: %ld\n", ftell(mapFile));
    
    fscanf(mapFile, "%d", size);
    printf("\nLa dimensione della mappa è %d", *size);

    printf("\nPosizione: %ld\n", ftell(mapFile));

    if(*size < 10)
        fseek(mapFile, sizeof(char), SEEK_CUR);
    else if(*size >= 10)
        fseek(mapFile, sizeof(char) * 2, SEEK_CUR);

    for(i = 0; i < *size; i++)
    {
        for(j = 0; j < *size; j++)
        {
            fscanf(mapFile, "%c%*c", *(mapMatrix + j));

            printf("\nmapMatrix[%d][%d] = %d", i, j, mapMatrix[i][j]);
            printf("\nPosizione: %ld", ftell(mapFile));
            
            //fseek(mapFile, sizeof(char), SEEK_CUR);
        }
    }
}