/*
Write a C program to count the number of vowels and consonants in a given string 
using a user-defined function. The program should accept a string from the user 
and pass it to a function that performs the counting logic. (strings, while/do while)
Function Prototypes:
void input(char *str);
void count(char *str, int *vowels, int *consonants);
void display(char *str, int vowels, int consonants);	4
*/

#include<stdio.h>

void input(char *str);
void count(char *str, int *vowels, int *consonants);
void display(char *str, int vowels, int consonants);

int main()
{
    char str[100];
    int vowels = 0;
    int consonants = 0;

    input(str);

    count(str, &vowels, &consonants);

    display(str, vowels, consonants);

    return 0;
}

void input(char *str)
{
    printf("Entre a string: \n");
    fgets(str, 100, stdin);
}

void count(char *str, int *vowels, int *consonants)
{
    int i = 0;

    *vowels = 0;
    *consonants = 0;

    while(str[i] != '\0' && str[i] != '\n')
    {
        char ch = str[i];

        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
               ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
            {
                (*vowels)++;
            }
            else
            {
                (*consonants)++;
            }
        }

        i++;
    }
}

void display(char *str, int vowels, int consonants)
{
    printf("\nEntered string: %s", str);
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
}
