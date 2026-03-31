/*
(a)	Write a C program to check if the electricity units consumed exceed 100 using functions and structure.
 If they do, apply an extra charge of ₹5 per unit over 100 and display a warning message 
 “High consumption alert! Extra charge applied”. (if statement)
typedef struct {
        int units;
    	float rate;
    	float total_bill;
} ElectricityBill;
Function Prototypes:
ElectricityBill input();
ElectricityBill calculate_bill(ElectricityBill bill);
void output(ElectricityBill bill);
(b)	Write a C program to check if the user qualifies for a free unit consumption scheme using functions and structure.
 Example: If consumption is less than 50 units, the bill is ₹0. (if statement)
typedef struct {
    	int units;
    	float rate;
    	float total_bill;
} ElectricityBill;
Function Prototypes:
ElectricityBill input();
ElectricityBill calculate_bill(ElectricityBill bill);
void output(ElectricityBill bill);
*/

#include<stdio.h>

typedef struct {
    int units;
    float rate;
    float total_bill;
} ElectricityBill;

ElectricityBill input();
ElectricityBill calculate_bill(ElectricityBill bill);
void output(ElectricityBill bill);

int main()
{
    ElectricityBill bill = input();
    bill = calculate_bill(bill);
    output(bill);
    return 0;
}

ElectricityBill input()
{
    ElectricityBill bill;
    printf("Enter units consumed: ");
    scanf("%d", &bill.units);
    printf("Enter rate per unit: ");
    scanf("%f", &bill.rate);
    bill.total_bill = 0;
    return bill;
}

ElectricityBill calculate_bill(ElectricityBill bill)
{
    if(bill.units<50){
        bill.total_bill=0;
    }
    else if (bill.units > 100)
    {
        bill.total_bill=(100*bill.rate)+((bill.units-100)*(bill.rate+5));
    }
    else
    {
        bill.total_bill = bill.units * bill.rate;
    }
    return bill;
}

void output(ElectricityBill bill)
{
    printf("Units Consumed:%d\n", bill.units);
    printf("Rate per unit:%.2f\n", bill.rate);
    printf("Total Bill:%.2f\n", bill.total_bill);
 
    if (bill.units<50)
    {
        printf("Congratulations! You qualify for the free unit consumption scheme.\n");
    }
    else if (bill.units>100)
    {
        printf("Warning: High consumption alert! Extra charge applied.\n");
    }
    else
    {
        printf("Normal consumption. No extra charges.\n");
    }
}
