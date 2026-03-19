/*
Develop a modular C program to manage an integer array using dynamic memory allocation.
You must implement specific functions to allocate, initialize, display, and safely deallocate memory. 
This task ensures proficiency in preventing memory leaks and managing dangling pointers.
Function prototype:
int* create_array(int n); 
void initialize_array(int *arr, int n); 
void print_array(int *arr, int n); 
void delete_array(int **arr);
*/

 #include <stdio.h>
 
int* create_array(int n, int arr[]);
void initialize_array(int *arr, int n);
void print_array(int *arr, int n);
void delete_array(int **arr);
 
int main(void)
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    int *ptr = create_array(n, arr);
    initialize_array(ptr, n);
    print_array(ptr, n);
    delete_array(&ptr);
    if (ptr == NULL)
        printf("Pointer set to NULL successfully.\n");
    return 0;
}
 
int* create_array(int n, int arr[])
{
    return arr;
}
 
void initialize_array(int *arr, int n)
{
    printf("Enter %d elements:\n", n);
    for (int i=0;i<n;i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}
 
void print_array(int *arr, int n)
{
    printf("\nArray elements:\n");
    for (int i=0;i<n;i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}
 
void delete_array(int **arr)
{
    *arr = NULL;
}
