/*Write a program to swap two integer arrays.  
Function prototype:
void read_array(int n, int arr[]);
void print_array(int n, int arr[]);
void swap_array(int n, int a[n], int b[n]);*/

#include<stdio.h>
void read_array(int,int * );
void print_array(int,int * );
void swap_array(int,int *,int * );
int main(){

    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int a1[n],a2[n];
    read_array(n,a1);
    read_array(n,a2);
    print_array(n,a1);
    print_array(n,a2);
    swap_array(n,a1,a2);
    return 0;
}
void read_array(int x,int *arr){
    for(int i=0;i<x;i++){
        printf("Enter element %d of array: ",i+1);
        scanf("%d",&arr[i]);
    }
}
void print_array(int x,int *arr){
    printf("Elements of array:\n");
    for(int i=0;i<x;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void swap_array(int x,int *a,int *b){
    int temp=0;
    for(int i=0;i<x;i++){
        temp=a[i];
        a[i]=b[i];
        b[i]=temp;
    }
    printf("Elements of array 1 after swapping:\n");
    for(int i=0;i<x;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    printf("Elements of array 2 after swapping:\n");
    for(int i=0;i<x;i++){
        printf("%d\t",b[i]);
    }
    printf("\n");
}









