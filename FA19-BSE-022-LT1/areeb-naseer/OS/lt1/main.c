#include <stdio.h>
#include "header.h"
int main()
{
	int x,y;
	float a,b;
	char choice ; 
	while(choice!='q')
	{
		printf("\n\n\t\t\tPlease enter +, -, *, / or q to quit \n\n");
		printf("please enter your choice\n");
		scanf("%c",&choice);
		switch(choice)
		{
			case '+':
			{
				printf("Please enter first number:\n");
				scanf("%d",&x);
	
				printf("Please enter second number:\n");
				scanf("%d",&y);
				printf("Sum of given numbers is %d\n",add(x,y));
				break;
			}
			case '-':
			{
				printf("Please enter first number:\n");
				scanf("%d",&x);
	
				printf("Please enter second number:\n");
				scanf("%d",&y);
				printf("Subtraction of given numbers is %d\n",sub(x,y));
				break;
			}
			case '*':
			{
				printf("Please enter first number:\n");
				scanf("%d",&x);
	
				printf("Please enter second number:\n");
				scanf("%d",&y);
				printf("Multiplication of given numbers is %d\n",mul(x,y));
				break;
			}
			case '/':
			{
				printf("Please enter first number:\n");
				scanf("%f",&a);
	
				printf("Please enter second number:\n");
				scanf("%f",&b);
				printf("Division of given numbers is %.2f\n",div(x,y));
				break;
			}
			case 'q':
			{
				printf("Thanks for using myclac\n");
				
				break;
			}
			
				
		}
	}	
}

