/*  Reading  data from other process( from write pro.)*/

#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <string.h>
#include <unistd.h>
#include <time.h>

struct timespec startTime,stopTime;
float secsElapsed1;
float secsElapsed2;




int main() 
{ 
	clock_t startTime = clock();  
	key_t key = ftok("man",65); 

	
	int shmid = shmget(key,1024,0666|IPC_CREAT); 

	
	char *str = (char*) shmat(shmid,(void*)0,0); 

	printf("Data read from memory: %s\n",str); 
	
	 
	shmdt(str); 
	
	 
	shmctl(shmid,IPC_RMID,NULL); 
	clock_t stopTime = clock();
	float secsElapsed2 = (float)(stopTime  - startTime)/CLOCKS_PER_SEC;
	printf("Time taken by write process is %lfsec",secsElapsed2);
	return 0; 
} 

