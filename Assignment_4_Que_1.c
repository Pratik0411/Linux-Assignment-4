#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void function(void *thread)
{
	int tid = (int)(thread);
	printf("Thread ID: %u\n\n", tid);
	printf("PID is: %d\n\n", getpid());
}

int main()
{
	pthread_t tid, tid2;
	
	pthread_create(&tid, NULL, function, tid);
	pthread_create(&tid2, NULL, function, tid);
	
	pthread_join(tid, NULL);
	
	printf("Terminating the main thread\n");
	
	pthread_exit(NULL);
	
	pthread_join(tid2, NULL);		//executing pending task
	
	printf("Thread ID: %u\n", tid);
	printf("Thread termination successful\n");
}
