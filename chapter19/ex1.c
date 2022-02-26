//for reading the text file
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch;
    int count = 1;
    fp = fopen("sample.txt", "r");
    if (fp == NULL)
    {
        printf("Enable to open the file\n");
        exit(1);
    }
    printf("\n%3d: ", count);
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
        {
            count++;
            printf("\n%3d: ", count);
        }
        else
        {
            printf("%c", ch);
        }
    }
    printf("\n");
    fclose(fp);
    return 0;
}