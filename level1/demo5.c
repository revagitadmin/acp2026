/*
Write a program to swap two integer arrays.  
Function prototype:
void read_array(int n, int arr[]);
void print_array(int n, int arr[]);
void swap_array(int n, int a[n], int b[n]);
*/

#include<stdio.h>

void read_array(int n, int arr[]);
void print_array(int n, int arr[]);
void swap_array(int n, int a[n], int b[n]);

int main()
{
    int n;
    printf("entre the size of array: ");
    scanf("%d", &n);
    int a[n];
    int b[n];
    
    printf("entre the elem of array 1: ");
    read_array(n,a);
    printf("entre the elem of array 2: ");
    read_array(n,b);

    printf("Before swap : Arrray 1 \n");
    print_array(n, a);
    printf("Before swap : Arrray 2 \n");
    print_array(n, b);

    swap_array(n,a,b);
    
    printf("After swap : Array 1 \n");
    print_array(n,a);
    printf("After swap : Array 2 \n");
    print_array(n,b);

    return 0;
}

void read_array(int n, int arr[])
{
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void print_array(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n",arr[i]);
    }
}

void swap_array(int n, int a[n], int b[n])
{
    for (int i=0; i<n;i++)
    {
        int temp = a[i];
        a[i]=b[i];
        b[i]=temp;
    }
}

