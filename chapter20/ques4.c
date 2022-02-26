// command line calculator for only two arguments
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, first, second, result;
    char *str[] = {"+", "-", "/", "*", "%"}; // argv[2]
    if (argc != 4)
    {
        printf("Improper number of argumenets\n");
        exit(1);
    }

    /* checking the operator */

    for (i = 0; i < 5; i++)
    {
        if (strcmp(argv[2], str[i]) == 0)
        {
            break;
        }
        else
        {
            printf("Not a valid operator\n");
            exit(2);
        }
    }
    first = atoi(argv[1]); // atoi() converts string into integer
    second = atoi(argv[3]);
    //char ch = *argv[1];
    printf("\nResut of the operation is:\n");
    switch (i)
    {
    case 0:
        result = first + second;
        printf("%d", result);
        break;

    case 1:
        result = first - second;
        printf("%d", result);
        break;

    case 2:
        result = first / second;
        printf("%d", result);
        break;

    case 3:
        result = first * second;
        printf("%d", result);
        break;

    case 4:
        result = first % second;
        printf("%d", result);
        break;
    }

    return 0;
}