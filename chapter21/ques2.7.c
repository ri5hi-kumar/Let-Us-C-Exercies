// setting its odd bits to 1
#include <stdio.h>
#define _BV(x) (1 << x)

void showbits(unsigned char);

int main()
{
    unsigned short int num; // 2 byte variable
    unsigned char a, k;     // 1 byte = 8 bits variable
    int i;
    printf("Entre the number:\n");
    scanf("%hu", &num);
    num = num & 0x00FF; // changing the 2 byte to 1 byte by turning the first 8 bits OFF
    a = num;            // storing it in a 1 byte variable
    showbits(a);
    printf("\n");

    for (i = 7; i >= 0; i = i - 2)
    {
        k = a & _BV(i);
        if (k == 0) // checking if odd bits are OFF     // we cannot put 'i' in if-else statement
        {
            a |= _BV(i); //turning them ON
        }
    }

    /* another ways of doing it */

    // unsigned char b;
    // b = _BV(1) | _BV(3) | _BV(5) | _BV(7);
    // a = a | b;

    // for (i = 7; i >= 0; i = i - 2)
    // {
    //     num |= _BV(i);
    // }
    
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