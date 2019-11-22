#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
struct msg
{
	long mtype;
	char mtext[100];
};
void *send_type2(void * msgid)
{
	struct msg message;
	int ret;
	
	int *id = (int *)msgid;
	message.mtype = 2;
	printf("it will send msg until you type bye\n");
	while(1)
	{
		printf("%s type msg:",__func__,message.mtext);
		gets(message.mtext);
		ret = msgsnd(*id,&message,sizeof(message),0);
		if(ret == -1)
		{
			printf("message cannot send\n");
		}
		printf("%s msg send from :%s\n",__func__,message.mtext);
		if(strcmp("bye",message.mtext) == 0)//when user types the "bye" it will send d msg "bye" and come out of loop
                {
                        printf("breaking\n");
                        break;
                }
	}
	
}
void *receive_type1(void *msgid)
{
	struct msg message;
	int ret,count=0;
        int *id=(int *)msgid;
	while(1)
	{
       		ret = msgrcv(*id,&message,sizeof(message),1,0); 
		if(ret == -1)
		{
			printf("message can not received\n");
		}
		if(strcmp("bye",message.mtext)==0)//when is receives "bye" it will stop the receiving process,comes out of loop 
		
		{
			memset(message.mtext,'\0',100);
			printf("breaking\n");
			break;
		}
		printf("%s msg received :%s\n",__func__,message.mtext);
		memset(message.mtext,'\0',100);
		
	}
}
	 


int main()
{
	pthread_t id[2];
        int ret,ret1,msgid;
	key_t key;
	key = ftok("filr",65);
	msgid = msgget(key,0666|IPC_CREAT);
	if(msgid == -1)
	{
		printf("message queue is not created\n");
		exit(0);
	}
        ret = pthread_create(&id[0],NULL,&send_type2,(void *)&msgid); //sending thread
	if(ret != 0)
	{
		printf("thread not created\n");
	}
	ret1= pthread_create(&id[1],NULL,&receive_type1,(void *)&msgid);//receiving thread
        if(ret1 != 0)
	if(ret1 != 0)
	{
		printf("thread1 is not created\n");
	}
	pthread_join(id[0],NULL);
        pthread_join(id[1],NULL);
	return 0;

}

