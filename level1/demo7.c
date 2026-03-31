/*

Write a C program to compare two strings using user-defined functions. The program should return:
•	0 if both strings are equal
•	1 if the first string is lexicographically greater
•	-1 if the second string is lexicographically greater
Function prototype:
void inputStrings(char str1[], char str2[]);
int compareStrings(char str1[], char str2[]);
void output(int result);

*/

#include<stdio.h>


void inputStrings(char str1[], char str2[]);
int comparestrings(char str1[], char str2[]);
void output(int result);

int main()
{
    char str1[100], str2[100];
    inputStrings(str1, str2);
    int result;
    result = comparestrings(str1, str2);
    output(result);
    return 0;
}

void inputStrings(char str1[], char str2[])
{
    printf("enter the string 1: ");
    scanf("%s",str1);
    printf("entre the string 2: ");
    scanf("%s",str2);
}

int comparestrings(char str1[], char str2[])
{
    for(int i=0; str1[i]!='\0' && str2[i]!='\0';i++)
    {
        if(str1[i]>str2[i])
        {
            return 1;
        }
        else if(str1[i]<str2[i])
        {
            return -1;
        }
    }
    return 0;

}

void output(int result)
{
    if(result==0)
    printf("both strings are equal");
    else if(result==1)
    printf("string 1 is greater than string 2");
    else
    printf("string 2 is greater than string 1");
}
