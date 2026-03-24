#include <stdio.h>

// Function to input strings
void inputStrings(char str1[], char str2[]) {
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
}

// Manual string comparison
int compareStrings(char str1[], char str2[]) {
    int i = 0;

    // Loop until one string ends
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] > str2[i]) {
            return 1;   // str1 is greater
        } else if (str1[i] < str2[i]) {
            return -1;  // str2 is greater
        }
        i++;
    }

    // If both ended at same time → equal
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;
    }
    // If str1 ended first → str2 is longer
    else if (str1[i] == '\0') {
        return -1;
    }
    // If str2 ended first → str1 is longer
    else {
        return 1;
    }
}

// Function to output result
void output(int result) {
    if (result == 0)
        printf("\nStrings are equal.\n");
    else if (result == 1)
        printf("\nFirst string is greater.\n");
    else
        printf("\nSecond string is greater.\n");
}

int main() {
    char str1[50], str2[50];

    inputStrings(str1, str2);
    int result = compareStrings(str1, str2);
    output(result);

    return 0;
}