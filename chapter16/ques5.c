//check two vowels in succession
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str1[70];
    char *s;
    int count = 0;
    printf("Entre the string:\n");
    fgets(str1, sizeof(str1), stdin);
    s = str1;
    while (*s)
    {
        if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u')
        {
            s++;
            if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u')
            {
                count++;
            }
            continue;
        }
        s++;
    }
    printf("NO. of occurences: %d\n", count);
    return 0;
}