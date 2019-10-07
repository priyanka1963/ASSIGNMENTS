/* Writing data in  one process*/

#include<string.h>
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
 

int main() 
{ 
	
	 
	key_t key = ftok("man",65); 

	
	int shmid = shmget(key,1024,0666|IPC_CREAT); 
	 
	 
	 char *str = (char*) shmat(shmid,(void*)0,0); 

	printf("Write Data : "); 
	fgets(str,100,stdin);

	printf("Data written in memory: %s\n",str); 
	
	 
	shmdt(str); 

	return 0; 
} 

