#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

    int res,n;
    res = open("fifo1",O_WRONLY);
    write(res,"Message",7);// write a message to pipe fifo1
    printf("sender process having pid:%d\n",getpid());

    return 0;
}