//to abberivate first and last name of person
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str1[30], str2[30], target[30], lastname[20];
    char *p, *token;
    printf("Entre the name:\n");
    fgets(str1, sizeof(str1), stdin);
    strcpy(str2, str1);
    int count = 0;
    token = strtok(str1, " ");
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, " ");
    }

    int j = 0, i = 0;
    p = strtok(str2, " ");
    while (p != NULL)
    {
        if (i == count - 1)
        {
            strcpy(lastname, p);
            target[j] = '\0';
        }
        else
        {
            target[j] = *p;
            j++;
            target[j] = '.';
            j++;
        }
        i++;
        p = strtok(NULL, " ");
    }
    strcat(target, lastname);
    printf("%s\n", target);
    return 0;
}