#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int shared = 1;
pthread_mutex_t l;//mutex lock variable

void *fun1(){

    int x;
    printf("Thread1 trying to acquire lock\n");
    pthread_mutex_lock(&l);//threade one acquires the lock.
                           //now thread2 will not be able to acquire the lock
                           //lock until it is unlock by thrade1
    //critical section
    printf("Thrade1 acquire lock\n");
    x = shared;//1
    printf("Thrade1 reads the value of shared variable as %d\n",x);
    x++;//2
    sleep(1);//thread1 is preemted by thread2
    shared = x;//2
    printf("value of shard variable update by Thrade1 is:%d\n",shared);
    pthread_mutex_unlock(&l);
    printf("Thrade1 releaed the lock\n");
}

void *fun2(){
   int y;
    printf("Thread2 trying to acquire lock\n");
    pthread_mutex_lock(&l);//threade one acquires the lock.
                           //now thread2 will not be able to acquire the lock
                           //lock until it is unlock by thrade1
    //critical section
    printf("Thrade2 acqire lock\n");
    y = shared;//2
    printf("Thrade2 reads the value of shared variable as %d\n",y);
    y--;//1
    sleep(1);//thread1 is preemted by thread2
    shared = y;//1
    printf("value of shard variable update by Thrade2 is:%d\n",shared);
    pthread_mutex_unlock(&l);
    printf("Thrade2 releaed the lock\n");
}

int main(){

    pthread_mutex_init(&l,NULL);//initializing mutex locks

    pthread_t thread1,thread2;

    pthread_create(&thread1,NULL,fun1,NULL); 
    pthread_create(&thread2,NULL,fun2,NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    printf("the final value of the shared: %d\n",shared);//1

    return 0;
}