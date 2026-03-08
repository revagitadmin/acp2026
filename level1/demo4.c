/*Write a modular C program to create a structure Flight with flight_number, 
destination, and available_seats. Create an array of 4 flights. Write a program that takes a destination 
name from the user and checks if a flight is available to that location, displaying the flight number if found.
Function prototype:
void readFlights(int n, Flight_t f[]); 
void searchByDestination(int n, Flight_t f[], char searchDest[]);*/

#include<stdio.h>
#include<string.h>
typedef struct{
    char flight_number[10];
    char destination[50];
    int available_seats;
}Flight;
void readFlights(int,Flight * );
void searchByDestination(int,Flight *,char * );
int main(){
    int n=4;
    char dest[50];
    Flight f[n];
    readFlights(n,f);
    printf("Enter destination to search: ");
    scanf("%s",dest);
    searchByDestination(n,f,dest);
    return 0;
}
void readFlights(int n,Flight *arr){
    for(int i=0;i<n;i++){
        printf("Enter details of flight %d\n",i+1);
        printf("Enter flight number: ");
        scanf("%s",arr[i].flight_number);
        printf("Enter flight destination: ");
        scanf("%s",arr[i].destination);
        printf("Enter number of available seats: ");
        scanf("%d",&arr[i].available_seats);
    }
}
void searchByDestination(int n,Flight *arr,char *d){
    for(int i=0;i<n;i++){
        int result=strcmp(d,arr[i].destination);
        if(result==0){
            printf("Flight number %s is available to your destination\n",arr[i].destination);
            return;
        }
    }
    printf("No flights for your destination\n");
}
        













