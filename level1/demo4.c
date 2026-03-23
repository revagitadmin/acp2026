#include<stdio.h>
#include<string.h>
typedef struct
{
    int flight_number;
    char destination[50];
    int available_seats;
}Flight_t;
void readFlights(int n, Flight_t f[])
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter flight number: ");
        scanf("%d", &f[i].flight_number);

        printf("Enter destination: ");
        scanf("%s", f[i].destination);

        printf("Enter available seats: ");
        scanf("%d", &f[i].available_seats);
    }
}
void searchByDestination(int n, Flight_t f[], char searchDest[])
{
    int i, found = 0;
    for(i=0;i<n;i++)
    {
        if(strcmp(f[i].destination, searchDest) == 0)
        {
            printf("Flight available. Flight Number: %d\n", f[i].flight_number);
            found = 1;
        }
    }
    if(found==0)
    {
        printf("The flights are not available for the destination\n");
    }
    
}
int main()
{
    int n=4;
    Flight_t flights[4];
    char searchDest[50];
    readFlights(n, flights);
    printf("Enter the destination to go : ");
    scanf("%s",searchDest);
    searchByDestination(n, flights, searchDest);
    return 0;
    
}

