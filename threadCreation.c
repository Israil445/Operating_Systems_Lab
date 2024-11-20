#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *fnc(){
    printf("Inside thread\n");
    for (int i=1;i<=5;i++){
        printf("%d\n",i);
        sleep(1);
    }

}

int main(){
    pthread_t a_thread;//thread declaration
    pthread_create(&a_thread, NULL, fnc , NULL);
    pthread_join(a_thread,NULL);//process waits for thread to finish

    printf("Inside main program\n");
    for(int j = 20;j<=25;j++){
        printf("%d\n",j);
        sleep(1);
    }
} 