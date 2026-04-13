#include <stdio.h>
#include <string.h>

/* Structure Definition */
typedef struct{
    int flight_number;
    char destination[50];
    int seats;
}Flight;

/* Function Prototypes */
void input_flights(int n, Flight flights[n]);
int search_flights(int n, Flight flights[n], char destination[], int result[]);
void display(int count, int result[], Flight flights[]);

int main()
{
    int n=4; 
    // printf("Enter n:");
    // scanf("%d", &n);
    Flight flights[n];
    input_flights(n, flights);
    char dest[50];
    printf("Enter destination to search: ");
    scanf("%s", dest);
    int result[n];
    int count = search_flights(n, flights, dest, result);
    display(count, result, flights);
    return 0;
}

/* Function to input flight details */
void input_flights(int n, Flight flights[n])
{
    for(int i=0; i<n; i++)
    {
        printf("\nEnter details of flight %d\n", i+1);

        printf("Enter flight number: ");
        // write code
        scanf("%d", &flights[i].flight_number);

        printf("Enter destination: ");
        // write code
        scanf("%s", flights[i].destination);

        printf("Enter available seats:\n");
        // write code
        scanf("%d", &flights[i].seats);
    }
}

/* Function to search flights */
int search_flights(int n, Flight flights[n], char dest[], int result[])
{
    int count = 0;
    for(int i=0; i<n; i++){
        if(strcmp( dest, flights[i].destination) == 0)
        {
            result[count] = i;
            count++;
        }
    }
        // write condition using strcmp
        // store index in result[count]
    return count;
}

/* Function to display result */
void display(int count, int result[], Flight flights[])
{
    if(count == 0 ){
        printf("No flight available to the given destination\n");
    }
    else{
        printf("Flights available:\n");
        for(int i=0 ; i<count; i++)
        {
            int index = result[i];
            printf("Flight Number: %d\n", flights[index].flight_number);
        }
    }
}