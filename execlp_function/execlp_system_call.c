#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
	printf("Fork Failed.\n");
	exit(-1);
    }

    else if (pid == 0) {//child process
    execlp("./child", "", NULL);
    printf("below from this line never execute\n");
    }

    else {//parent process
    wait(NULL);    
	printf("Parent Process.\n");
    }

    exit(0);
}
