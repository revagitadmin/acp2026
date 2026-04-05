#include <stdio.h>

void input(int n, float arr[n])
{
    for(int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
}

int find_max_index(int n, float arr[n])
{
    int maxindex = 0;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > arr[maxindex])
        {
            maxindex = i;
        }
    }
    return maxindex;
}

void output(float arr[], int maxindex)
{
    printf("Maximum value = %.2f\n", arr[maxindex]);
    printf("Index of maximum value = %d\n", maxindex);
}

int main()
{
    int n;
    printf("Enter size : ");
    scanf("%d", &n);

    float a[n];

    input(n, a);

    int max = find_max_index(n, a);

    output(a, max);

    return 0;
}