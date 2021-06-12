#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 4096

char *mstrrev(char *str)
{
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

int main(int argc, char **argv)
{
    char fn[MAX];
    char tmp[MAX];
    strcpy(fn, argv[1]);
    FILE *fp = fopen(fn, "r"); //read
    char revs[MAX][1024];
    int idx = 0;
    while (fgets(tmp, 1024, fp))
    {

        mstrrev(tmp);
        strcpy(revs[idx], tmp);
        idx++;
    }
    fclose(fp);
    fp = fopen(fn, "w");
    for (int i = idx - 1; 0 <= i; i--)
    {

        fprintf(fp, "%s", revs[i]);
    }
    fclose(fp);

    //remove("tempFile.txt");
}
