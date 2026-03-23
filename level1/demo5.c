#include <stdio.h>
void read_array(int n, int arr[]);
void print_array(int n, int arr[]);
void swap_array(int n, int a[n], int b[n]);

int main()
{
    int n;
    printf("Enter the size of the arrays: ");
    scanf("%d", &n);
    int a[100], b[100];
    printf("Enter the first array:\n");
    read_array(n, a);
    printf("Enter the second array:\n");
    read_array(n, b);
    swap_array(n, a, b);
    printf("After swapping:\n");
    printf("First array: ");
    print_array(n, a);
    printf("Second array: ");
    print_array(n, b);
    return 0;
}
void read_array(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
}
void print_array(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void swap_array(int n, int a[n], int b[n])
{
    for(int i=0; i<n; i++)
    {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

