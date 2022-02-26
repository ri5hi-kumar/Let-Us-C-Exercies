//merges line altenatively from two files in the target file
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *f1, *f2, *ft;
    char str1[80], str2[80];
    char *prawl, newl = '\n';
    int flag = 0;
    f1 = fopen("sample.txt", "r");
    if (f1 == NULL)
    {
        printf("Cannot open the sample file\n");
        exit(1);
    }
    f2 = fopen("sample2.txt", "r");
    if (f2 == NULL)
    {
        printf("Cannot open the sample2 file\n");
        fclose(f2);
        exit(2);
    }
    ft = fopen("targetques3.txt", "w+");
    if (ft == NULL)
    {
        printf("Cannot open the target file\n");
        fclose(f1);
        fclose(f2);
        exit(3);
    }

    /* read the source file and copy the lines alternatively
    read till the eof of any one of the files is reached */

    while (fgets(str1, 79, f1) != NULL)
    {
        prawl = strchr(str1, newl);
        fputs(str1, ft);
        if (!prawl)
        {
            fputs("\n", ft);
        }
        if (fgets(str2, 79, f2) != NULL)
        {
            fputs(str2, ft);
            prawl = strchr(str2, newl);
            flag = 1;
            if (!prawl)
            {
                fputs("\n", ft);
            }
        }
        else
        {
            fputs("\n", ft);
        }
    }

    /* copy the contents of the file whose eof is not reached */

    if (flag == 1)
    {
        while (fgets(str2, 79, f2) != NULL)
        {
            prawl = strchr(str1, newl);
            fputs(str2, ft);
            if (!prawl)
            {
                fputs("\n", ft);
            }
        }
    }
    printf("\nCopying complete\n");
    fclose(f1);
    fclose(f2);
    fclose(ft);
    return 0;
}