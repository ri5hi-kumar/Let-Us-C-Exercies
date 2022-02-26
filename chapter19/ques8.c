// reading a single name from a list of names
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fs;
    char student[10], another = 'y', ch;
    int num, n;
    int dh;
    /* for entring the data */

    fs = fopen("studentques8.txt", "w+");
    if (fs == NULL)
    {
        printf("Cannot open the students file\n");
        exit(1);
    }
    while (another == 'y' || another == 'Y')
    {
        // fflush(stdin);
        printf("Entre the name of the student:\n");
        // fgets(student, 9, stdin);
        scanf("%s", student);
        fputs(student, fs); // wrote data in file
        fputs("\n", fs);
        puts("Do you want to add another name?\n");
        fflush(stdin);
        // while (dh = getchar() != '\n')
        // {
        //     ;
        // }
        
        another = getchar();
    }

    fseek(fs, 0L, SEEK_SET); // FILE pointer reset to the start of file
    puts("Entre any numberfrom the list\n");
    scanf("%d", &num);
    n = num;
    while (fgets(student, 10, fs) != NULL)
    {
        num--; //count downwards to reach the required record
        if (num == 0)
        {
            printf("Name of the student no. %d is %s\n", n, student);
        }
    }
    if (num > 0)
    {
        puts("No such number in the list\n");
    }
    fclose(fs);
    return 0;
}