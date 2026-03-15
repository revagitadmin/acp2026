#include<stdio.h>

void input(int n, float arr[n]);
int  find_max_index(int n, float arr[n]);
void output(float arr[], int max_index);

int main(void)
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n <= 0) 
    {
        printf("n must be greater than 0.\n");
        return 1;
    }
    float arr[n];
    input(n, arr);
    int max_idx = find_max_index(n, arr);
    output(arr, max_idx);
    return 0;
}

void input(int n, float arr[n])
{
    printf("Enter %d float value:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%f", &arr[i]);
    }
}

int find_max_index(int n, float arr[n])
{
    int max_idx = 0;
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > arr[max_idx])
         {
            max_idx = i;
        }
    }
    return max_idx;
}

void output(float arr[], int max_index)
{
    printf("\nMaximum value : %.2f\n", arr[max_index]);
    printf("Found at index: %d\n",    max_index);
}