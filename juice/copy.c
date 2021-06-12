#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>   
#include <sys/stat.h>   
#include <fcntl.h>
#include <unistd.h>
#define MAX 1
#define MMAX 100 

int main(int argc, char **argv)
{
    char cpyfile[MMAX];
    strcpy(cpyfile, argv[1]);
    int fd = open(cpyfile, O_RDONLY);
    if (fd < 0)
    {
        fprintf(stderr, "failed\n");
    }

    char tarfile[MMAX];
    strcpy(tarfile, argv[2]);
    int fd2 = open(tarfile, O_RDWR|O_CREAT);
    char buffer[MAX];
    for(int i=0;i<MAX;i++)
    {
        buffer[i]='\0';
    }
    int lensize;
    while((lensize=read(fd,buffer,MAX)))
    {
        // printf("%s\n",buffer);
        // puts("*******seperate********");
        write(fd2,buffer,MAX);
    }
    close(fd);
    close(fd2);

    
}
