// find if the collage won the trophy or not
#include <stdio.h>
#define _BV(x) (1 << x)

void showbits(signed char);

int main()
{
    int games, andmask, count = 0;
    printf("Entre the number:\n");
    scanf("%d", &games);
    showbits(games);
    for (int i = 8; i >= 0; i--)
    {
        andmask = _BV(i);
        if ((games & andmask) == andmask)
        {
            count++;
        }
    }
    printf("Matches won by the collage are = %d\n", count);
    if (count >= 5)
    {
        printf("Collage won the Championship\n");
        if ((games & _BV(7)) == _BV(7))
        {
            printf("Chess won!\n");
        }
        if ((games & _BV(6)) == _BV(6))
        {
            printf("Carom won!\n");
        }
        if ((games & _BV(5)) == _BV(5))
        {
            printf("Table Tannis won!\n");
        }
        if ((games & _BV(4)) == _BV(4))
        {
            printf("Lawn Tennis won!\n");
        }
        if ((games & _BV(3)) == _BV(3))
        {
            printf("Hockey won!\n");
        }
        if ((games & _BV(2)) == _BV(2))
        {
            printf("Football won!\n");
        }
        if ((games & _BV(1)) == _BV(1))
        {
            printf("Basketball won!\n");
        }
        if ((games & _BV(0)) == _BV(0))
        {
            printf("Cricket won!\n");
        }
    }
    return 0;
}

void showbits(signed char n)
{
    int i;
    unsigned char k, j;
    for (i = 8; i >= 0; i--)
    {
        j = i;
        k = n & _BV(j);
        k == 0 ? printf("0") : printf("1");
    }
    printf("\n");
}