/*
Write a C program to concatenate two strings using user-defined functions. 
The program should accept two strings from the user and pass them to a function that performs the concatenation. 
(strings, while/do while)
Function prototype:
void input(char *str);
void concatenate_strings(char *str1, char *str2);
void display(char *str);
*/

#include<stdio.h>

void input(char *str1, char *str2);
void concatenate_strings(char *str1, char *str2);
void display(char *str);

int main()
{
    char str1[100], str2[100];
    input(str1, str2);
    concatenate_strings(&str1, &str2);
    display(str1);
    return 0;
}
void input(char *str1, char *str2)
{
    printf("enter string 1: ");
    fgets(str1, 100, stdin);
    printf("enter string 2: ");
    fgets(str2, 100, stdin);
}

void concatenate_strings(char *str1, char *str2)
{
    int i=0,j=0;
    while(str1[i]!=0)
    {
        i++;
    }
    while(str2[j]!=0)
    {
        str1[i]=str2[j];
        i++;
        j++;
    }
    str1[i]='\0';
}

void display(char *str)
{
    printf(" the concatenated string is : %s", str);
}
