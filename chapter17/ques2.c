//making a bank

#include <stdio.h>
#include <stdlib.h>

struct customers
{
    int acc_number;
    char name[10];
    int balence;
    int code;
};

struct customers s[3];
void set_customer_data();
void below_hun();
void withdrawal();
void deposit();

int main()
{
    int i, choice;
    printf("Entre the detalis of the customers:\n");
    set_customer_data();
    printf("\n");
    below_hun();
    printf("Entre 1 for deposit and 0 for withdrawal:\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        deposit();
        break;

    case 0:
        withdrawal();
        break;

    default:
        printf("Not a valid character entred\n");
        break;
    }

    return 0;
}

void set_customer_data()
{
    int i;
    for (i = 0; i < 3; i++)
    {
        fflush(stdin);
        printf("Entre the name of the customer:\n");
        scanf("%s", s[i].name);
        fflush(stdin);
        printf("Entre the account number of the customer:\n");
        scanf("%d", &s[i].acc_number);
        fflush(stdin);
        printf("Entre the balence in the account of customer:\n");
        scanf("%d", &s[i].balence);
        fflush(stdin);
        printf("Entre the code for the account:\n");
        scanf("%d", &s[i].code);
    }
}

void below_hun()
{
    int bal;
    printf("Entre the ammount below which you want to get the details\n");
    scanf("%d", &bal);
    for (int i = 0; i < 3; i++)
    {
        if (s[i].balence < bal)
        {
            printf("Account number = %d\n", s[i].acc_number);
            printf("Name = %s\n", s[i].name);
        }
        printf("\n");
    }
}

void deposit()
{
    int amount, acc_no, pin, j = 0;
    printf("Entre the amount to be deposited:\n");
    scanf("%d", &amount);
    printf("Entre the account number:\n");
    scanf("%d", &acc_no);
    printf("Entre the pin:\n");
    scanf("%d", &pin);
    for (int i = 0; i < 3; i++)
    {
        if (s[i].acc_number == acc_no && s[i].code == pin)
        {
            j = 1;
            s[i].balence = s[i].balence + amount;
            printf("The new balence of %s is %d\n", s[i].name, s[i].balence);
        }
        if (j = 0)
            printf("Wrong account number or pin\n");
    }
}

void withdrawal()
{
    int amount, acc_no, pin, j = 0;
    printf("Enter the amount to be withdrawn:\n");
    scanf("%d", &amount);
    printf("Entre the account number:\n");
    scanf("%d", &acc_no);
    printf("Entre the pin:\n");
    scanf("%d", &pin);
    for (int i = 0; i < 3; i++)
    {
        if (s[i].acc_number == acc_no && s[i].code == pin)
        {
            j = 1;
            if (s[i].balence < amount || s[i].balence < 100)
            {
                printf("The balence is insufficient for the specified withdrawal\n");
            }
            else
            {
                s[i].balence = s[i].balence - amount;
                printf("The new balence of %s is %d\n", s[i].name, s[i].balence);
            }
        }
        if (j = 0)
            printf("Wrong account number or pin\n");
    }
}
