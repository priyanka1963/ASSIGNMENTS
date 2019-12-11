#include<stdio.h>
#include<stdlib.h>
#include "ring.h"
#define MAXSIZE 10

int array[20];
int location,start,SIZE,value,new_value,del_value=0,rot_time,Rsize;

int main(int argc,char *argv[])
{
	 
	
        int choice;
	if(argc >= 2)
	{
	SIZE=atoi(argv[1]);
	while(1)
	{

                printf("\n\n--------Menu-----------\n");
                printf("1.Create\n");
                printf("2.Add\n");
                printf("3.Delete\n");
                printf("4.Rotate\n");
                printf("5.Display\n");
                printf("6.Clear\n");
		printf("7.Exit\n");
		printf("-----------------------");

                printf("\nEnter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:         Create();
                                        break;
                        case 2:
                                        Add();
                                        break;
                        case 3:
                                        Delete();
                                        break;

                        case 4:
                                        Rotate();
                                        break;
                        case 5:
                                        Display();
                                        break;
                        case 6:
                                       Clear();
                                        break;
			case 7:
					exit(0);
                   
                        default:
                                       printf("\nInvalid choice:\n");
                                        break;
                }
	    }
   
         }
	else
	{
	printf("Please enter valid arguments\n");
	}
       
	return 0;
	}
