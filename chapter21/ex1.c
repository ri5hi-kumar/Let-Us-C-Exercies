// to find the color
#include <stdio.h>
#define _BV(x) (1 << x)
void showbits(unsigned char);

int main()
{
    unsigned char color, i;
    int c;
    char *rbcolors[] = {"Violet", "Indigo", "Blue", "Green", "Yellow", "Orange", "Red"};
    printf("Entre any number:\n");
    scanf("%d", &c);
    color = (unsigned char)c;
    showbits(color);
    printf("\n");
    printf("Color represented are:\n");
    for (i = 0; i <= 6; i++)
    {
        if ((color & _BV(i)) == _BV(i))
        {
            printf("%s\n", rbcolors[i]);
        }
    }
}

void showbits(unsigned char n)
{
    int i;
    unsigned char k, andmask;
    for (i = 7; i >= 0; i--)
    {
        andmask = _BV(i);
        k = n & andmask;
        k == 0 ? printf("0") : printf("1");
    }
}