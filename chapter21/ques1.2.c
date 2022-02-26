// Find the type of the animal
#include<stdio.h>
#define _BV(x) (1<<x)

void showbits(int n);

int main(){
        struct animal
    {
        char name[20];
        int type;
    };
    struct animal a = {"OCELOT", 18};
    int andmask;
    showbits(a.type);
    printf("Animal is a ");
    if ((a.type & _BV(4)) == _BV(4))
    {
        printf("Carnivore and ");
    }
    if ((a.type & _BV(3)) == _BV(3))
    {
        printf("Marsupial\n");
    }
    if ((a.type & _BV(2)) == _BV(2))
    {
        printf("Cetacean\n");
    }
    if ((a.type & _BV(1)) == _BV(1))
    {
        printf("Feline\n");
    }
    if ((a.type & _BV(0)) == _BV(0))
    {
        printf("Canine\n");
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