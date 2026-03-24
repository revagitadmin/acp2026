#include<stdio.h>

struct flight{
    int flight_number;
    char destination[20];
    int available_seats;
};

typedef struct flight Flight;

void readFlights(int n, Flight f[])
{
    for(int i=0;i<n;i++)
    {
    printf("Flight %d details:",i+1);
    printf("Flight number: ");
    scanf("%d",&f[i].flight_number);
    printf("Flight destination: ");
    scanf("%s",&f[i].destination);
    printf("Available seats: ");
    scanf("%d",&f[i].available_seats);
    }
}