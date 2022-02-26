// displaying the information of the students
#include <stdio.h>
#define _BV(x) (1 << x)

void showbits(int n);

int main()
{
    int data[] = {273, 548, 786, 1096};
    int num, i, roonmum;
    for (i = 0; i < 4; i++)
    {
        num = data[i];
        if ((num & _BV(0)) == _BV(0))
        {
            printf("Year: First\n");
        }
        if ((num & _BV(1)) == _BV(1))
        {
            printf("Year: Second\n");
        }
        if ((num & _BV(2)) == _BV(2))
        {
            printf("Year: Third\n");
        }
        if ((num & _BV(3)) == _BV(3))
        {
            printf("Year: Forth\n");
        }
        if ((num & _BV(4)) == _BV(4))
        {
            printf("Branch: Mechanical\n");
        }
        if ((num & _BV(5)) == _BV(5))
        {
            printf("Branch: Chemical\n");
        }
        if ((num & _BV(6)) == _BV(6))
        {
            printf("Branch: Electornics\n");
        }
        if ((num & _BV(7)) == _BV(7))
        {
            printf("Branch: Civil\n");
        }
        roonmum = num >> 8;
        printf("Room number is = %d\n", roonmum);
    }
    return 0;
}

void showbits(int n)
{
    int i;
    int k, j;
    for (i = 4; i >= 0; i--)
    {
        j = i;
        k = n & _BV(j);
        k == 0 ? printf("0") : printf("1");
    }
    printf("\n");
}