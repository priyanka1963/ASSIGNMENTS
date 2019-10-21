//recieve mesg from another queue
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 


struct mesg_buffer { 
	long msg_type; 
	char msg_txt[100]; 
} message; 

int main() 
{ 
	key_t key; 
	int msgid; 

	
	key = ftok("prog", 65); 

	
	msgid = msgget(key, 0666 | IPC_CREAT); 

	
	msgrcv(msgid, &message, sizeof(message), 1, 0); 

	
	printf("Data Received is : %s \n", message.msg_txt); 

	
	msgctl(msgid, IPC_RMID, NULL); 

	return 0; 
} 

