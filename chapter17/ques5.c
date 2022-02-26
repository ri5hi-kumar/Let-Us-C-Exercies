//making list of tenure employes
#include <stdio.h>
#include <stdlib.h>

struct date
{
    int day, month, year;
};

struct employee
{
    int emp_code;
    char name[10];
    struct date dof;
};

struct employee e[3];
void set_data();
int check_date(struct date *);
void tenure_employees(struct date *);

int main()
{
    struct date present;
    int check;
    printf("Entre the information of the employees:\n");
    set_data();
    printf("Entre today's date:\n");
    scanf("%d %d %d", &present.day, &present.month, &present.year);
    check = check_date(&present);
    if (check == 0)
    {
        printf("\nImproper date entred\n");
        exit (0);
    }
    printf("Employes whose tenure is >= 3 years are:\n");
    tenure_employees(&present);
    return 0;
}

int check_date(struct date *dt)
{
    if ((dt->day > 31 || dt->day < 0) || (dt->month > 12 || dt->month < 0) || (dt->year > 9999 || dt->year < 1000))
    {
        return (0);
    }
    else
    {
        return (1);
    }
}
//better verrsion in next question

void set_data()
{
    for (int i = 0; i < 3; i++)
    {
        printf("Entre the employee code:\n");
        scanf("%d", &e[i].emp_code);
        fflush(stdin);
        printf("Entre the name of the employee:\n");
        scanf("%s", e[i].name);
        fflush(stdin);
        printf("Entre the date of joinning:\n");
        scanf("%d %d %d", &e[i].dof.day, &e[i].dof.month, &e[i].dof.year);
        fflush(stdin);
    }
}

void tenure_employees(struct date *pd)
{
    for (int i = 0; i < 3; i++)
    {
        if (pd->year > e[i].dof.year + 3)
        {
            printf("%s\n", e[i].name);
        }
        else
        {
            if (pd->year == e[i].dof.year + 3)
            {
                if (pd->month > e[i].dof.month)
                {
                    printf("%s\n", e[i].name);
                }
                else
                {
                    if ((pd->month == e[i].dof.month) && (pd->day >= e[i].dof.day))
                    {
                        printf("%s\n", e[i].name);
                    }
                }
            }
        }
    }
}
