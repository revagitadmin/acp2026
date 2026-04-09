/*
Write a modular C program to create a structure Flight with flight_number, destination, and available_seats. Create an array of 4 flights. Write a program that takes a destination name from the user and checks if a flight is available to that location, displaying the flight number if found.
Function prototype:
void readFlights(int n, Flight_t f[]); 
void searchByDestination(int n, Flight_t f[], char searchDest[]);

*/

#include<stdio.h>
#include<string.h>

typedef struct {
    char flight_number[50];
    char destination[50];
    int available_seats;
} Flight_t;

void readflights(int n, Flight_t f[]);
void searchByDestination(int n, Flight_t f[], char searchDest[]);

int main()
{
int n=4;
Flight_t f[n];
readflights(n,f);
char searchDest[50];
printf("entre the destination where to go:");
scanf("%s",searchDest);
searchByDestination(n,f,searchDest);
return 0;
}

void readflights(int n, Flight_t f[])
{
    for (int i = 0; i < n; i++)
    {
        printf("enter flight no %d:",i+1);
        scanf("%s",f[i].flight_number);
        printf("enter destination %d:",i+1);
        scanf("%s",f[i].destination);
        printf("enter available seats in  %d:",i+1);
        scanf("%d",&f[i].available_seats);
    }
}

void searchByDestination(int n, Flight_t f[], char searchDest[])
{
    int flag = 0;
    for (int i=0;i<n;i++)
    {
        if (strcmp(f[i].destination, searchDest) == 0)
        {
            printf("Flight found:-\n");
            printf("Flight Number:- %s\n",f[i].flight_number);
            printf("Destination:- %s\n",f[i].destination);
            printf("Available Seats:- %d\n",f[i].available_seats);
            flag = 1;
        }
    }
    if (flag==0)
    {
        printf("flight Not found to your destination: %s\n", searchDest);
    }
}

