#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct structure S;

struct structure
{
	char name[31]; 
        int weight; 
        int price; 
        int quantity; 
        S * next;
};

/*void display_1()
{
        printf("<<  PRESS-1  snacks       >>");
        printf("<<  PRESS-2  beverages    >>");
        printf("<<  PRESS-3  chocolates   >>");
        printf("<<  PRESS-4  biscuits     >>");
        printf("<<  PRESS-5  cakes        >>");
        printf("<<  PRESS-6  all_products >>");
        printf("<<  press-8  <<BACK>>     >>");
	printf("\n");
}*/

//to insert a new node in the linked list
S * insert_product(S * head,S * new)
{	
        S * ptr=head;
	//traversing through the linked list
        for(;ptr!=NULL && ptr->next!=NULL;ptr=ptr->next);
        if(head==NULL)
        {
                head=new;
                new->next=NULL;
        }
        else
        {
                ptr->next=new;
                new->next=NULL;
        }
        return head;
}

//to read input from text file and creating a linked list
S * read_file(char * filename,S * head)
{
        FILE * F;
        F=fopen(filename,"r");
        S a[20];  //an array of structures
        int i=0;
        for(;i<20;i++)
	{
                if(fscanf(F,"%s %d %d %d",a[i].name,&a[i].weight,&a[i].price,&a[i].quantity)==EOF)
                        break;
	}
	//linking the elements(structures) of array
        for(int k=0;k<i;k++)
	{
                S * ptr=(S *)(malloc(sizeof(S)));
                ptr=&a[k];
                head=insert_product(head,ptr);
        }
        return head;
}

//first node with matching n will be removed
S * delete(S * head,int n){
	//ptr1 to match n starting from head
	//ptr2 points to node previous to ptr1,starts with NULL value
	S *ptr1=head, *ptr2=NULL;
	//loop traverses ptr1 through nodes in the list till n is matched
	for(int i=1;ptr1!=NULL && i<n;i++,ptr1=ptr1->next)
		ptr2=ptr1;
	if(ptr1!=NULL)
	{
		if(ptr2!=NULL)
		{
			ptr2->next=ptr1->next;
			//free(ptr1);
			ptr1=NULL;
		}
		if(ptr1==head)  //if ptr1 is first node,change head
		{
			head=ptr1->next;
			//free(ptr1);
			ptr1=NULL;
		}
	}
	return head;
}

//to update the quantity of the item selected in the linked list 
S * update_list(S * head,int n,int k)
{
        S * ptr=head;
        for(int i=1;i<n;i++,ptr=ptr->next);
        if(ptr->quantity<=k)
                delete(head,n);
        else if(ptr->quantity>k)
                ptr->quantity=ptr->quantity-k;
        return head;
}

//to add quantity to an item in the linked list
S * update_list_add(S * head,int n,int k)
{
        S * ptr=head;
        for(int i=1;i<n;i++,ptr=ptr->next);
        ptr->quantity=ptr->quantity+k;
        return head;
}

//printing the content of all nodes in the list
void display(S * head)
{
	printf("%-10s %-20s %-10s %-10s %-10s\n"," ","ITEM","WEIGHT","PRICE","QUANTITY");
	for (int i=1; head!= NULL;head=head->next)
	{
		printf("PRESS %d    %-20s %-10d %-10d %-10d\n",i,head->name,head->weight,head->price,head->quantity);
		i++;
	}
	printf("\n");
}

//to copy nth node of a linked list of desired quantity k
S * copy_data(S * head,int n,int k)
{
        S * temp,* ptr=head;
        temp=(S *)(malloc(sizeof(S)));
        for(int i=1;ptr!=NULL && i<n;i++,ptr=ptr->next);
        strcpy(temp->name,ptr->name);
        temp->quantity=ptr->quantity;
        temp->price=ptr->price;
        temp->weight=ptr->weight;
        temp->next=NULL;
        if(k>temp->quantity)
                printf("Desired quantity is not available.");
        else
                temp->quantity=k;
        return temp;
}

//to update the contents of the file
void update_file(char *filename,S * head)
{
	FILE * F;
	F=fopen(filename,"w");
	S * ptr;
	ptr=head;
	for(;ptr!=NULL;ptr=ptr->next)
		fprintf(F,"%s %d %d %d\n",ptr->name,ptr->weight,ptr->price,ptr->quantity);
	fclose(F);
}

//to view the items of a particular category
S * view(S * cat,char * filename)
{
        cat=read_file(filename,cat);
        display(cat);
        sleep(1);
	return cat;
}

//to select a particular item in category and add it to cart
void select1(S * cat,char * filename,int n,int k,S cart[],int * j)
{
        S * copy;
        copy=copy_data(cat,n,k);
        strcpy(cart[*j].name,copy->name);
        cart[*j].price=copy->price;
        cart[*j].quantity=copy->quantity;
        (*j)++;
        printf("SUCCESSFULLY ADDED TO CART\n");
        update_list(cat,n,k);
        update_file(filename,cat);
}

//to view cart
void view_cart(S cart[],int j)
{
       /* if(j==0)
        {
                display_c();
        }*/
        //else
	if(j!=0)
        {
                printf("%-10s %-20s %-10s %-10s\n"," ","ITEM","PRICE","QUANTITY");
                for (int i=0;i<j;i++)
                {
                        printf("ITEM  %d    %-20s %-10d %-10d\n",i+1,cart[i].name,cart[i].price,cart[i].quantity);
                }
        }
}

