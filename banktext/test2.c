#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
FILE *fp;

int main()
{
    int choice;
    printf("1. Add customer in the bank\n");
    printf("2. Display all accounts information\n");
    printf("3. Checking your account balance\n");
    printf("4. To Withdraw or Deposit\n");
    printf("5. Exit");
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
            with_dep();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
            exit(0);
            break;
        }
    }
    return 0;
}

// adding a account number
int add_account_no(){
    int acc_no;
    fp = fopen("customer.txt", "a+");
    if (fp == NULL)
    {
        printf("Cannot open the customer file\n");
        exit(0);
    }
    fseek(fp, -(sizeof(customer)), SEEK_END);
    while (fscanf(fp, "%d", &customer[count].account_no) != EOF)
    {
        acc_no = customer[count].account_no;
        return (acc_no + 3);
    }
    fclose(fp);
}

// adding a customer
void add_customer()
{
    if (count == 3)
    {
        printf("No more space left in the bank\n");
        return;
    }
    fp = fopen("customer.txt", "a");
    if (fp == NULL)
    {
        printf("Cannot create/append the customer data file\n");
        exit(1);
    }
    fflush(stdin);
    customer[count].account_no = add_account_no();
    printf("Auto genrated account number is %d\n", customer[count].account_no);
    printf("Entre the name of the customer:\n");
    scanf("%s", customer[count].name);
    // fgets(customer[count].name, sizeof(customer[count].name), stdin);
    printf("Entre the age of the customer:\n");
    scanf("%d", &customer[count].age);
    printf("Entre the customer four digit pin\n");
    scanf("%d", &customer[count].pin);
    printf("Entre the starting balaence(not < 100):\n");
    scanf("%d", &customer[count].balance);
    // customer[count].account_no = add_account_no();
    // printf("Auto genrated account number is %d\n", customer[count].account_no);

    fprintf(fp, "\n%s %d %d %d %d\n", customer[count].name, customer[count].age, customer[count].pin, customer[count].account_no, customer[count].balance);
    count++;

    fclose(fp);
}

// displaying all information of all accounts
void display_all()
{
    int i = 0;
    fp = fopen("customer.txt", "r");
    if (fp == NULL)
    {
        printf("Cannot open the customer data file\n");
        exit(2);
    }
    while (fscanf(fp, "%s %d %d %d %d", customer[i].name, &customer[i].age, &customer[i].pin, &customer[i].account_no, &customer[i].balance) != EOF)
    {
        printf("Account Number = %d\n", customer[i].account_no);
        printf("Name = %5s\n", customer[i].name);
        printf("Age = %5d\n", customer[i].age);
        printf("\n");
        i++;
    }
    fclose(fp);
}

// display of balence of a customer
void display_customer_info()
{
    int code, temp_acc;
    int i = 0;
    printf("Entre your four digit pin:\n");
    scanf("%d", &code);
    printf("Entre your six digit account number:\n");
    scanf("%d", &temp_acc);
    fp = fopen("customer.txt", "r");
    if (fp == NULL)
    {
        printf("Cannot open the customer data file\n");
        exit(3);
    }
    while (fscanf(fp, "%s %d %d %d %d", customer[i].name, &customer[i].age, &customer[i].pin, &customer[i].account_no, &customer[i].balance) != EOF)
    {
        printf("\n");
        if ((customer[i].account_no == temp_acc) && (customer[i].pin == code))
        {
            printf("Name = %s\n", customer[i].name);
            printf("Current Balance = %d\n", customer[i].balance);
        }
        i++;
    }
    fclose(fp);
}

// for withdrawing and depositing ammount
void with_dep()
{
    short int option;
    int ammount;
    int code, temp_acc;
    int i = 0;
    printf("Entre your four digit pin:\n");
    scanf("%d", &code);
    printf("Entre your six digit account number:\n");
    scanf("%d", &temp_acc);
    printf("Entre 1 for withdraw and 0 for deposit\n");
    scanf("%hi", &option);
    printf("Entre the ammount:\n");
    scanf("%d", &ammount);
    fp = fopen("customer.txt", "r+");
    if (fp == NULL)
    {
        printf("Cannot open the customer data file\n");
        exit(4);
    }
    while (fscanf(fp, "%s %d %d %d %d", customer[i].name, &customer[i].age, &customer[i].pin, &customer[i].account_no, &customer[i].balance) != EOF)
    {
        if ((customer[i].account_no == temp_acc) && (customer[i].pin == code))
        {
            if (option == 0)
            {
                customer[i].balance += ammount;
                printf("Current Balance = %d\n", customer[i].balance);
            }
            else
            {
                if ((option == 1) && (customer[i].balance - ammount > 100))
                {
                    customer[i].balance = customer[i].balance - ammount;
                    printf("Current Balance = %d\n", customer[i].balance);
                }
                else
                {
                    printf("Balance to low\n");
                    return;
                }
            }
            fseek(fp, -sizeof(customer[i].balance), SEEK_CUR);
            fprintf(fp, "%d\n", customer[i].balance);
        }
        else
        {
            i++;
        }
    }
    fclose(fp);
}