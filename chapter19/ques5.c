//updating the costomer bank details
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct customer
{
    int accno;
    char name[30];
    float balance;
};

struct trans
{
    int accno;
    int trans_type; // 0 for deposit and 1 for withdrawl
    float amount;
};

/* for making this code work first uncomment the data entring loop and comment the reading loop then entre the data.
    After entring the data comment the first loop and uncomment the second one */

int main()
{
    struct customer s; //for first loop to run remove the s and ss from this line and add it again for second loop
    struct trans ss;
    FILE *fs, *ft;
    int slen = sizeof(struct customer);

    /* for entring the data */

    // struct customer s[3];
    // struct trans ss[5];
    // ft = fopen("customerques5.dat", "wb");
    // if (ft == NULL)
    // {
    //     printf("Cannot open the customer file\n");
    //     exit(1);
    // }
    // printf("Entre the customer data\n\n");
    // for (int i = 0; i < 3; i++)
    // {
    //     fflush(stdin);
    //     printf("Entre the account number:\n");
    //     scanf("%d", &s[i].accno);
    //     fflush(stdin);
    //     printf("Entre the name of customer:\n");
    //     scanf("%s", s[i].name);
    //     fflush(stdin);
    //     printf("Entre the balance:\n");
    //     scanf("%f", &s[i].balance);
    //     fflush(stdin);
    // }
    // fwrite(&s, sizeof(s), 1, ft);
    // fclose(ft);

    // printf("\n");
    // printf("Entre the transaction data\n\n");

    // fs = fopen("transactionques5.dat", "wb");
    // if (ft == NULL)
    // {
    //     printf("Cannot open the customer transaction file\n");
    //     fclose(ft);
    //     exit(2);
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("Entre the account number:\n");
    //     scanf("%d", &ss[i].accno);
    //     fflush(stdin);
    //     printf("Entre the transaction type:\n");
    //     scanf("%d", &ss[i].trans_type);
    //     fflush(stdin);
    //     printf("Entre the amount:\n");
    //     scanf("%f", &ss[i].amount);
    //     fflush(stdin);
    // }
    // fwrite(&ss, sizeof(ss), 1, fs);
    // fclose(fs);

    /* for reading the trandection data and updating the customer data */

    fs = fopen("transactionques5.dat", "rb");
    if (ft == NULL)
    {
        printf("Cannot open the customer transaction file\n");
        exit(1);
    }
    ft = fopen("customerques5.dat", "rb+");
    if (ft == NULL)
    {
        printf("Cannot open the customer file\n");
        fclose(fs);
        exit(1);
    }
    while (fread(&ss, sizeof(ss), 1, fs) == 1)
    {
        fseek(ft, 0, SEEK_SET);
        while (fread(&s, slen, 1, ft) == 1)
        {
            if (s.accno == ss.accno)
            {
                if (ss.trans_type == 0)
                    s.balance += ss.amount;
                else
                {
                    if ((ss.trans_type == 1) && (s.balance - ss.amount > 100))
                        s.balance -= ss.amount;
                    else
                        s.balance = 100;
                }
            }
            fseek(ft, -slen, SEEK_CUR);
            fwrite(&s, slen, 1, ft);
            //break;
        }
    }
    fclose(fs);
    fclose(ft);
    printf("\nCustomer data updated\n");

    // displaying the new customer data 

    ft = fopen("customerques5.dat", "rb");
    int n = 0;
    struct customer cust[5];
    while (fread(&s, sizeof(s), 1, ft) == 1)
    {
        cust[n] = s;
        n++;
    }
    fclose(ft);
    for (int i = 0; i < n; i++)
    {
        printf("Name: %s balance: %f\n", cust[i].name, cust[i].balance);
    }
    return 0;
}
