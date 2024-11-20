#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int shared = 5;

int main(){
    
    pid_t p = fork();

   if(p==0) {
        //child process
        int x = shared;
        x++;
        sleep(1);
        shared = x;
    }

    else {
        //parent process (p>0)
        int y = shared;
        y--;
        sleep(1);
        shared = y;
    }

printf("shared: %d\n",shared);



    return 0 ;
}