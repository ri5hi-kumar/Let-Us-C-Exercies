// acending order of joining date
#include <stdio.h>
#include <stdlib.h>

struct date
{
    int d, m, y;
};
int isgreater(struct date, struct date);
int main()
{
    struct employee
    {
        int empcode[6];
        char empname[10];
        struct date join_date;
        float salary;
    };
    FILE *fs, *ft;

    /* loop for entring the data */
    
    // struct employee e[3];
    // fs = fopen("employeeques6.dat", "wb");
    // if (fs == NULL)
    // {
    //     printf("Cannot make the employee file\n");
    //     exit(1);
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("Entre the employee code:\n");
    //     scanf("%d %d %d %d %d %d", &e[i].empcode[0], &e[i].empcode[1], &e[i].empcode[2], &e[i].empcode[3], &e[i].empcode[4], &e[i].empcode[5]);
    //     fflush(stdin);
    //     printf("Entre the employee name:\n");
    //     scanf("%s", e[i].empname);
    //     fflush(stdin);
    //     printf("Entre the employee joining date(dd-mm-yyyy):\n");
    //     scanf("%d %d %d", &e[i].join_date.d, &e[i].join_date.m, &e[i].join_date.y);
    //     fflush(stdin);
    //     printf("Entre the employee salary:\n");
    //     scanf("%f", &e[i].salary);
    // }
    // fwrite(&e, sizeof(e), 1, fs);
    // fclose(fs);

    /* loop for reading the data and entring it in the target file */

    struct employee emp[3], e, temp;
    int n;
    fs = fopen("employeeques6.dat", "rb");
    if (fs == NULL)
    {
        printf("Cannot open the employee file\n");
        exit(1);
    }
    ft = fopen("arranagedques6.dat", "wb");
    if (ft == NULL)
    {
        printf("Cannot make the arranged employee file\n");
        fclose(fs);
        exit(2);
    }
    n = 0;
    while (fread(&e, sizeof(e), 1, fs) == 1)
    {
        emp[n] = e;
        n++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            if (isgreater(emp[i].join_date, emp[k].join_date))
            {
                temp = emp[i];
                emp[i] = emp[k];
                emp[k] = temp;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        fwrite(&emp[i], sizeof(e), 1, ft);
    }
    fclose(fs);
    fclose(ft);
    printf("Rearrangement successful\n");

    /* displaying the rearranged data */

    for (int i = 0; i < n; i++)
    {
        printf("Name: %s Joining data: %d %d %d\n", emp[i].empname, emp[i].join_date.d, emp[i].join_date.m, emp[i].join_date.y);
    }

    return 0;
}

int isgreater(struct date d1, struct date d2)
{
    if (d1.y > d2.y)
    {
        return (1);
    }
    else
    {
        if (d1.y == d2.y)
        {
            if (d1.m > d2.m)
            {
                return (1);
            }
            else
            {
                if ((d1.m == d2.m) && (d1.d >= d2.d))
                {
                    return (1);
                }
            }
        }
    }
    return 0;
}