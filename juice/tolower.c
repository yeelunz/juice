#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <sys/types.h>   
#include <sys/stat.h>   
#include <fcntl.h>
#include <unistd.h>
#define MAX 1024
#define BUf 1


void strtolower(char*a)
{
    char*ptr=a;
    while(*ptr)
    {
        if(isupper(*ptr))
        {
            *ptr=tolower(*ptr);
        }
        ptr++;
    }
}


int main(int argc,char**argv)
{

    char fileName[MAX];
    strcpy(fileName,argv[1]);
    char buf[BUf];
    int fd = open(fileName,O_RDWR);
    int fd2 = open(fileName,O_RDWR);
    int size;
    while((size=read(fd,buf,BUf)))
    {
        strtolower(buf);
        write(fd2,buf,BUf);
    }
    close(fd);
    close(fd2);


}