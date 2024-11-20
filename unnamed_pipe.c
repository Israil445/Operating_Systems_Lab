#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    int fd[2],n;
    char buf[50];

    pid_t p;
    pipe(fd);//creating an unnamed pipe
    //parent process send data to child porcess

    p = fork();
    if(p>0){//parent process
       
        printf("passing value to child\n");
        write(fd[1],"hello\n",6);
    }

    else if(p==0){
        //child process
        printf("child process received data\n");
        n = read(fd[0],buf,50);
        write(1,buf,n);
    }


    return 0;
}