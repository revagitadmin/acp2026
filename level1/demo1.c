#include<stdio.h>

void input(int n,float arr[n]);
int find_max_index(int n,float arr[n]);
void output(int n,float arr[],int max_index);

void input(int n,float arr[n])
{
    printf("enter the %d elements:\n",n);

    for(int i=0;i<n;i++)
    {
        scanf("%f",&arr[i]);
    }
}

int find_max_index(int n,float arr[n])
{
    int max_index=0;

    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[max_index])
        {
            max_index=i;
        }
    }

    return max_index;
}

void output(int n,float arr[],int max_index)
{
    float max=arr[max_index];

    printf("maximum value=%.2f\n",max);
    printf("indices of maximum value:");

    for(int i=0;i<n;i++)
    {
        if(arr[i]==max)
        {
            printf("%d ",i);
        }
    }
}

int main()
{
    int n;

    printf("Enter number of elements:");
    scanf("%d",&n);

    float arr[n];

    input(n,arr);

    int max_index = find_max_index(n,arr);

    output(n,arr,max_index);

    return 0;
}