//first try to make structures
#include <stdio.h>
void linkfloat()
{
    float a = 0, *b;
    b = &a;
    a = *b;
}
int main()
{
    struct books
    {
        char name;
        float price;
        int pages;
    };

    struct books b[3];
    int i, dh;
    printf("entre the parameters of the books:\n");
    for (i = 0; i < 3; i++)
    {
        scanf("%c %f %d", &b[i].name, &b[i].price, &b[i].pages);
        while ((dh = getchar()) != '\n')
        {
            ;
        }
    }

    for (i = 0; i < 3; i++)
    {
        printf("%c %f %d\n", b[i].name, b[i].price, b[i].pages);
    }
    return 0;
}