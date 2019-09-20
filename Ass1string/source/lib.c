#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "string.h"
#define MAX_SIZE 100

void stringlength()
{
	char s[100];
	int length=0;
	printf("Enter a string to calculate string length=\n");
	fgets(s,1000,stdin);
	while(s[length] != '\0')
	{
		length++;
	}
	printf("length of string=%d",length);
}


void truncate()
{
	char string1[50],string2[50],final[50];
	int num=0,j=0,pos,len;        		   //num is starting position of string1 & string 2   j is starting position of final string				  
	printf("Enter a string =");		
	fgets(string1,50,stdin);
	printf("Enter a position =");
	scanf("%d",&pos);
	printf("Enter length =");
	scanf("%d",&len);

	for(num=0;num<pos-1;num++)

		string2[num]=string1[num];


	for(num=pos+len-1;num<strlen(string1);num++,j++)
	{

		final[j]=string1[num];

	}
	strcat(string2,final);		
	printf("%s",string2);
}


void occurence()
{

	int i, j,l1, l2,count=0,count1=0;
	char str[50],sub[50];
	printf("\nEnter a string : ");
	scanf("%[^\n]s", str);

	l1 = strlen(str);

	printf("\nEnter a substring : ");
	scanf(" %[^\n]s", sub);

	l2 = strlen(sub);

	for (i = 0; i < l1;)
	{
		j = 0;
		count = 0;
		while ((str[i] == sub[j]))
		{
			count++;
			i++;
			j++;
		}
		if (count == l2)
		{
			count1++;                                   
			count = 0;
		}
		else
			i++;
	}    
	printf("%s occurs %d times in %s", sub, count1, str);
}


void replace()
{
	char text[100],word[10],rpwrd[10],str[10][10] ;
	int row=0,column=0,k=0,w,len3;
	printf("Enter a string\n");
	fgets(text, 100 ,stdin); 
	printf(" word to be replaced\n");
	scanf("%s",word);	
	printf(" new word to be replaced\n");
	scanf("%s",rpwrd);
	len3=strlen(text);

	for (k=0; k<len3; k++)                      
	{

		if (text[k]!=' ')
		{
			str[row][column] = text[k];
			column++;
		}
		else
		{
			str[row][column]='\0';
			column=0; row++;
		}
	}
	str[row][column]='\0';
	w=row;
	for(row=0; row<=w; row++)
	{
		if(strcmp(str[row],word)==0)
			strcpy(str[row],rpwrd);
		printf("%s ",str[row]);	
	}
}




 



