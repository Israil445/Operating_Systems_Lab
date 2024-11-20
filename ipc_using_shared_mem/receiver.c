#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main(){
    void *shared_memory;
    char buf[100];
    int shmid;

    shmid = shmget((key_t)1122,1024,0666);//shared memory already created so IPC_CREAT is not used here 
    printf("Id of the shared memory: %d\n",shmid);

    shared_memory = shmat(shmid,NULL,0);//process attach to the shared memory segment
    printf("Process attached at %p\n",shared_memory);

    printf("Data read from shared memory is : %s\n",(char *)shared_memory);


    return 0;
}