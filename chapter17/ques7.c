//comparing two dates
#include <stdio.h>
#include <stdlib.h>

struct date
{
    int day, month, year;
};

int check_date(struct date *);
int compare_dates(struct date *, struct date *);

int main()
{
    int check, value;
    struct date dt1, dt2;
    printf("Entre the first date:\n");
    check = check_date(&dt1);
    if (check == 0)
    {
        printf("\nImproper date entred\n");
        exit(0);
    }
    fflush(stdin);
    printf("Enter the second date:\n");
    check = check_date(&dt2);
    if (check == 0)
    {
        printf("\nImproper date entred\n");
        exit(0);
    }
    fflush(stdin);
    value = compare_dates(&dt1, &dt2);
    printf("\n%d\n", value);
    return 0;
}

int check_date(struct date *dt)
{
    printf("Entre date(dd):\n");
    scanf("%d", &dt->day);
    printf("Entre the month(mm):\n");
    scanf("%d", &dt->month);
    printf("Entre the year(yyyy):\n");
    scanf("%d", &dt->year);
    if ((dt->day > 31 || dt->day < 0) || (dt->month > 12 || dt->month < 0) || (dt->year > 9999 || dt->year < 1000))
    {
        return (0);
    }
    else
    {
        return (1);
    }
}

int compare_dates(struct date *dt1, struct date *dt2)
{
    if ((dt1->day == dt2->day) && (dt1->month == dt2->month) && (dt1->year == dt2->year))
    {
        return (0);
    }
    else
    {
        return (1);
    }
}