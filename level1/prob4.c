#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        if (str[i] != str[j]) return 0;
        i++; j--;
    }
    return 1;
}

int main() {
    char str[50];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isPalindrome(str)) printf("Palindrome\n");
    else printf("Not Palindrome\n");
    return 0;
}