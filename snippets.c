if(fgetc(map) == '0')
            printf(" ");
        if(fgetc(map) == '1')
            printf("#");
        if(fgetc(map) == '2')
            printf("O");
        if(fgetc(map) == '3')
            printf("P");
        if(fgetc(map) == '\n')
            printf("\n");
        else if(fgetc(map) != ' ')
        {
            printf("\n%c\n", fgetc(map));
            printf("\nFile error in mapPrint\n");
            return 0;
        }