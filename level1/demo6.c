#include <stdio.h>
#include <stdlib.h>

// Create array dynamically
int* create_array(int n)
{
    int *arr = (int*)malloc(n * sizeof(int));

    if(arr == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    return arr;
}

// Initialize array
void initialize_array(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

// Print array
void print_array(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Delete array safely
void delete_array(int **arr)
{
    free(*arr);      // free memory
    *arr = NULL;     // avoid dangling pointer
}

int main()
{
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int *arr = create_array(n);

    if(arr == NULL)
        return 0;

    printf("Enter elements:\n");
    initialize_array(arr, n);

    printf("Array elements:\n");
    print_array(arr, n);

    delete_array(&arr);

    return 0;
}