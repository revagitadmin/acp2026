/*
Write a program to swap two strings.  
Function prototype:
void read_string(char str[], int size);
void print_string(char str[]);
void swap_strings(char str1[], char str2[]);
*/

#include<stdio.h>

void read_string(char str[], int size);
void print_string(char str[]);
void swap_strings(char str1[], char str2[]);

int main(){
    int size=200;
    char str1[size];
    char str2[size];
    read_string(str1, size);
    read_string(str2, size);
    
    printf("-----BEFORE SWAP------");
    printf("\nString 1: ");
    print_string(str1);
    printf("\nString 2: ");
    print_string(str2);
    
    swap_strings(str1, str2);
    
    printf("\n-----AFTER SWAP------");
    printf("\nString 1: ");
    print_string(str1);
    printf("\nString 2: ");
    print_string(str2);

    return 0;
}

void read_string(char str[], int size)
{
    printf("Entre string : ");
    fgets(str,size,stdin);
}

void print_string(char str[])
{
    printf(" %s",str);
}

void swap_strings(char str1[], char str2[])
{
    char temp[200];
    int i=0;
    while(str1[i]!=0)
    {
        temp[i]=str1[i];
        i++;
    }
    temp[i]='\0';
i=0;
while(str2[i]!=0)
    {
        str1[i]=str2[i];
        i++;
    }
    str1[i]='\0';
i=0;
while(temp[i]!=0)
    {
        str2[i]=temp[i];
        i++;
    }
    str2[i]='\0';
}