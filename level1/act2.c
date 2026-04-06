#include<stdio.h>

struct ElectricityBill{
    int units;
    float rate;
    float total_bill;
};

typedef struct ElectricityBill Ebill;

Ebill input()
{
    Ebill bill;
    printf("Enter number of units consumed: ");
    scanf("%d",&bill.units);
    printf("Enter rate per unit: ");
    scanf("%f",&bill.rate);
    return bill;
}

Ebill calculate_bill(Ebill bill)
{
    bill.total_bill=bill.units*bill.rate;

    if(bill.units>100){
        int extra_units=bill.units-100;
        float extra_charge=extra_units*5.0;
    }
}
