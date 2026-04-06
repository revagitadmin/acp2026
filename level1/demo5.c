#include<stdio.h>

void read_array(int n, int arr[])
{
    for(int i=0;i<n;i++){
        printf("Enter the element at index %d: ",i+1);
        scanf("%d",&arr[i]);
    }
}
void print_array(int n, int arr[])
{
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void swap_array(int n, int a[n], int b[n])
{
    int temp[n];
    for(int i=0;i<n;i++){
        temp[i]=a[i];
        a[i]=b[i];
        b[i]=temp[i];
    }
}
int main()
{
    int n, arr[n], a[n], b[n];
    printf("Enter the  size of the arrays: ");
    scanf("%d",&n);  

    printf("Enter the elements of array 1:\n");
    read_array(n,a);
    printf("Enter the elements of array 2:\n");
    read_array(n,b);

    printf("Array 1 elements before swapping: ");
    print_array(n,a);
    printf("Array 2 elements before swapping: ");
    print_array(n,b);

    swap_array(n,a,b);

    printf("Array 1 after swapping: ");
    print_array(n,a);
    printf("Array 2 after swapping: ");
    print_array(n,b);

    return 0;
}


