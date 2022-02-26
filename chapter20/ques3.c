// using command line arguments for searching for a word in a file and replacing it
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fs, *ft;
int newstr(char *, char *, char *); // function for changing the word

/* for information */
// argv[1] == old word
// argv[2] == new word
// argv[3] == filename

int main(int argc, char *argv[])
{
    char str[80];
    if (argc != 4)
    {
        printf("Improper number of arguments\n");
        exit(1);
    }
    fs = fopen(argv[3], "r");
    if (fs == NULL)
    {
        printf("Cannot opne the source file\n");
        exit(2);
    }
    ft = fopen("temp.txt", "w");
    if (ft == NULL)
    {
        printf("Cannot open the target file\n");
        fclose(fs);
        exit(3);
    }
    while (fgets(str, 79, fs) != NULL)
    {
        newstr(str, argv[1], argv[2]);
    }
    fclose(fs);
    fclose(ft);
    remove(argv[3]);
    rename("temp.txt", argv[3]);
    return 0;
}

int newstr(char *line, char *search, char *replace)
{
    char *p;
    int offset;
    char pre[80], post[80], final[80];
    p = strstr(line, search);
    if (p == NULL)
    {
        return (0);
    }
    offset = p - line;
    strncpy(pre, line, offset);
    pre[offset] = '\0';
    strcpy(post, p + strlen(search));
    strcpy(final, pre);
    strcat(final, replace);
    strcat(final, post);
    fputs(final, ft);
}