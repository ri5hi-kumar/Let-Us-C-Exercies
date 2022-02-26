// checking bits if OFF or ON of a number
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
        printf("3rd bit is off.... will put it on ");
        a |= _BV(3);
        showbits(a);
        printf("\n");
    }

    if ((a & _BV(5)) == _BV(5))
    {
        printf("its fifth bit is on\n");
    }
    else
    {
        printf("5th bit is off.... will put it on ");
        a |= _BV(5);
        showbits(a);
        printf("\n");
    }

    printf("The resultant bits:\n");
    showbits(a);
    printf("\n");
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
