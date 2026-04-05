#include <stdio.h>
#include <stdlib.h>
int* create_array(int n); 
void initialize_array(int *arr, int n); 
void print_array(int *arr, int n); 
void delete_array(int **arr);
int main() {
    int n = 5;
    int *my_array = create_array(n);
    
    if (my_array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    
    initialize_array(my_array, n);
    print_array(my_array, n);
    delete_array(&my_array);
    
    return EXIT_SUCCESS;
}
int* create_array(int n) {
    return (int*)malloc(n * sizeof(int));
}
void initialize_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1; // Initialize with values 1 to n
    }
}
void print_array(int *arr, int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void delete_array(int **arr) {
    free(*arr);
    *arr = NULL; // Avoid dangling pointer
}

