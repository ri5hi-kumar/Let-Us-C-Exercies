// this code will copy contents of one file into the other
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> /* for prototypes of islower and toupper */

int main()
{
    FILE *fs, *ft;
    char ch, source[20], target[20];
    // printf("Entre the source name:\n");
    // fgets(source, 20, stdin);
    // printf("Entre the target name:\n");
    // fgets(target, 20, stdin);

    fs = fopen("sample.txt", "r");
    if (fs == NULL)
    {
        printf("Cannot open the source file\n");
        exit(1);
    }
    ft = fopen("sample2.txt", "w");
    if (ft == NULL)
    {
        printf("Cannot open the target file\n");
        fclose(fs);
        exit(2);
    }

    while ((ch = fgetc(fs)) != EOF)
    {
        if (islower(ch))
        {
            fputc(toupper(ch), ft);
        }
    }
    printf("\nFile copied\n");
    fclose(fs);
    fclose(ft);
    return 0;
}