/*electricity bill*/
#include<stdio.h>
typedef struct{
    int units;
    float r;
    float total_bill;
}ElectricityBill;
ElectricityBill input()
{
    ElectricityBill bill;
    printf("enter the units consumed:");
    scanf("%d",&bill.units);
    printf("enter the rate per unit:");
    scanf("%f",&bill.r);

    return bill;
}
ElectricityBill calculate_bill(ElectricityBill bill)
{
    if(bill.units < 50)
    {
        bill.total_bill=0;

    }
    else if(bill.units >=100 && bill.units <150)
    { 
        int extra_units=bill.units-100;
        bill.total_bill=(bill.units*bill.r) + (extra_units*5);
        printf("\nHigh consumption! extra charge applied for %d units.\n",extra_units); 
    }
    else
    {
        bill.total_bill=bill.units*bill.r;
    }
    return bill;
}
void output(ElectricityBill bill)
{   
    printf("\n Units consumed: %d\n",bill.units);
    printf("Rate per unit: %.2f\n",bill.r);
    printf("Total electricity bill: %.2f\n",bill.total_bill);
}
int main()
{
    ElectricityBill bill;
    bill=input();
    bill=calculate_bill(bill);
    output(bill);
    return 0;
}
