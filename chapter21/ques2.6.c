// to exchange the contents of two nibbles
#include <stdio.h>
#define _BV(x) (1 << x)

void showbits(unsigned char);

int main()
{
    unsigned short int num;             // 2 byte variable
    unsigned char a, leftnibble, rightnibble, newnum;   // 1 byte = 8 bits variable
    printf("Entre the number:\n");
    scanf("%hu", &num);
    num = num & 0x00FF;                 // changing the 2 byte to 1 byte by turning the first 8 bits OFF 
    a = num;                            // storing it in a 1 byte variable
    showbits(num);
    printf("\n");
    leftnibble = (a & 0xF0) >> 4;       // turning OFF the last 4 bits and shifting first 8 to the right
    rightnibble = a & 0x0F;             // turning OFF the first 4 bits and only last 8 bits remain
    newnum = (rightnibble << 4) | leftnibble;   // shifting the last remaining 4 bits to the left and turning ON the right bits by leftnibble
    showbits(newnum);
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