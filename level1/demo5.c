//swap two integer arrays
//wacp to swap two integr arrays
/*void read_array(int n.int arr[])
void print_array(int n,int arr[])
void swap_array(int n, int a[n],int b[n])
*/
#include<stdio.h>
void read_array(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
        printf("enter the element %d:",i+1);
        scanf("%d",&arr[i]);
    }
}
void print_array(int n,int arr[]){
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}
void swap_array(int n,int a[n],int b[n])
{
    for(int i=0;i<n;i++){
        int tem=a[i];
        a[i]=b[i];
        b[i]=tem;
    }
}
int main(){
    int n;
    printf("enter the size of the array:\n");
    scanf("%d",&n);
    int a[n],b[n];
    printf("enter the first array:\n");
    read_array(n,a);
    printf("enter the second array:\n");
    read_array(n,b);
    printf("before swapping:\n");
    print_array(n,a);
    print_array(n,b);
    swap_array(n,a,b);
    printf("after swapping:\n");
    print_array(n,a);
    print_array(n,b);
    return 0;
}