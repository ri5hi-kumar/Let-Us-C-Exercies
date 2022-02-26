// rewritng the function showbits() in _BV(x)
#include <stdio.h>
#define _BV(x) (1 << x)

void showbits(unsigned char n)
{
    int i;
    unsigned char k, j;
    for (i = 7; i >= 0; i--)
    {
        j = i;
        k = n & _BV(j);
        k == 0 ? printf("0") : printf("1");
    }
    printf("\n");
}


// int main(){
//     // unsigned char a;
//     unsigned char num;
//     printf("Entre a number:\n");
//     scanf("%c", &num);
//     // num &= 0x00FF;
//     // a = num;
//     showbits(num);
//     return 0;
// }