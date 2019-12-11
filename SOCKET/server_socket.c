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

int main(int argc ,int *argv[])
{
	int sockfd,newsockfd,portno,clilen,n;
	char buff[1024];
	char info[2000];
	pid_t childpid;
	
	struct sockaddr_in serv_addr,cli_addr;

	struct sockaddr_in
	{
		short int sin_family;
		u_short sin_port;
		struct in_addr sin_addr;

	};
	if (argc < 2) 
	{
		printf("ERROR, no port provided\n");
		exit(1);
	}

	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		perror("error opening socket");
	}
	else
	{
		printf("Socket succesfully connected\n");
	}

	memset(&serv_addr,'\0',sizeof(serv_addr));
	portno=atoi(argv[1]);
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(portno);
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	


	if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
	{
		perror("error in binding\n");
	}
	else
	{
		printf("binded succesfully to port  %d\n",3000);
	}

	if(listen(sockfd,10)==0)
	{
		printf("Listening Successfully\n");
	}
	else
	{
		perror("Listening failed\n");
	}

	while(1)
	{

		clilen=sizeof(cli_addr);
		newsockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&clilen);
		if(newsockfd==-1)
		{
			perror("error in accept\n");
			continue;
		}
		else
		{
			printf("connection accepted succesfully from %s: %d\n",inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
		}

		if((childpid = fork()) == 0)
		{

			close(sockfd);
			while(1)
			{
				n=read(newsockfd,buff,1024);
				if(n<0)
				{
					perror("error in reading\n");
				}
				else
				{
					printf("read succesfully\n");
					printf("client:%s",buff);
				}
				if(strcmp(buff,"exit")==0)
				{
					memset(buff,'\0',1024);
					close(newsockfd);
					printf("\nDisconnected from %s: %d\n",inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
					exit(1);
				}
				else
				{
					printf("\nEnter msg\t:-",info);	
					gets(info);
					n=write(newsockfd,info,strlen(info));
				}
				memset(buff,'\0',1024);
			}
		}
	}
	return 0;
}




