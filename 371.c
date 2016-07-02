#include "stdio.h"
#include "stdlib.h"

/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

*/

int getSum(int a, int b) {
    int sum = 0;
    int carry = 0;
    int i=0;
    int mask = 1;
    
    for(i=0;i<32;i++)						//int is 4 byte, so judge each bit by mask one by one
    {
    	//a= 1 and b=1
		if((a & mask) && (b & mask))			
		{
			if(carry == 1)
			{
				sum = sum | mask;	//set the ith bit 				
			}
			else 
			{
				sum = sum & (~mask);//clear the ith bit 		
			}
			carry = 1;			
		}
		//a=1 or b=1
		else if((a & mask) || (b & mask))	
		{
			if(carry == 1)
			{
				sum = sum & (~mask);//clear the ith bit 	
				carry = 1;
			}
			else
			{
				sum = sum | mask;	//set the ith bit 
				carry = 0;
			}
		}
		//a=0, b=0
		else 
		{
			if(carry == 1)
			{	
				sum = sum | mask;	//set the ith bit 
			}
			carry = 0;
		}
		mask = mask << 1;
    }
    return sum;
}

void main()
{
	int a =1, b=2;
	printf("%d\n",getSum(a,b));
}

