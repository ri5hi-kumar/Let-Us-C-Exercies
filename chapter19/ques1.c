//reading student records
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* for making this code work first uncomment the data entring loop and comment the reading loop then entre the data.
    After entring the data comment the first loop and uncomment the second one */


int main()
{
    FILE *fp;
    struct student
    {
        char name[10];
        int age;
    };
    struct student s, stud[10], temp; //for first loop to run remove the s from this line and add it again for second loop
    int n, i, k;

    /* for entring data in the .dat file first run this loop and make a file */

    // struct student s[3]
    // writing the data
    // fp = fopen("studentques1.dat", "wb");
    // for (i = 0; i < 3; i++)
    // {
    //     fflush(stdin);
    //     printf("Entre the name of the student:\n");
    //     scanf("%s", s[i].name);
    //     fflush(stdin);
    //     printf("Entre the age of the student:\n");
    //     scanf("%d", &s[i].age);
    // }
    // fwrite(&s, sizeof(s), 1, fp);
    // fclose(fp);

    /* for reading the file run this loop */

    fp = fopen("studentques1.dat", "rb");
    n = 0;
    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        stud[n] = s;
        n++;
    }

    // for rearranging in alphabatical order

    for (i = 0; i < n - 1; i++)
    {
        for (k = i + 1; k < n; k++)
        {
            if (strcmp(stud[i].name, stud[k].name) > 0)
            {
                temp = stud[i];
                stud[i] = stud[k];
                stud[k] = temp;
            }
        }
    }
    fclose(fp);

    //printing the names on console

    for (i = 0; i < n; i++)
    {
        printf("Name: %s age: %d\n", stud[i].name, stud[i].age);
    }

    return 0;
}