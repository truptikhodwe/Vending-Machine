#include<unistd.h>   //To include sleep(timelapse)
#include<stdio.h>
#include"funcs_new.h"  
void owner()
{
	S *snacks=NULL,*beverages=NULL,*chocolates=NULL,*biscuits=NULL,*cakes=NULL;
	S * all_cat[]={snacks,beverages,chocolates,biscuits,cakes};     //This array contains structures of all categories
	char * file[]={"snacks.txt","beverages.txt","chocolates.txt","biscuits.txt","cakes.txt"};       //This array contains the name of included files
	while(1)
	{
		display_x();     //prints the available choices for the owner
		sleep(1);
		int select_2;      //To select the choice of the owner
		printf("YOUR-CHOICE\n");
		scanf("%d",&select_2);
		if(select_2==6)
			break;
		if(select_2>9 || select_2<1||(select_2>6 && select_2<=8))
		{
			printf("INVALID CHOICE:\n");
			sleep(1);
		}
		else
		{	
			all_cat[(select_2)-1]=view(all_cat[(select_2)-1],file[(select_2)-1]);     //All the items of the selected category will be displayed
			int select_3;     //To select the item number
			while(1)
			{	printf("Choose the item\n");
				scanf("%d",&select_3);
				printf("PRESS 1 FOR ADDING NEW ITEM\n");
				printf("PRESS 2 FOR REMOVING AN ITEM\n");
				printf("PRESS 3 TO GO BACK\n");
				printf("YOUR CHOICE\n");
				int n;
				scanf("%d",&n);    //To make the choice whether the owner wants to add , remove or go back
				if(n==3)
					break;
				switch(n)
				{
				case 1:	 
				{
					int q;      
					printf("Enter the quantity to be added:\n");
					scanf("%d",&q);       //Takes the quantity as input
					all_cat[(select_2)-1]=update_list_add(all_cat[(select_2)-1],select_3,q);    //To add q quantity of the item in the list
					update_file(file[(select_2)-1],all_cat[(select_2)-1]);     //To update the file accordingly
					break;
				}
				
				case 2:
				{
					int q;
					printf("Enter quantity to be removed:\n");
					scanf("%d",&q);       //Takes the quantity as input
					all_cat[(select_2)-1]=update_list(all_cat[(select_2)-1],select_3,q);       //To remove q quantity of item in the list
                    update_file(file[(select_2)-1],all_cat[(select_2)-1]);     //To update the file accordingly
					break;
				}
				}
			}
		}
	}
}
 	
