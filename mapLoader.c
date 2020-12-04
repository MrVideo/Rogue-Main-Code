#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *map = fopen("map1.txt", "r");
    int dim, i, j, k = 0;
    char currentLine[100], mapMatrix[100][100];

    for(i = 0; i < 100; i++)
    {
        *(currentLine + i) = '\0';

        for(j = 0; j < 100; j++)
            mapMatrix[i][j] = '\0';
    }

    if(map == NULL)
    {
        printf("File error: file doesn't exist\n");
        return 0;
    }

    fscanf(map, "%d", &dim);

    fseek(map, sizeof(char) * 3, SEEK_SET);

    for(i = 0; i < dim * 2; i++)
    {   
        if(!feof(map))
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

    printf("\n");

    fclose(map);

    return 0;
}