#include<stdio.h>
#include "ring.h"
int array[20];
int location,start,SIZE,value,new_value,rot_time,Rsize;


void Create() //creating an array
{
        printf("Enter a  specific location to insert elements: \n");
	scanf("%d",&location);
        printf("\nEnter the value to insert:\n");
	scanf("%d",&value);
	for(start=0;start<SIZE;start++)
	{
		array[start]=0;
	if(array[location-1] == 0 )
		{
			
			array[location-1]=value; 
			
		}
	}
}

void Add()   //inserting an element  to an array  
{         
    printf("\nEnter the location to insert new element:\n");         
    scanf("%d",&location);         
    printf("\nEnter the new value to be inserted :\n");         
    scanf("%d",&new_value);         
    for(start=SIZE-1;start>=location-1;start--)
        {
                array[start+1]=array[start];
        }
        array[location-1]=new_value;
        SIZE=SIZE+1;
}//end of insert()


void Delete()      //deleting an array element
{
        printf("\nEnter the location to delete element :\n");
        scanf("%d",&location);
        array[location-1]= 0 ;
       
	
}//end of delete()


void Rotate()   // rotate ring
{
	printf("Enter a ring size: \n");
	scanf("%d",&Rsize);
	while(rot_time<Rsize)
	{
		for(start=0;start<SIZE;start++)
		{
			printf("%d   ",array[start]);
		}
		rot_time++;
		printf("\n\n");
	}

}    //end rotate



void Display()  //displaying an array elements
{
        int start;
        printf("\nThe array elements are:\n");
        for(start=0;start<SIZE;start++)
	{
                 printf("%d\t",array[start]);         
         }
 }//end of display() 

void Clear()    //clear buffer
{
	for(start=0;start<SIZE;start++)
	{
		array[start]=0;
	}
}   //end buffer


