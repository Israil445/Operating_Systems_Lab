#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/stat.h>
#include<stdlib.h>

int main(){

    int res,n;
    char msg[]="insert a message: ";
    char buf[100];

    write(1,msg,strlen(msg));//write a msg to monitor
    n = read(0,buf,strlen(msg));//read data from keyboard
    buf[n]='\0';

    int fd = open("fifo1",O_WRONLY);
    write(fd,buf,strlen(buf));



    return 0;
}