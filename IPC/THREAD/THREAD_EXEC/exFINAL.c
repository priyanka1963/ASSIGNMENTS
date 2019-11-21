#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>
#include <time.h>
#include <sys/ipc.h>
#include<sys/wait.h> 
#include<unistd.h>
#include<string.h>
int main(int argc ,char *argv[])
{
	long int value;
	value=atoi(argv[1]);
	int d=atoi(argv[2]);
	int n=d;
	pid_t pids[n];
	int ret,p[2],pipeid,ret1;
	ret1=pipe(p);
	if(ret1 == -1)
	{
		printf("failed to open pipe\n");
	}
	for(int i=0; i<d; i++)
	{
		pids[i]=fork();
		if(pids[i]==0)
		{
			char s[20];
			int sum = 0;
			for(int j=i+1;j<=value;) 
			{
				sum += j;
				j += d;
			}
			sprintf(s,"%d",sum);
			write(p[1],s,sizeof(s));
			exit(0);
		}
	}
	long int total_sum = 0;
	
	char r[20];
	for(int i=0; i<n; i++) 	
	{
		read(p[0],r,sizeof(r));
		printf("SUM:%s\n",r);
		total_sum = total_sum + atoi(r);
			
	}
	printf("Total sum=%lld",total_sum);
	return 0;
}
