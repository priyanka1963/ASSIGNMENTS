#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lib.h"

int main() 	
{
	int choice;
	
	//choice=atoi(argv[1]);
	while(1)
	{
		printf("\n\n--------Menu-----------\n");		
		printf("\n1.stringlength\n");
		printf("2.truncate \n");
		printf("3.occurence \n");
		printf("4.replace\n");
		printf("5.Exit\n");
		printf("-----------------------");

		printf("\nEnter your choice :\n");
		scanf("%d",&choice);

		getchar();

		switch(choice)
		{
			case 1 :stringlength();
				break;	
			case 2 :truncate();
				break;
			case 3 :occurence();
				break;
			case 4 :replace();
				break;
			case 5 :exit(0);
		
				

			default : printf("wrong choice! enter valid choice");
				  break; 	
		}
	}
	return 0;
}

