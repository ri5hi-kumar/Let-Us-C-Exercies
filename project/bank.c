#include <stdio.h>
#include <stdlib.h>
#include "bankfuncs.h"
FILE *fp;

int main()
{
    int choice;
    printf("1. Add customer in the bank\n");
    printf("2. Display all accounts information\n");
    printf("3. Checking your account balance\n");
    while (1)
    {
        printf("\n");
        printf("Entre the choice:\n");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            add_customer();
            break;
        case 2:
            display_all();
            break;
        case 3:
            display_customer_info();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            exit(0);
            break;
        }
    }
    return 0;
}

// adding a customer
void add_customer()
{
    if (count == 3)
    {
        printf("No more space left in the bank\n");
        return;
    }
    fp = fopen("customer.dat", "ab");
    if (fp == NULL)
    {
        printf("Cannot create/append the customer data file\n");
        exit(1);
    }
    fflush(stdin);
    printf("Entre the name of the customer:\n");
    scanf("%s", customer[count].name);
    // fgets(customer[count].name, sizeof(customer[count].name), stdin);
    printf("Entre the age of the customer:\n");
    scanf("%d", &customer[count].age);
    printf("Entre the customer four digit pin\n");
    scanf("%d", &customer[count].pin);
    printf("Entre the starting balaence(not < 100):\n");
    scanf("%d", &customer[count].balance);
    
    //fflush(stdin);
    fwrite(&customer, sizeof(customer), 1, fp);
    count++;
    fclose(fp);
}

// displaying all information of all accounts
void display_all()
{
    int i = 0;
    fp = fopen("customer.dat", "rb");
    if (fp == NULL)
    {
        printf("Cannot open the customer data file\n");
        exit(2);
    }
    while (fread(&customer, sizeof(customer), 1, fp) == 1)
    {
        printf("Name = %5s\n", customer[i].name);
        printf("Age = %5d\n", customer[i].age);
        printf("Current Balance = %5d\n", customer[i].balance);
        printf("\n");
        i++;
    }
    fclose(fp);
}

// display of balence of a customer
void display_customer_info()
{
    int code;
    int n = 0, i = 0;
    struct bank c[3];
    printf("Entre your four digit pin:\n");
    scanf("%d", &code);
    fp = fopen("customer.dat", "rb");
    if (fp == NULL)
    {
        printf("Cannot open the customer data file\n");
        exit(3);
    }
    while (fread(&customer, sizeof(customer), 1, fp) == 1)
    {
        c[n] = customer[i];
        n++;
        i++;
    }
    for (int j = 0; j < n; j++)
    {
        if (c[j].pin == code)
        {
            printf("Name = %5s\n", c[j].name);
            printf("Age = %5d\n", c[j].age);
            printf("Current Balance = %5d\n", c[j].balance);
            return;
        }
        else
        {
            printf("Match not found\n");
            return;
        }
    }
    fclose(fp);
}