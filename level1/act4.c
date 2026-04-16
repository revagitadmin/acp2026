#include <stdio.h>

typedef struct {
    char player_name[50];
    int jersey_number;
    int runs_scored;
} Player;

// Function to read player details
void readPlayers(int n, Player p[]) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Player %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", p[i].player_name);
        printf("Jersey Number: ");
        scanf("%d", &p[i].jersey_number);
        printf("Runs Scored: ");
        scanf("%d", &p[i].runs_scored);
    }
}

// Function to calculate average runs
float calculateAverageRuns(int n, Player p[]) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += p[i].runs_scored;
    }
    return (float)total / n;
}

int main() {
    int n = 11;  // fixed team size
    Player team[n];

    readPlayers(n, team);
    float avg = calculateAverageRuns(n, team);

    printf("\nAverage runs scored by the team: %.2f\n", avg);

    return 0;
}