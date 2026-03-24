#include <stdio.h>
#include <stdlib.h>  // for malloc and free

// Function to create dynamic array
int* createScores(int n) {
    int *scores = (int*)malloc(n * sizeof(int));
    if (scores == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return scores;
}

// Function to input scores
void inputScores(int *scores, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter score of player %d: ", i + 1);
        scanf("%d", &scores[i]);
    }
}

// Function to display scores
void displayScores(int *scores, int n) {
    printf("\nTeam Scores:\n");
    for (int i = 0; i < n; i++) {
        printf("Player %d: %d\n", i + 1, scores[i]);
    }
}

// Function to delete scores safely
void deleteScores(int **scores) {
    free(*scores);
    *scores = NULL;  // prevent dangling pointer
}

int main() {
    int n;
    printf("Enter number of players: ");
    scanf("%d", &n);

    int *scores = createScores(n);   // Step 1: allocate memory
    inputScores(scores, n);          // Step 2: input values
    displayScores(scores, n);        // Step 3: display values
    deleteScores(&scores);           // Step 4: free memory

    return 0;
}