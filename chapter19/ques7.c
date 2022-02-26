// Reading a file of blood doners and printing it on the console
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct doner
{
    char name[10], address[20];
    int age, blood_ty;
};

int main()
{

    /* for entring th data of the doners */

    // struct doner D[3];
    // FILE *fs;
    // fs = fopen("donersques7.dat", "wb");
    // if (fs == NULL)
    // {
    //     printf("Cannot open the file of doners\n");
    //     exit(1);
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     fflush(stdin);
    //     printf("Entre the name of the doner:\n");
    //     scanf("%s", D[i].name);
    //     fflush(stdin);
    //     printf("Entre the address of the doner:\n");
    //     scanf("%s", D[i].address);
    //     fflush(stdin);
    //     printf("Entre the age of the doner:\n");
    //     scanf("%d", &D[i].age);
    //     fflush(stdin);
    //     printf("Entre the blood type of the doner:\n");
    //     scanf("%d", &D[i].blood_ty);
    //     fflush(stdin);
    // }
    // fwrite(&D, sizeof(D), 1, fs);
    // fclose(fs);

    /* for reading the data and printing it */

    struct doner D;
    FILE *fs;
    fs = fopen("donersques7.dat", "rb");
    if (fs == NULL)
    {
        printf("Cannot open the file\n");
        exit(1);
    }

    while (fread(&D, sizeof(D), 1, fs) == 1)
    {
        if ((D.age < 25) && (D.blood_ty == 2))
        {
            printf("Name: %s Age: %d Address: %s\n", D.name, D.age, D.address);
        }
    }
    fclose(fs);

    /* this is an alternative method for which you have to store the read content in another array first by the
        following code */

    // int n = 0;
    // struct doner don[3];
    // while (fread(&D, sizeof(D), 1, fs) == 1)
    // {
    //     if ((D.age < 25) && (D.blood_ty == 2))
    //     {
    //         don[n] = D;
    //         n++;
    //     }
    // }
    
    // for (int i = 0; i < n; i++)
    // {
    //     printf("Name: %s Age: %d Address: %s\n", don[i].name, don[i].age, don[i].address);
    // }
    return 0;
}