/*manage integer array with dyanmic memory allocation*/
#include<stdio.h>
#include<stdlib.h>
int* create_array(int n);
void initialize_array(int *arr,int n);
void print_array(int *arr,int n);
void delete_array(int **arr);
int* create_array(int n)
{
    int *arr= (int*)malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("Memory allcoation failed\n");
        exit(1);

    }
    return arr;

}
//function tot initialize array
void initialize_array(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("enter the element %d:", i+1);
        scanf("%d",&arr[i]);
    }

}
void print_array(int *arr,int n){
    printf("\n array element");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void delete_array(int **arr){
    free(*arr);
    *arr=NULL;

}
int main()
{
    int n;
    printf("enter the size of the array:");
    scanf("%d",&n);
    int *arr= create_array(n);
    initialize_array(arr,n);
    print_array(arr,n);
    delete_array(&arr);
    return 0;
}