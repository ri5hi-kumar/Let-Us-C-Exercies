// checking bits if on or off of a number
#include <stdio.h>
#define _BV(x) (1 << x)

void showbits(unsigned char);

int main()
{
    unsigned char a;
    unsigned short int num;
    printf("Entre a number:\n");
    scanf("%hu", &num);
    num &= 0x00FF;
    a = num;
    showbits(num);
    printf("\n");

    if ((a & _BV(3)) == _BV(3))
    {
        printf("its third bit is on\n");
    }
    else
    {
        printf("its third bit is on\n");
    }

    if ((a & _BV(6)) == _BV(6))
    {
        printf("its sixth bit is on\n");
    }
    else
    {
        printf("its sixth bit is on\n");
    }

    if ((a & _BV(7)) == _BV(7))
    {
        printf("its seventh bit is on\n");
    }
    else
    {
        printf("its seventh bit is on\n");
    }

    return 0;
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
