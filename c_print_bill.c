#include<stdio.h>
typedef struct structure S;  
//The structure used for our project

struct structure
{
        char name[31];
        int weight;
        int price;
        int quantity;
        S * next;
};

int total(S cart[],int j)    //This returns the total payable amount
{
	int sum=0;
	for(int i=0;i<j;i++)
	{
		sum+=(cart[i].price)*(cart[i].quantity);
	}
	return sum;
}

void bill(S cart[],int total,int j)     //This prints the order details in a bill format
{
	printf("%-10s %-20s %-10s %-10s\n"," ","ITEM","PRICE","QUANTITY");
	for(int i=0;i<j;i++)
		printf("ITEM  %d    %-20s %-10d %-10d\n",i+1,cart[i].name,cart[i].price,cart[i].quantity);
	printf("GRAND_TOTAL:%d\n",total);
}
