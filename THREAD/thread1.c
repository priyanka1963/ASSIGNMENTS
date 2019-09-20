#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *Thread1();
void *Thread2();


int main()
{
        pthread_t tid1, tid2;
        int  ret1, ret2;

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
        
        char character;
        printf("The alphabets from A TO Z are \n ");
        for(character='A';character<='Z';character++)
        {

                printf(" %c", character);
        }
}


void *Thread2(void* arg)
{
	
	char ch;
	printf("\nThe alphabets from a TO z are\n  ");
	for(ch='a';ch<='z';ch++)
	{

		printf(" %c ", ch);
	}
	
}
	


                                                                                                                                           

