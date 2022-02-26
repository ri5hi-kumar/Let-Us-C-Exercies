//to delete all occurances of 'the' in the sentence
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[80], str1[80];
    char *s, *p, *q;
    int i;
    printf("\nEntre the value of string:\n");
    fgets(str, sizeof(str), stdin);
    s = str;
    p = str1;
    while (*s)
    {
        q = s;
        if (*s == 't' || *s == 'T')
        {
            s++;
            if (*s == 'h')
            {
                s++;
                if (*s == 'e')
                ;
                else
                {
                    for (i = 0; i <= 2; i++)
                    {
                        *p++ = *q++;
                    }
                }
            }
            else
            {
                *p++ = *q++;
                s--;
            }
        }
        else
        {
            *p++ = *s;
        }
        s++;
    }
    *p = '\0';
    printf("The new string is:\n");
    puts(str1);
    return 0;
}