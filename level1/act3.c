/*
Write a C program to calculate electricity bills for multiple consumers using array of structures 
and functions and display the highest bill. (array of structures, for loop, if statement)
typedef struct {
    	int consumerID;
    	float unitsConsumed;
    	float billAmount;
}Bill;
Function Prototypes:
void input(int n, Bill bills[n]);
void calculate_Bills(int n, Bill bills[n]);
int findHighestBillIndex(int n, Bill bills[n]);
void displayHighestBill(int index, Bill bills[]);
*/

#include<stdio.h>

typedef struct {
    	int consumerID;
    	float unitsConsumed;
    	float billAmount;
        float rate;
} Bill;

void input(int n, Bill bills[n]);
void calculate_Bills(int n, Bill bills[n]);
int findHighestBillIndex(int n, Bill bills[n]);
void displayHighestBill(int index, Bill bills[]);

int main()
{
    int n;
    printf(" entre the number of customers: ");
    scanf("%d",&n);
    Bill bills[n];
    input(n, bills);
    calculate_Bills(n, bills);
    int max_index=findHighestBillIndex(n, bills);
    displayHighestBill(max_index, bills);
    return 0;
}

void input(int n, Bill bills[n])
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("Entre the custoumer %d id: ",i+1);
        scanf("%d",&bills[i].consumerID);
        printf("entre the Bill Amount");
        scanf("%f",&bills[i].unitsConsumed);
        printf("Enter the rate: ");
        scanf("%f",&bills[i].rate);
    }
}

void calculate_Bills(int n, Bill bills[n])
{
    int i;
    for(i=0;i<n;i++)
    {
        bills[i].billAmount = bills[i].rate * bills[i].unitsConsumed;
    }
}

int findHighestBillIndex(int n, Bill bills[n])
{
    int max_index=0;
    int i;
    for(i=1;i<n;i++)
    {
        if(bills[i].billAmount>bills[max_index].billAmount)
        {
            max_index=i;
        }
    }
    return max_index;
}

void displayHighestBill(int index, Bill bills[])
{
    printf("The custumer[%d] has highest bill of %.2f.",bills[index].consumerID,bills[index].billAmount);
}