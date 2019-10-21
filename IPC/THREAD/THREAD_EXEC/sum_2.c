#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include <time.h>

long int value;
int n,j=1;

struct timespec startTime,stopTime,startTime1,stopTime1 ;
float secsElapsed,secsElapsed1;
long long int sum=0;

void *function(void *arg)

{
clock_t startTime = clock();
static int i=1;
int rem;

int limit=(value/n)*i;
rem = value % n ;
if(rem!=0)
{
limit=limit+rem;
}
for(j; j<=limit; j++)
{
 if(value>=j)
 {	 
 sum=sum+j;
 //printf("j is:%d",j);
}
}


j=limit+1;
i++;
#if DEBUG
printf("limit is %d ",limit);
printf("\nsum=%lld\n", sum);
#endif
clock_t stopTime = clock();
float secsElapsed = (float)(stopTime  - startTime)/CLOCKS_PER_SEC;
#if DEBUG
printf("Time taken by each thread is %lf\n\n",secsElapsed);
#endif


}

int main(int argc ,char *argv[])
{

clock_t startTime1 = clock();
printf("\n\nstart time:%ld\n\n",startTime1);
 value=atoi(argv[1]);
 n=atoi(argv[2]);

int count=0;
pthread_t tid[n];

for(int i=0; i<n; i++)
{
 pthread_create( &tid[i], NULL, &function, NULL);
}
for(int i=0; i<n; i++)
{
 pthread_join(tid[i], NULL);
}
clock_t stopTime1 = clock();
printf("\n\n stopTime1 time:%ld\n\n",stopTime1);
float secsElapsed1 = (float)(stopTime1  - startTime1)/CLOCKS_PER_SEC;
printf("Time taken by main function is %lf\n\n",secsElapsed1);
return 0;
}
