/*Create a structure  with flight_number, destination, and available_seats.
Take input for 4 flights. Ask the user for a destination and check if a flight is available to that location. Display the flight number if found.
void readFlights(int n, Flight_t f[]);
void searchByDestination(int n, Flight_t f[], char searchDest[]);
*/
#include <stdio.h>
#include <string.h>

typedef struct {
    int flight_number;
    char destination[50];
    int available_seats;
} Flight_t;

// Function to read flight details
void readFlights(int n, Flight_t f[]) {
    for (int i = 0; i < n; i++) {
        printf("Enter flight number: ");
        scanf("%d", &f[i].flight_number);
        printf("Enter destination: ");
        scanf("%s", f[i].destination);
        printf("Enter available seats: ");
        scanf("%d", &f[i].available_seats);
    }
}

// Function to search flights by destination
void searchByDestination(int n, Flight_t f[], char searchDest[]) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(f[i].destination, searchDest) == 0) {
            printf("\nFlight found! Flight Number: %d, Seats Available: %d\n",
                   f[i].flight_number, f[i].available_seats);
            found = 1;
        }
    }
    if (!found) {
        printf("\nNo flights available to %s\n", searchDest);
    }
}

int main() {
    int n = 4;
    Flight_t flights[n];

    readFlights(n, flights);

    char searchDest[50];
    printf("\nEnter destination to search: ");
    scanf("%s", searchDest);

    searchByDestination(n, flights, searchDest);

    return 0;
}