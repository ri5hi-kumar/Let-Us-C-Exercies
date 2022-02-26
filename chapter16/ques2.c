//to remove vowels from a string
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[80], str1[80];
    char *s, *p;
    printf("Entre the string:\n");
    fgets(str, sizeof(str), stdin);
    //strlwr(str);
    s = str;
    p = str1;
    while (*s)
    {
        if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u')
        {
            s++;
        }
        else
        {
            *p++ = *s++;
        }
    }
    *p = '\0';
    printf("The new string is:\n");
    //printf("%s", str1);
    puts(str1);
    return 0;
}