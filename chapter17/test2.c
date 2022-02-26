//testing nested structures
#include<stdio.h>

int main(){
    struct address
    {
        char phone[15]; char city[25]; int pin;
    };
    struct emp
    {
        char name[10]; struct address a;
    };
    struct emp e = {"rishi", "7143093188", "gajsinghpur", 100000};
    printf("name = %s\tnumber = %s\ncity = %s\tpin = %d\n", e.name, e.a.phone, e.a.city, e.a.pin);
    return 0;
}