/*semaphore using 2 thread to print a thread after 5 sec*/


#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h>

sem_t sem;

void *function();



int main()
{
	sem_init(&sem, 0, 1); 
        pthread_t tid1, tid2;
        int  ret1, ret2;

        if(ret1!=0 && ret2!=0)
        {
                printf("Cant create thread\n");
        }

	
        ret1 = pthread_create(&tid1, NULL, &function, NULL);
	sleep(5);
        ret2 = pthread_create(&tid2, NULL, &function, NULL);
	
        pthread_join( tid1, NULL);
        pthread_join( tid2, NULL);

        printf("tid 1 returns: %d\n",ret1);
        printf("tid 2 returns: %d\n",ret2);
	sem_destroy(&sem); 
        
}

  
 
 
void *function(void * arg)
{
	
         sem_wait(&sem);
	 char character;
        printf(" The alphabets from A TO Z are \n ");
	for(character='A';character<='Z';character++)
        {
			
		printf("In funtion \nthread id = %d\n", pthread_self());
                printf(" %c\n", character);
		sem_post(&sem);

        }
	
	
}

