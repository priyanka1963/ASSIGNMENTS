
/*write a program to short array in minimum steps.*/

#include<stdio.h>
#include "sort.h"

int nsortingarray(int size,int arr[100])
{

	int numc,j;
	for(numc=0;numc<size;numc++)
	{

		for(j=numc+1;j<size;j++)
		{	
			
			if(arr[numc]>arr[j])
			{
				arr[numc]=arr[numc]+arr[j];
				arr[j]=arr[numc]-arr[j];
				arr[numc]=arr[numc]-arr[j];
				
			}
			
		}
	
         }
    
	return 0;
 }


