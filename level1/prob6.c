#include <stdio.h>

int compare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] > str2[i]) return 1;
        else if (str1[i] < str2[i]) return -1;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') return 0;
    else if (str1[i] == '\0') return -1;
    else return 1;
}

int main() {
    char str1[50], str2[50];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    int res = compare(str1, str2);
    if (res == 0) printf("Strings are Equal\n");
    else if (res == 1) printf("First string is Greater\n");
    else printf("Second string is Greater\n");
    return 0;
}