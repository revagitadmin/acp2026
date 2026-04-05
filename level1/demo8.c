#include <stdio.h>

// Function prototypes
void input(char *str);
void concatenate_strings(char *str1, char *str2);
void display(char *str);

int main() {
    char str1[200], str2[100];

    printf("Enter first string: ");
    input(str1);

    printf("Enter second string: ");
    input(str2);

    concatenate_strings(str1, str2);

    printf("Concatenated string: ");
    display(str1);

    return 0;
}

// Function to take input using fgets
void input(char *str) {
    fgets(str, 100, stdin);

    // Remove newline character
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}

// Function to concatenate using while loop
void concatenate_strings(char *str1, char *str2) {
    int i = 0, j = 0;

    // Move to end of first string
    while (str1[i] != '\0') {
        i++;
    }

    // Copy second string to first
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }

    // Add null terminator
    str1[i] = '\0';
}

// Function to display string
void display(char *str) {
    printf("%s\n", str);
}