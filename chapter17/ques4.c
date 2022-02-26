//record of cricketers

#include <stdio.h>
#include <stdlib.h>

void fun()
{
    float f, *ff = &f;
}
int sort_fun(const void *, const void *);
void set_cricketer_data();
void display();
void list_average();

struct cricketer
{
    int no_of_matches;
    char name[10];
    int age;
    float average;
};
struct cricketer c[3];

int main()
{
    printf("Entre the detalis of the customers:\n");
    set_cricketer_data();
    printf("\n");
    display();
    printf("\n");
    list_average();
    display();
    return 0;
}

void set_cricketer_data()
{
    int i;
    for (i = 0; i < 3; i++)
    {
        fflush(stdin);
        printf("Entre the name of the player:\n");
        scanf("%s", c[i].name);
        fflush(stdin);
        printf("Entre the number of matches played:\n");
        scanf("%d", &c[i].no_of_matches);
        fflush(stdin);
        printf("Entre the age of player:\n");
        scanf("%d", &c[i].age);
        fflush(stdin);
        printf("Entre the average runs scored:\n");
        scanf("%f", &c[i].average);
    }
}

void display()
{
    for (int i = 0; i < 3; i++)
    {
        printf("%d\t%s\t%d\t%d\t%f\n", i + 1, c[i].name, c[i].age, c[i].no_of_matches, c[i].average);
    }
}

void list_average()
{
    int i, j;
    qsort((struct cricketer *)c, 3, sizeof(c[0]), sort_fun);
}
int sort_fun(const void *f, const void *ff)
{
    return (((struct cricketer *)f)->average - ((struct cricketer *)ff)->average);
}