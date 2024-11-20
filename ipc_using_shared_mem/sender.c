#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main(){
    void *shared_memory;
    char buf[100];
    int shmid;

    shmid = shmget((key_t)1122,1024,0666|IPC_CREAT);//creates shared memory segment with key 112 and size 1024 byte and permision
    printf("Id of the shared memory: %d\n",shmid);

    shared_memory = shmat(shmid,NULL,0);//process attach to the shared memory segment
    printf("Process attached at %p\n",shared_memory);//this print the address where the segment is attachedd

    printf("Enter some data to write to shared memory\n");
    read(0,buf,100);//get some input from user

    strcpy(shared_memory,buf);// data writen to the shared memory
    printf("you worte : %s\n",(char *)shared_memory);


    return 0;
}