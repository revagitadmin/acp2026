#include <stdio.h>

// Function to read array
void read_array(int n, int arr[])
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

// Function to print array
void print_array(int n, int arr[])
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to swap arrays
void swap_array(int n, int a[n], int b[n])
{
    for(int i = 0; i < n; i++)
    {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

int main()
{
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int a[n], b[n];

    printf("Enter elements of array A:\n");
    read_array(n, a);

    printf("Enter elements of array B:\n");
    read_array(n, b);

    swap_array(n, a, b);

    printf("After swapping:\n");

    printf("Array A: ");
    print_array(n, a);

    printf("Array B: ");
    print_array(n, b);

    return 0;
}