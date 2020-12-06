#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[20], currentLine[100], **mapMatrix;
    int mapSize, i, j, spaceCounter = 0;

    mapMatrix = calloc(100, sizeof(int));
    for(i = 0; i < 100; i++)
        mapMatrix[i] = calloc(100, sizeof(int));
    for(i = 0; i < 100; i++)
        for(j = 0; j < 100; j++)
            **(mapMatrix + j) = '\0';
    
    system("clear");

    printf("Inserisci il nome del file da aprire: ");
    scanf("%s", filename);
    
    FILE *map = fopen(filename, "r");

    if(map == NULL)
    {
        printf("\nImpossibile aprire il file.\n");
        return 0;
    }

    fscanf(map, "%d", &mapSize);

    printf("\nLa dimensione è: %d\n", mapSize);

    for(i = 0; i < mapSize; i++)
    {
        if(!feof(map))
        {
            fseek(map, 2 * mapSize * sizeof(char) * (i + 1), SEEK_SET);

            fscanf(map, "%s", currentLine);

            for(j = 0; j < mapSize * 2; j++)
            {
                if(currentLine[j] != ' ' || currentLine[j] != '\n')
                {
                    mapMatrix[i][spaceCounter] = currentLine[j];
                    spaceCounter++;

                    printf("\nPosizione attuale del cursore: %ld", ftell(map));
                    printf("\nCarattere in currentLine[%d]: %c\n", j, currentLine[j]);
                    

                }
            }

            spaceCounter = 0;
        }
    }

    printf("\nLa mappa numerica è:\n");
    
    for(i = 0; i < mapSize; i++)
    {
        for(j = 0; j < mapSize * 2; j++)
        {
            printf("%d ", mapMatrix[i][j]);
        }

        printf("\n");
    }

    fclose(map);

    return 0;
}