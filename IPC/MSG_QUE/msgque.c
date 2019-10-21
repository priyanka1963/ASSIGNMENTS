// send and receive msg using message queue 
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <unistd.h>


struct msg_buffer { 
	long msg_type; 
	char msg_txt[100]; 
} message; 

int main() 
{ 
	key_t key; 
	int msgid; 

	
	key = ftok("prog", 65); 

	
	msgid = msgget(key, 0666 | IPC_CREAT); 
	message.msg_type = 1; 

	printf("Write Data : "); 
	gets(message.msg_txt); 

	
	msgsnd(msgid, &message, sizeof(message), 0); 

	
	printf("Data send is : %s \n", message.msg_txt); 

	return 0; 
} 

