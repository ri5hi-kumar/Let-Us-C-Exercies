// to exchange the contents of numbers of two bytes
#include <stdio.h>
#define _BV(x) (1 << x)

void showbits(unsigned int);

int main()
{
    unsigned short int num, leftbyte, rightbyte, newnum;
    printf("Entre the number:\n");
    scanf("%hu", &num);
    showbits(num);
    printf("\n");
    leftbyte = (num & 0xFF00) >> 8;         // turning OFF the last 8 bits and shifting first 8 to the right
    rightbyte = (num & 0x00FF);             // turning OFF the first 8 bits and only last 8 bits remain
    newnum = (rightbyte << 8) | leftbyte;   // shifting the last remaining 8 bits to the left and turning ON the right bits by leftbyte
    printf("The new number after exchanging is:\n");
    showbits(newnum);
    printf("\n");
    return 0;
}

void showbits(unsigned int n)
{
    int i;
    unsigned int k, j, andmask;
    for (i = 15; i >= 0; i--)
    {
        j = i;
        andmask = _BV(i);
        k = n & andmask;
        k == 0 ? printf("0") : printf("1");
    }
}