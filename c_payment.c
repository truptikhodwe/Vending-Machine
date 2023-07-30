#include<stdio.h>

int payment(int amt)     //This function returns 1 if and only if the payment is done successfully
{
    float s,wallet;
    printf("PROCEEDING FOR TRANSACTION\n");
    printf("ENTER THE AMOUNT :  ");
    scanf("%f",&s);      //Amount entered by the user
    printf("\n");
    float short_amount;
    while(1)
    {
    if (s< amt)    //When the entered amount is less than the payable amount
    {
        short_amount = amt - s;
        printf("YOU ARE RS %f SHORT OF AMOUNT\n",short_amount);
        printf("PLEASE PROCEED TO PAY RS %f TO GET YOUR ITEMS\n",short_amount);
       

    }
    else if (s> amt)       //When the entered amount is greater than the payable amount
    {
        float excess_amount;
        excess_amount = s - amt;
        printf(" RS %f HAS BEEN ADDED TO YOUR WALLET",excess_amount);
        wallet = wallet + excess_amount;
        return 1;
    }
    else         //When the entered amount is equal to the payable amount
    {
        printf("PAYMENT SUCCESSFULL !\n");
        return 1;
    }
    amt = short_amount;
    printf("ENTER THE AMOUNT: \n");
    scanf("%f",&s);     //User again enters amount until the total amount is greater than or equal to the payable amount

        
    }
}