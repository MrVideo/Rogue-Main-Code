#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loadMap(int **mapMatrix, int *size, char *filename);

int main()
{
    char filename[20];
    int size = 0, *sizePtr, **mapMatrix, i, j;

    mapMatrix = calloc(100, sizeof(int));
    for(i = 0; i < 100; i++)
        mapMatrix[i] = calloc(100, sizeof(int));

    //Debug    
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
            printf("%d ", mapMatrix[i][j]);
        
        printf("\n");
    }

    printf("\nPrimo elemento della matrice: %d\n", mapMatrix[0][0]);
    //Debug end

    sizePtr = &size;
    
    printf("Inserisci il nome della mappa: ");
    scanf("%s", filename);

    loadMap(&mapMatrix[0], sizePtr, filename);

    //Debug
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
            printf("%d ", mapMatrix[i][j]);
        
        printf("\n");
    }

    printf("\nPrimo elemento della matrice: %d\n", mapMatrix[0][0]);
    //Debug end
}

void loadMap(int **mapMatrix, int *size, char *filename)
{
    FILE *map = fopen(filename, "r");
    char currentLine[100];
    int i, j, spaceCounter = 0;

    fscanf(map, "%d", size);
    //Debug
    printf("\nDimensione: %d\n", *size);
    //Debug end

    fseek(map, sizeof(char) * 3, SEEK_SET);

    for(i = 0; i < *size; i++)
    {   
        if(!feof(map))
        {
            fgets(currentLine, *size * 2, map);
            fseek(map, sizeof(char) * 2, SEEK_CUR);
            
            for(j = 0; j < *size * 2; j++)
            {
                if(currentLine[j] != ' ')
                {
                    mapMatrix[i][spaceCounter] = (int)currentLine[j];
                    spaceCounter++;
                    //Debug
                    printf("%c ", currentLine[j]);
                    //Debug end
                }
            }
            spaceCounter = 0;
            //Debug
            printf("\n");
            //Debug end
        }
    }
}