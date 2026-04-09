/*
Write a C program using functions to read the temperature of each day for a week (7 float values),
 store them in an array, and find the minimum and maximum temperature. (array,
  passing arrays to functions, for loop, if statement)
Function Prototypes:
void inputTemperatures(int n, float temps[n]);
float findHighest(int n, float temps[n]);
float findLowest(int n, float temps[n]);
void output(float max, float min);

*/

#include<stdio.h>

void inputTemperatures(int n, float temps[n]);
float findHighest(int n, float temps[n]);
float findLowest(int n, float temps[n]);
void output(float max, float min);

int main()
{
    int n;
    printf("Enter no of days in a week : ");
    scanf("%d", &n);
    float temps[n];
    inputTemperatures(n, temps);
    float max = findHighest(n, temps);
    float min = findLowest(n, temps);
    output(max, min);
    return 0;
}

void inputTemperatures(int n, float temps[n])
{
    for(int i=0;i<n;i++)
    {
        printf("entre temperature of day %d : ",i+1);
        scanf("%f", &temps[i]);
    }
}

float findHighest(int n, float temps[n])
{
    float max=temps[0];
    for(int i=0;i<n;i++)
    {
        if(temps[i]>max)
        {
            max=temps[i];
        }
    }
    return max;
}

float findLowest(int n, float temps[n])
{
    float min=temps[0];
    for(int i=0;i<n;i++)
    {
        if(temps[i]<min)
        {
            min=temps[i];
        }
    }
    return min;
}

void output(float max, float min)
{
    printf("the highest temperature is :%.2f\n", max);
    printf("the lowest temperature is :%.2f\n", min);
}
