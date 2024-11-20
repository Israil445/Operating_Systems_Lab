#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

    int res,n;
    char buf[50];

    res = open("fifo1",O_RDONLY);
    n = read(res,buf,50);

    printf("reader process having pid: %d\n",getpid());
    printf("receiver receive data: %s\n",buf);

    return 0;
}