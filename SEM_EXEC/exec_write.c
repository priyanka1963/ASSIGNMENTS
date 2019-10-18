/* Writing data in  one process*/

#include<string.h>
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
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

	printf("Write Data : "); 
	fgets(str,100,stdin);

	printf("Data written in memory: %s\n",str); 
	
	 
	shmdt(str); 
	clock_t stopTime = clock();
	float secsElapsed1 = (float)(stopTime  - startTime)/CLOCKS_PER_SEC;
	printf("Time taken by write process is %lfsec",secsElapsed1);
	return 0; 
} 

