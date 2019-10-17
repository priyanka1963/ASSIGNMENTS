#include<stdio.h>
#include<stdlib.h>
#include "sort.h"


extern int arr[100];
int main()
{
int numc,size,arr[100];

	printf("Enter the size of elements:\n") ;
	scanf("%d",&size) ;

	printf("Enter the elements\n") ;
	for(numc=0;numc<size;numc++)
	{
		scanf("%d",&arr[numc]) ;
	
	}

	nsortingarray(size,arr);

	printf("Elements sorted in ascending order are\n");
	for(numc=0;numc<size;numc++)
	{
		printf("%d ",arr[numc]) ;
	}
	
	  
	
return 0;

}
