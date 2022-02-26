// using command line arguments for coppying file contents into another file
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fs, *ft;
    char ch;
    if (argc != 3)
    {
        puts("Improper number of arguments\n");
        exit(1);
    }
    fs = fopen(argv[1], "r");
    if (fs == NULL)
    {
        printf("Cannot open the source file\n");
        exit(2);
    }
    ft = fopen(argv[2], "w");
    if (ft == NULL)
    {
        printf("Cannot open the target file\n");
        fclose(fs);
        exit(3);
    }
    while (!feof(fs))
    {
        ch = fgetc(fs);
        if (ferror(fs))
        {
            printf("error in reading the file\n");
            break;
        }
        else
        {
            fputc(ch, ft);
        }
    }
    fclose(fs);
    fclose(ft);
    return 0;
}