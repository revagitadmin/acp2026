//swap two integer arrays
//wacp to swap two integr arrays
/*void read_array(int n.int arr[])
void print_array(int n,int arr[])
void swap_array(int n, int a[n],int b[n])
*/
#include<stdio.h>// for headerfile
void read_array(int n,int arr[])//we rre reading the array elements from the user 
{
    for(int i=0;i<n;i++)//for loop to read the array elements
    {
        printf("enter the element %d:",i+1);
        scanf("%d",&arr[i]);
    }
}
void print_array(int n,int arr[]){//we re printoing the array here with sapces
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}
void swap_array(int n,int a[n],int b[n])//we re swapping thr array 
{
    for(int i=0;i<n;i++){//for loop to swap the array elements 
        int tem=a[i];
        a[i]=b[i];
        b[i]=tem;
    }
}
int main(){//main function
    int n;//declaring the variable n
    printf("enter the size of the array:\n");
    scanf("%d",&n);//reading the input 
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