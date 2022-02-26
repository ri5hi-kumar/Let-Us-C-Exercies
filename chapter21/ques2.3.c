// for checking "on" bits
#include <stdio.h>
#define _BV(x) (1 << x)

void showbits(unsigned char);
int checkbits(unsigned int, int, int);

int main()
{
    unsigned int x = 0xF0FF;
    int p, n, flag;
    printf("The value of x = ");
    showbits(x);
    printf("\n");
    printf("Entre the number from:\n");
    scanf("%d", &p);
    printf("Entre the number \"how many\":\n");
    scanf("%d", &n);
    flag = checkbits(x, p, n);
    if (flag == 1)
    {
        printf("%d bits from pos %d are turned on\n", n, p);
    }
    else
    {
        printf("%d bits from pos %d are not turned on\n", n, p);
    }
    return 0;
}

void showbits(unsigned char n)
{
    int i;
    unsigned char k, andmask;
    for (i = 7; i <= 0; i--)
    {
        andmask = _BV(i);
        k = n & andmask;
        k == 0 ? printf("0") : printf("1");
    }
}

int checkbits(unsigned int x, int p, int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        if ((x & _BV(p)) != _BV(p))
        {
            return 0;
        }
        p--;
    }
    return 1;
}