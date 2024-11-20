#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/stat.h>
#include<stdlib.h>

int main(){

    int res,n;
    char buf[100];

    res = open("fifo1",O_RDONLY);
    n = read(res,buf,sizeof(buf));
    buf[n]='\0';

    write(1,buf,strlen(buf));//write to monitor

    return 0;
}