//to append the contents of one fle at the end of another
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp, *ft;
    char ch;
    fp = fopen("sample.txt", "a");
    if (fp == NULL)
    {
        puts("Cannot open the file\n");
        exit(1);
    }
    ft = fopen("sample2.txt", "r");
    if (ft == NULL)
    {
        puts("Cannot open the file\n");
        fclose(fp);
        exit(2);
    }
    while (1)
    {
        ch = fgetc(ft);
        if (ch == EOF)
        {
            break;
        }
        fputc(ch, fp);
    }
    printf("Appending complete\n");
    fclose(fp);
    fclose(ft);
    return 0;
}

// alternative way after line 22:
// Make a char array "str" and get all the contents of file 2 in this array and then put it. 
// char str[80];
// while (fgets(str, 79, ft) != NULL)
// {
//     fputs(str, fp);
// }
