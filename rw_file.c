#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){

    int fd,fd1,n;
    char buf[50];

    fd = open("test.txt",O_RDONLY);
    n = read(fd,buf,50);
   
    fd1 = open("target.txt",O_CREAT|O_WRONLY,0642);
    write(fd1,buf,n);

    return 0;
}