//creating a small library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_book();
void disp_book();
void disp_book_auth(int aut_ano);
void sortbyano();
int sort_function(const void *f, const void *ff);
void linkfloat();

struct library
{
    int acc_no, flag;
    char title[10], author[10];
    float price;
};
int count;
struct library book[3];

int main()
{
    int choice;
    while (1)
    {
        printf("1. Add book information\n");
        printf("2. Display book information\n");
        printf("3. List all books of a author\n");
        printf("4. List the title of book\n");
        printf("5. List the count of books in library\n");
        printf("6. List the books in order of accession number\n");
        printf("7. Exit\n");
        printf("Entre your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_book();
            break;

        case 2:
            disp_book();
            break;

        case 3:
            disp_book_auth(0);
            break;

        case 4:
            disp_book_auth(1);
            break;

        case 5:
            printf("Total number of books = %d\n", count);
            break;

        case 6:
            sortbyano();
            break;

        case 7:
            exit(0);
            break;
        }
    }
    return 0;
}

void add_book()
{
    if (count == 3)
    {
        printf("No more space\n");
        return;
    }

    printf("Entre the details of the book:\n");
    printf("Name of the book:\n");
    scanf("%s", book[count].title);
    printf("Name of the author:\n");
    scanf("%s", book[count].author);
    printf("Accession number of the book:\n");
    scanf("%d", &book[count].acc_no);
    printf("Price of the book:\n");
    scanf("%f", &book[count].price);
    printf("Issued/Not Issued(0/1):\n");
    scanf("%d", &book[count].flag);
    if ((book[count].flag != 1) && (book[count].flag != 0))
    {
        printf("Improper status\n");
        return;
    }
    count++;
    printf("Book details entred\n");
}

void disp_book()
{
    int i;
    printf("Details of %d books in the library:\n", count);
    for (i = 0; i < count; i++)
    {
        printf("Name of the book: %s\n", book[i].title);
        printf("Name of the author: %s\n", book[i].author);
        printf("Accession number: %d\n", book[i].acc_no);
        printf("Price of the book: %f\n", book[i].price);
        printf("Status of the book: ");
        book[i].flag == 0 ? printf("Issued\n") : printf("Available\n");
        printf("\n");
    }
}

void disp_book_auth(int aut_ano)
{
    char nm[10];
    int accno, i = 0, dec = 0;

    //check if author name is given or accession number is given
    if (aut_ano == 0)
    {
        printf("Entre the name of the author:\n");
        scanf("%s", nm);
        printf("Details of books by author %s in library:\n", nm);
    }
    else
    {
        printf("Entre the accession number:\n");
        scanf("%d", &accno);
        printf("Details of books with accession number %d:\n", accno);
    }
    for (i = 0; i < count; i++)
    {
        if ((strcmp(nm, book[i].author) == 0) && (aut_ano == 0))
        {
            dec++;
        }
        else
        {
            if (aut_ano == 1)
            {
                if (book[i].acc_no == accno)
                {
                    dec++;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                break;
            }
        }
        printf("Name of the book: %s\n", book[i].title);
        printf("Name of the author: %s\n", book[i].author);
        printf("Accession number: %d\n", book[i].acc_no);
        printf("Price of the book: %f\n", book[i].price);
        printf("Status of the book: ");
        book[i].flag == 0 ? printf("Issued\n") : printf("Available\n");
        printf("\n");
    }
    if (dec == 0)
        printf("No such book\n");
}

void sortbyano(){
    qsort((struct library *)book, count, sizeof(book[0]), sort_function);
    printf("After the sorting:\n");
    disp_book();
}
int sort_function(const void *f, const void *ff){
    return(((struct library *)f) -> acc_no - ((struct library *)ff) -> acc_no);
}
void linkfloat(){
    float a=0, *b;
    b = &a;
    a = *b;
}