#include <stdio.h>

void input(int n, float arr[n])
{
    for(int i=0;i<n;i++)
    {
        printf("Enter the value of element %d: ",i+1);
        scanf("%f",&arr[i]);
    }
}

int find_max_index(int n, float arr[n])
{
    int max_index=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>arr[max_index]){
        max_index=i;
        }
    }
    return max_index;
}

void output(int max_index, float arr[])
{
    printf("Maximum value in the array is %.2f at index %d",arr[max_index],max_index);
}

int main()
{
    int n,max_index;
    printf("Enter the value of n:");
    scanf("%d",&n);
    float arr[n];
    input(n,arr);
    max_index= find_max_index(n,arr);
    output(max_index,arr);
    return 0;
}