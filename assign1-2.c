#include <stdio.h>

void inputTemperatures(int n, float temps[n]);
float findHighest(int n, float temps[n]);
float findLowest(int n, float temps[n]);
void output(float max, float min);

int main() {

    float temps[7];
    float max, min;
    int n=7;
    inputTemperatures(n,temps);
    max= findHighest(n,temps);
    min= findLowest(n,temps);
    
    output(max,min);

    // Call function to input 7 temperatures
    // Call function to find highest temperature
    // Call function to find lowest temperature
    // Call function to display results

    return 0;
}

void inputTemperatures(int n, float temps[n]) {
    
    printf("Enter temperatures:\n");
    for(int i=0;i<7;i++)
    {
        scanf("%f",&temps[i]);
    }
    // Write code to read temperatures
}

float findHighest(int n, float temps[n]) {
    float max= temps[0];
    for(int i=1;i<7;i++)
    {
        if(temps[i] > max)
        {
            max =temps[i];
        }
    }
    return max;
    // Write code to find highest temperature
}

float findLowest(int n, float temps[n]) {
    float min = temps[0];
    for(int i=1;i<7;i++)
    {
        if(temps[i]<min)
        {
            min=temps[i];
        }
    }
    return min;
    // Write code to find lowest temperature
}

void output(float max, float min) {
    printf("Highest temperature: %.2f\n", max);
    printf("Lowest temperature: %.2f\n", min);
    // Write code to display results
}


//assign->2
#include <stdio.h>

/* Structure Definition */
typedef struct {
    int units;
    float rate, total_bill;
} ElectricityBill;

/* Function Prototypes */
ElectricityBill input();
ElectricityBill calculate_bill(ElectricityBill bill);
void output(ElectricityBill bill);

int main() {
    ElectricityBill bill;
    bill = input();
    bill= calculate_bill(bill);
    output(bill);

    // TODO: Call input function
    // TODO: Call calculate_bill function
    // TODO: Call output function

    return 0;
}

ElectricityBill input() {
    ElectricityBill bill;

    printf("Enter units consumed: ");
    // TODO: read units
    scanf("%d",&bill.units);

    printf("Enter rate per unit: ");
    // TODO: read rate
    scanf("%f",&bill.rate);

    return bill;
}

ElectricityBill calculate_bill(ElectricityBill bill) {

    // TODO: calculate total bill using units and rate
    if(bill.units < 50)
    {
        bill.total_bill = 0;
    }
    else if(bill.units <= 100)
    {
        bill.total_bill =bill.units * bill.rate; 
    }
    else
    {
        bill.total_bill =100*bill.rate + (bill.units - 100)* (bill.rate +5);
        printf("High consumption alert! Extra charge applied\n");
    }

    

    return bill;
}

void output(ElectricityBill bill) {
    printf("Units Consumed: %d\n", bill.units);
    printf("Rate per Unit: %.2f\n", bill.rate);
    printf("Total Bill: %.2f\n", bill.total_bill);
}