/*
Write a C program using user-defined functions to
i.	Accept names of two students.
ii.	Find the length of each student's name.
iii.	Compare which student's name is longer and display an appropriate message. (strings, while/do while, if)
Function Prototypes:
void input(char *name);
int calculate_name_length(char *name);
void compare_output(int len1, int len2);
*/

#include<stdio.h>
#include<string.h>

void input(char *name);
int calculate_name_length(char *name);
void compare_output(int len1, int len2);

int main()
{
    char name1[100];
    char name2[100];


    input(name1);
    input(name2);

    int name1_len = calculate_name_length(name1);
    int name2_len = calculate_name_length(name2);

    compare_output(name1_len, name2_len);

    return 0;
}

void input(char *name)
{
    printf("Entre the name of student: \n");
    fgets(name, 100, stdin );
}

int calculate_name_length(char *name)
{
    int i=0;
    while(name[i] !='\0'  && name[i] != '\n')
    {
        i++;
    }
    return i;
}

void compare_output(int len1, int len2)
{
    if(len1>len2)
    {
        printf("name 1 is greater than name 2 \n");
    }
    else if(len2>len1)
    {
        printf("name 2 is greater than name 1 \n");
    }
    else
    {
        printf("Both are equal\n");
    }
}