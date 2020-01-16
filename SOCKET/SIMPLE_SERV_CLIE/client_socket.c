#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<fcntl.h>
#include<pthread.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<netinet/tcp.h>

int main()
{
	int sockfd,connect_ret=0,ret2;
	struct sockaddr_in data;
	char buffer[1024];
	char info[2000];

	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd == -1)
	{
		printf("error to create socket\n");
	}
	memset(&data,'\0',sizeof(data));
	data.sin_family=AF_INET;
	data.sin_port=htons(3000);
	data.sin_addr.s_addr=inet_addr("127.0.0.1");
	
	connect_ret = connect(sockfd,(struct sockaddr *)&data,sizeof(data));
	if(connect_ret == -1)
	{
		printf("failed to connect\n");
	}
	else
	{
		printf("conneced succesfully\n");
	}
	while(1)
	{


		printf("Enter a msg to send server\t:",info);
		gets(info);
		write(sockfd,info,strlen(info));
		printf("data send is:%s\n",info);
		if(strcmp(info,"exit")==0)
		{
			close(sockfd);
			printf("disconnected from server.\n");
			memset(info,'\0',1024);
			exit(1);
		}

		if(read(sockfd,buffer,1024));
		{
			printf("data read from server is:\t %s\n",buffer);
		}
		memset(buffer,'\0',1024);	
	}

	return 0;
}




