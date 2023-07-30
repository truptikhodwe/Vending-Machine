#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>	//to include sleep [time-lapse]
//#include"func2.h"
#include"funcs_new.h"	//this is the header file which contains the prototypes of all the functions
int main()
{	
	S *snacks=NULL,*beverages=NULL,*chocolates=NULL,*biscuits=NULL,*cakes=NULL;		
	S * all_cat[]={snacks,beverages,chocolates,biscuits,cakes};				//this array contains structures of all the categories
	char * file[]={"snacks.txt","beverages.txt","chocolates.txt","biscuits.txt","cakes.txt"};//this array contains names of the included files
	S cart[50];
	int j=0;										//on incrementing value of j items can be added to the cart
	display_a();										
	sleep(2);		
	int select_1;										//to select between owner or customer service 						
	display_f();	
	printf("YOUR-CHOICE:");
	scanf("%d",&select_1);
	if(select_1==1)	
	{
		//if owner service is selected
	printf("Enter Password:\n");
	char pw[20];
	scanf("%s",pw);
	char code[]="whostheboss";
	int i=0;
	while(strcmp(pw,code)!=0)
	{
		i++;
		printf("SORRY,THE PASSWORD IS INCORRECT\n");
		printf("TRY AGAIN\n");
		if(i==4)
			break;
		scanf("%s",pw);
	}
	if(strcmp(pw,code)==0)
		{
		printf("CORRECT PASSWORD ENTERED\n");
		owner();
		}
	}
	else if (select_1==2)									//if customer service is selected
	{
		while(1)
		{	
			display_b();
			sleep(1);
			int select_2;								//to between categories or payment option
			printf("YOUR-CHOICE\n");
			scanf("%d",&select_2);
			if(select_2==6)							//payment option
				break;
			if(select_2>9 || select_2<1||(select_2>6 && select_2<=8))
			{
				printf("INVALID CHOICE:\n");
				sleep(1);
			}
			else
			{	
				all_cat[(select_2)-1]=view(all_cat[(select_2)-1],file[(select_2)-1]);//all the items of the selected category will be displayed
				int select_3;							//to select items or view cart or go back to select the category again
				while(1)
				{
					menu();
					printf("YOUR-CHOICE\n");
					scanf("%d",&select_3);
					if(select_3==3)				//to go back
						break;
					switch (select_3)	
					{
						case 1:				//to select the items
							{	
								
								int n,qty;
								scanf("%d %d",&n,&qty);
								select1(all_cat[(select_2)-1],file[(select_2)-1],n,qty,cart,&j);	//add required item and quantity
								break;
							}
						case 2:	
							{
								view_cart(cart,j);		//to view the cart
								break;
							}
						case 3:
							{break;}				//to go back
					//	case 4:
						//	{exit;}
					}
				}
			}
		}
		//billing part
		int amount;
		amount=total(cart,j);
		printf("Total:%d\n",amount);
		if(payment(amount))
		{
		bill(cart,amount,j);
		display_g();
		}
	}

/*	else if(select_1==3)
	{
	//	exit;
	}*/
}
