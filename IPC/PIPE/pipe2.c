#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{

int pipefd1[2],pipefd[2];
int retstatus1,retstatus2;
char pipe1writem[50]={"i am priyanka"}; 
char pipe2writem[50]= {"she is girl"};
char readm[50];
int pid;

retstatus1=pipe(pipefd1);

if(retstatus1==-1)
{
printf("Cant create pipe");
return 1;
}
retstatus2=pipe(pipefd1);

if(retstatus2==-1)
{
printf("Cant create pipe");
return 1;
}
pid=fork();

if(pid!=0)
{
close(pipefd1[0]);
close(pipefd2[1]);

printf(" parent process - writing message1 in pipe-  %s\n",pipe1writem[0]);
write(pipefd[1],pipe1writem[0],sizeof(pipe1writem[0]));

read(pipefd[0],readm,sizeof(readm));
printf(" child process - reading message1 from pipe - %s\n",readm);
}
else
{
close(pipefd1[1]);
close(pipefd2[0]);

printf("parent process - writing message 2 in pipe - %s\n",pipe1writem[1]);
write(pipefd[1],pipe1writem[1],sizeof(pipe1writem[0]));

read(pipefd[0],readm,sizeof(readm));
printf("child process - Reading message 2 from pipe - %s\n",readm);

}
return 0;
}



