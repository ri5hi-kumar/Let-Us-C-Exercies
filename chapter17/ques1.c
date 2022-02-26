//making a list of students and their data

#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll;
    char name[10];
    char department[10];
    char course[10];
    int year;
};

struct student s[3];
void set_student_data();
void display();
void name_acc_roll(int);
void name_acc_year(int);

int main()
{
    int i, y, r;
    printf("Entre the detalis of the students:\n");
    set_student_data();
    printf("These are the students and their details:\n");
    display();
    printf("\n");
    printf("Entre the roll number of the student:\n");
    scanf("%d", &r);
    name_acc_roll(r);
    printf("Entre the year of joining of the student:\n");
    scanf("%d", &y);
    name_acc_year(y);
    return 0;
}

void set_student_data()
{
    int i;
    for (i = 0; i < 3; i++)
    {
        fflush(stdin);
        printf("Entre the name of the student:\n");
        scanf("%s", s[i].name);
        fflush(stdin);
        printf("Entre the roll number of the student:\n");
        scanf("%d", &s[i].roll);
        fflush(stdin);
        printf("Entre the department of the student:\n");
        scanf("%s", s[i].department);
        fflush(stdin);
        printf("Entre the course of the student:\n");
        scanf("%s", s[i].course);
        fflush(stdin);
        printf("Entre the year of joining of the student:\n");
        scanf("%d", &s[i].year);
    }
}

void display()
{
    for (int i = 0; i < 3; i++)
    {
        printf("%s\t%d\t%s\t%s\t%d\n", s[i].name, s[i].roll, s[i].department, s[i].course, s[i].year);
    }
}

void name_acc_roll(int r)
{
    int i, j = 0;
    for (i = 0; i < 3; i++)
    {
        if (s[i].roll == r)
        {
            printf("Name = %s\n", s[i].name);
            printf("Roll number = %d\n", s[i].roll);
            printf("Department = %s\n", s[i].department);
            printf("Course = %s\n", s[i].course);
            printf("Year of joining = %d\n", s[i].year);
            j = 1;
        }
    }
    if (j == 0)
    {
        printf("No such roll number is in the list\n");
    }
}

void name_acc_year(int y){
    int i, j;
    for ( i = 0; i < 3; i++)
    {
        if (y == s[i].year)
        {
            printf("%s joinned in the year %d\n", s[i].name, s[i].year);
            j = 1;
        }
        
    }
    if (j == 0)
    {
        printf("No-one joinned in the year %d", y);
    }
    
}