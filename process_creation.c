#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main(){
    
    pid_t p = fork();
    printf("%d\n",p);
    if(p<0){
        printf("unseccessfull creation of process");
        exit(-1);
    }

    else if(p==0) {
        //child process
        printf("i am child process having pid: %d\n",getpid());
        printf("my parent pid: %d\n",getppid());
    }

    else {
        //parent process (p>0)
        printf("i am parent process : %d\n",getpid());
        printf("my child pid: %d\n",p);
    }



    return 0 ;
}