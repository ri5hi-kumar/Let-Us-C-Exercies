//convert number to words
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void convert(long int, char[]);
char *one[] = {" ", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven",
               "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *ten[] = {" ", " ", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main()
{
    long int num;
    printf("Entre the numbere:\n");
    scanf("%ld", &num);
    if (num <= 0)
    {
        printf("please no negative numbers\n");
    }
    else
    {
        convert((num / 10000000), "crore");
        convert((num / 100000) % 100, "lakh");
        convert((num / 1000) % 100, "thousand");
        convert((num / 100) % 10, "hundred");
        convert((num / 100), " ");
    }
}

void convert(long n, char *s)
{
    if (n > 19)
    {
        printf("%s %s ", ten[n / 10], one[n % 10]);
    }
    else
    {
        printf("%s ", one[n]);
    }
    if (n)
    {
        printf("%s", s);
    }
}