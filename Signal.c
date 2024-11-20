//	SIGCONT: to continue executing, if stopped.
//	SIGHUP:	 to hangup.
//	SIGPIPE: to write on a pipe with no one to read it.
//	SIGSTOP: to stop execution (cannot be caught or ignored).
//	SIGTERM: to terminate.
//	SIGUSR1: User-defined signal 1.
//	SIGUSR2: User-defined signal 2.	


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signalNo){
	printf("Received Signal No: %d\n", signalNo);	
}


int main(){
	int i;
	pid_t pid;

	pid = getpid();

	signal(SIGSTOP, signal_handler);
	

	for (i = 1; i < 100000000; i++)
		printf("%d. PID: %d\n", i, pid);

	return 0;
}
