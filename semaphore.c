#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int shared = 1;
sem_t s; //semaphore variables

void *fun1(){

    int x;
    sem_wait(&s);//s=1 then execute and set s = 0
    x = shared;//1
    x++;//2
    sleep(1);//thread1 is preemted by thread2
    shared = x;//2
    sem_post(&s);//s++=0++ = 1;now s = 1
}

void *fun2(){
    int y;
    sem_wait(&s);//s=0 wait until s<=0 then go to the thread1
                 //now s=1 executes wait then go to below and set s=0
    y = shared;//2
    y--;//1
    sleep(1);
    shared = y;//1
    sem_post(&s);//now s become 1
}

int main(){

    sem_init(&s,0,1);

    pthread_t thread1,thread2;

    pthread_create(&thread1,NULL,fun1,NULL); 
    pthread_create(&thread2,NULL,fun2,NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    printf("the final value of the shared: %d\n",shared);//1

    return 0;
}