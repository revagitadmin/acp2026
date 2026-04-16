 Write a C program to check if the electricity units consumed exceed 100 using functions and structure. If they do, apply an extra charge of ₹5 per unit over 100 and display a warning message “High consumption alert! Extra charge applied”. (if statement)

typedef struct {

int units;

float rate;

float total_bill;

} ElectricityBill;

Function Prototypes:

ElectricityBill input();

ElectricityBill calculate_bill(ElectricityBill bill);

void output(ElectricityBill bill);

