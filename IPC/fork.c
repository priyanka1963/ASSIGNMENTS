/* creating multiple process*/

#include <stdio.h> 
#include<sys/types.h>
#include <unistd.h> 

 
int main() 
{ 
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    int odd = 0, even = 0, num, i; 
    num = fork(); 
   
    
    if (num > 0) 
	{ 
        for (i = 0; i < 10; i++) 
	{
	 
            if (arr[i] % 2 == 0) 
                even = even + arr[i]; 
        } 
        printf( "Parent process \n"); 
        printf( "Sum of even no. =%d\n",even);
    } 
  
  
    else { 
        for (i = 0; i < 10; i++) 
	{ 
            if (arr[i] % 2 != 0) 
                odd = odd + arr[i]; 
        } 
        printf( "Child process \n"); 
        printf("\nSum of odd no.=%d ",odd); 
    } 
    return 0; 
} 
