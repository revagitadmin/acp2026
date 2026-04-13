/*Write a modular C program to read n float values from the user, store them in an array and find the maximum value and its index. (array, passing arrays to functions, for loop, if statement)
Function prototype:
void input(int n, float arr[n]);
int find_max_index(int n, float arr[n]);
void output(float arr[ ], int max_index);
 */
#include <stdio.h>

// Function prototypes
void input(int n, float arr[n]);//declaring the fucntions here
int find_max_index(int n, float arr[n]);
void output(float arr[], int max_index);

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];  // Declare array of size n

    input(n, arr);  // Step 1: Input values
    int max_index = find_max_index(n, arr);  // Step 2: Find max index
    output(arr, max_index);  // Step 3: Output result

    return 0;
}

// Function to input array values
void input(int n, float arr[n]) {
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i);
        scanf("%f", &arr[i]);
    }
}

// Function to find index of maximum value
int find_max_index(int n, float arr[n]) {
    int max_index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

// Function to display result
void output(float arr[], int max_index) {
    printf("Maximum value = %.2f at index %d\n", arr[max_index], max_index);
}