#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **mapLoader(int *size, char *filename);

int main()
{
    int dim, i, j, mapMatrix[100][100], **mapPtr, *size;
    char filename[30];

    size = &dim;
    mapPtr = mapMatrix;

    for(i = 0; i < 100; i++)
    {
        for(j = 0; j < 100; j++)
            mapMatrix[i][j] = '\0';
    }

    system("clear");

    printf("Inserisci il nome del file contenente la mappa: ");
    scanf("%s", filename);

    mapPtr = mapLoader(size, &filename[0]);

    //Debug
    for(i = 0; i < dim; i++)
    {
        for(j = 0; j < dim; j++)
            printf("%d", mapMatrix[i][j]);
        
        printf("\n");
    }
    //Debug end
    
    return 0;
}

int **mapLoader(int *size, char *filename)
{
    FILE *map = fopen(filename, "r");
    int i, j, mapMat[100][100];
    char currentLine[100];

    if(map == NULL)
    {
        printf("File error: file doesn't exist\n");
        return 0;
    }

    fscanf(map, "%d", size);

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
                    mapMat[i][j] = (int)currentLine[j];
                }
            }
        }
    }

    fclose(map);

    return &mapMat[0][0];
}