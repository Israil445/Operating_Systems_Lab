#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){

    pid_t p = fork();

    if(p<0) {
        printf("Unseccussful creation of process");
        exit(-1);
    }

    else if(p==0){
        //child process
        sleep(2);
        printf("i am child process having pid: %d\n",getpid());
        printf("my parent process pid: %d\n",getppid());

    }

    else {
        //parent process
        printf("i am parent process having pid: %d\n",getpid());
        printf("my child process pid: %d\n",p);
    }
    return 0;
}