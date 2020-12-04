#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *map = fopen("map1.txt", "r");
    int dim, i, j;
    char currentLine[100], *currentLinePointer;

    currentLinePointer = calloc(100, sizeof(char));

    if(map == NULL)
    {
        printf("File error: file doesn't exist\n");
        return 0;
    }

    fscanf(map, "%d", &dim);

    fseek(map, sizeof(char), SEEK_CUR);

    for(i = 0; i < dim * 2; i++)
    {   
        fgets(currentLine, dim * 2 + 1, map);

        for(j = 0; j < dim * 2; j++)
        {
            printf("%c", *(currentLine + j));
        }
    }

    printf("\n");

    fclose(map);

    return 0;
}