#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

pthread_mutex_t lock= PTHREAD_MUTEX_INITIALIZER;
FILE *fp;
void *Thread1();
void *Thread2();

struct timespec startTime,stopTime;
float secsElapsed1;
float secsElapsed2;

clock_t t1,t2;



int main()
{
	

	clock_t startTime = clock();
	pthread_t tid1, tid2;
	int  ret1, ret2;
	float a;
	if (pthread_mutex_init(&lock, NULL) != 0) 
	{ 
		printf("\n mutex init has failed\n"); 
		return 1; 
	} 

	if(ret1!=0 && ret2!=0)
	{
		printf("Cant create thread\n");
	}
	
	
	ret1 = pthread_create(&tid1, NULL, &Thread1, NULL);
	ret2 = pthread_create(&tid2, NULL, &Thread2, NULL);
	
	pthread_join( tid1, NULL);
	pthread_join( tid2, NULL); 

	printf("tid 1 returns: %d\n",ret1);
	printf("tid 2 returns: %d\n\n",ret2);

	a= (float)(t2-t1)/CLOCKS_PER_SEC;
	printf("switching time between two threads %f",a);
	clock_t stopTime = clock();
	float secsElapsed = (float)(stopTime  - startTime)/CLOCKS_PER_SEC;
	printf("\n\nTime taken by program is %lf\n\n",secsElapsed);
	exit(0);
}

void *Thread1(void* arg)
{	
	
	clock_t startTime = clock();
	printf("starttime=%ld\n",startTime);
	pthread_mutex_lock(&lock);
	fp=fopen("temp.txt","a+");   
	char character;
	printf("The alphabets from A TO Z are\n ");
	for(character='A';character<='Z';character++)
	{

		fprintf(fp," %c", character);
	}
	fclose(fp);
	pthread_mutex_unlock(&lock);
	clock_t stopTime = clock();
	t1 = stopTime=clock();
	printf("stop time=%ld",t1);
	float secsElapsed1 = (float)(stopTime  - startTime)/CLOCKS_PER_SEC;
	printf("\nTime taken by first thread is %lf\n\n",secsElapsed1);
	
}



void *Thread2(void* arg)
{
	sleep(5);
	clock_t startTime = clock();
	t2=startTime=clock();
	printf("starttime=%ld",t2);
	//pthread_mutex_lock(&lock);
	fp=fopen("temp.txt","a+");
	char ch;
	printf("\nThe alphabets from a TO z are\n  ");
	for(ch='a';ch<='z';ch++)
	{

		fprintf(fp," %c ", ch);
	}
	fclose(fp);
	//pthread_mutex_unlock(&lock);
	clock_t stopTime = clock();
	printf("stop time=%ld",stopTime);
	float secsElapsed2 = (float)(stopTime  - startTime)/CLOCKS_PER_SEC;
	printf("\nTime taken by 2nd thread is %lf\n\n",secsElapsed2);
	



}


