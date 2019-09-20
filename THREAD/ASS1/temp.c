#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock= PTHREAD_MUTEX_INITIALIZER;
FILE *fp;
void *Thread1();
void *Thread2();


int main()
{
	pthread_t tid1, tid2;
	int  ret1, ret2;

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
	printf("tid 2 returns: %d\n",ret2);
	exit(0);
}

void *Thread1(void* arg)
{
	fp=fopen("temp.txt","a+");   
	pthread_mutex_lock(&lock);
	char character;
	printf("The alphabets from A TO Z are ");
	for(character='A';character<='Z';character++)
	{

		fprintf(fp," %c", character);
	}
	fclose(fp);
	pthread_mutex_unlock(&lock);

}



void *Thread2(void* arg)
{
	fp=fopen("temp.txt","a+");
	pthread_mutex_lock(&lock);
	char ch;
	printf("The alphabets from a TO z are\n  ");
	for(ch='a';ch<='z';ch++)
	{

		fprintf(fp," %c ", ch);
	}
	fclose(fp);
	pthread_mutex_unlock(&lock);
}






