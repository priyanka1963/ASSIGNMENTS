#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{

int pipefd[2];
int retstatus;
char writem[2][50]={"i am priyanka", "she is girl"};
char readm[50];
int pid;

retstatus=pipe(pipefd);

if(retstatus==-1)
{
printf("Cant create pipe");
return 1;
}
pid=fork();

if(pid==0)
{
read(pipefd[0],readm,sizeof(readm));
printf(" child process - reading message1 from pipe is %s\n",readm);
read(pipefd[0],readm,sizeof(readm));
printf("child process - Reading message 2 from pipe is %s\n",readm);



}
else
{
printf(" parent process - writing message1 in pipe-  %s\n",writem[0]);
write(pipefd[1],writem[0],sizeof(writem[0]));

printf("parent process - writing message 2 in pipe - %s\n",writem[1]);
write(pipefd[1],writem[1],sizeof(writem[0]));

return 0;
}

}

