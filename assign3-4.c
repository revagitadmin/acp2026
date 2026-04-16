#include <stdio.h>

typedef struct {
    char player_name[30];
    int jersey_number;
    int runs_scored;
} Player;

void readPlayers(int n, Player p[]);
float calculateAverageRuns(int n, Player p[]);

int main() {
    int n;
    scanf("%d",&n);
    Player p[11];
    float avg;
    readPlayers(n,p);
    avg= calculateAverageRuns(n,p);
   
    printf("Average Runs: %.2f\n", avg);

    return 0;
}

void readPlayers(int n, Player p[]) {
    int i;
    for(i=0;i<n;i++)
    {
       
        scanf("%s",p[i].player_name);
        
        scanf("%d",&p[i].jersey_number);
       
        scanf("%d",&p[i].runs_scored);
    }
    // TODO: Use a loop to read player_name, jersey_number, and runs_scored
}

float calculateAverageRuns(int n, Player p[]) {
    int i;
    int total_runs =0;
    float average;
    
    for(i=0;i<n;i++)
    {
        total_runs += p[i].runs_scored;
        
    }
    average =(float)total_runs /n;
  

    // TODO: Calculate total runs using a loop
    // TODO: Compute average = total_runs / n

    return average;
}
//assign->4
#include <stdio.h>

typedef struct {
    int consumerID;
    float unitsConsumed;
    float billAmount;
} Bill;

void input(int n, Bill bills[n]);
void calculate_Bills(int n, Bill bills[n]);
int findHighestBillIndex(int n, Bill bills[n]);
void displayHighestBill(int index, Bill bills[]);

int main() {
    int n;
    int highestIndex;
    

   
    printf("Enter number of consumers:\n");
    scanf("%d",&n);
    
    Bill bills[n];
    
    input(n,bills);
    calculate_Bills(n,bills);
    highestIndex = findHighestBillIndex(n,bills);
    displayHighestBill(highestIndex,bills);

    // Call function to input consumer details
    // Call function to calculate electricity bills
    // Call function to find index of highest bill
    // Call function to display highest bill

    return 0;
}

void input(int n, Bill bills[n]) {
    int i;
    
    printf("Enter consumer details:\n");
    
    for(i=0;i<n;i++)
    {
        printf("Enter Consumer ID:\n");
        scanf("%d",&bills[i].consumerID);
        
        printf("Enter Units Consumed:\n");
        scanf("%f",&bills[i].unitsConsumed);
    }
    // Write code to read consumerID and unitsConsumed
}

void calculate_Bills(int n, Bill bills[n]) {
    // Write code to calculate billAmount
    for(int i=0;i<n;i++)
    {
        bills[i].billAmount = bills[i].unitsConsumed * 5;

    }
}

int findHighestBillIndex(int n, Bill bills[n]) {
    // Write code to find index of highest bill
    int highestIndex =0;
    for(int i=1;i<n;i++)
    {
        if(bills[i].billAmount > bills[highestIndex].billAmount)
        {
            highestIndex=i;
        }
    }
    return highestIndex;
}

void displayHighestBill(int index, Bill bills[]) {
    printf("Highest Bill Consumer Details:\n");
    // Write code to display consumer details
    printf("Consumer ID: %d\n",bills[index].consumerID);
    printf("Units Consumed: %.2f\n",bills[index].unitsConsumed);
    printf("Bill Amount: %.2f\n",bills[index].billAmount);
}