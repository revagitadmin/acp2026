#include <stdio.h>
#include <string.h>

// Function prototypes
void inputStrings(char str1[], char str2[]);
int compareStrings(char str1[], char str2[]);
void output(int result);

int main() {
    char str1[100], str2[100];
    int result;

    inputStrings(str1, str2);
    result = compareStrings(str1, str2);
    output(result);

    return 0;
}

// Function to take input using fgets
void inputStrings(char str1[], char str2[]) {
    printf("Enter first string: ");
    fgets(str1, 100, stdin);

    printf("Enter second string: ");
    fgets(str2, 100, stdin);

    // Remove newline character if present
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';
    
}

// Function using strcmp
int compareStrings(char str1[], char str2[]) {
    int cmp = strcmp(str1, str2);

    if (cmp == 0)
        return 0;
    else if (cmp > 0)
        return 1;
    else
        return -1;
}

// Function to display result
void output(int result) {
    if (result == 0)
        printf("Both strings are equal.\n");
    else if (result == 1)
        printf("First string is greater.\n");
    else
        printf("Second string is greater.\n");
}