#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int shared = 1;

void *fun1(){
    int x  = shared;
    x++;
    sleep(1);//thread1 is preemted by thread2
    shared = x;
}

void *fun2(){
    int y = shared;
    y--;
    sleep(1);//thread2 is preemted by thread1
    shared = y;
}

int main(){

    pthread_t thread1,thread2;

    pthread_create(&thread1,NULL,fun1,NULL); 
    pthread_create(&thread2,NULL,fun2,NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    printf("the final value of the shared: %d\n",shared);

    return 0;
}