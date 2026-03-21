/*electricity bill for many people and find the highest of it...*/
#include<stdio.h>
typedef struct{
    int consumerID;
    float unitsconsumed;
    float billAmount;
}Bill;
void input(int n, Bill bills[n]){
    for(int i=0;i<n;i++)
    {
        printf("enter the consumerID:\n");
        scanf("%d",&bills[i].consumerID);
        printf("enter the units consumed:\n");
        scanf("%f",&bills[i].unitsconsumed);
    
    }
}
void calculate_bill(int n, Bill bills[n])
{
    for(int i=0;i<n;i++)
    {
        if(bills[i].unitsconsumed < 50)
        {
            bills[i].billAmount=0;
        }
        else if(bills[i].unitsconsumed >= 100 && bills[i].unitsconsumed <150)
        {
            bills[i].billAmount=bills[i].unitsconsumed*1.5;
        }
        else
        {
            bills[i].billAmount=bills[i].unitsconsumed*2;
        }

    }
}

void output(int n,Bill bills[n])
{
    printf("ConsumerID\tUnits Consumed\tBill Amount\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%.2f\t\t%.2f\n",bills[i].consumerID,bills[i].unitsconsumed,bills[i].billAmount);
    }

}
int main()
{
    int n;
    printf("enter the number of consumers:\n");
    scanf("%d",&n);
    Bill bills[n];
    input(n,bills);
    calculate_bill(n,bills);
    output(n,bills);
    return 0;
}