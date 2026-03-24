#include <stdio.h>
#include <string.h>

// Function to input a string
void input(char *str) {
    scanf("%s", str);
}

// Function to swap two strings
void swapStrings(char *str1, char *str2) {
    char temp[100];  // temporary storage

    // Copy str1 into temp
    strcpy(temp, str1);

    // Copy str2 into str1
    strcpy(str1, str2);

    // Copy temp (original str1) into str2
    strcpy(str2, temp);
}

// Function to output strings
void output(char *str1, char *str2) {
    printf("\nAfter swapping:\n");
    printf("First string: %s\n", str1);
    printf("Second string: %s\n", str2);
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    input(str1);

    printf("Enter second string: ");
    input(str2);

    swapStrings(str1, str2);
    output(str1, str2);

    return 0;
}