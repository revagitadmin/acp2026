/*weekly temperature readings(find min and max)*/
#include<stdio.h>
void inputTemperatures(int n,float temps[n])
{
    for(int i=0;i<n;i++)
    {
        printf("enter temperature %d: ", i+1);
        scanf("%f", &temps[i]);
    }
}
float findHighest(int n,float temps[n])
{
    float max=temps[0];
    for(int i=1;i<n;i++)
    {
        if(temps[i]>max)
        {
            max=temps[i];
        }
    }
    return max;
}
float findLowest(int n,float temps[n])
{
    float min=temps[0];
    for(int i=1;i<n;i++)
    {
        if(temps[i]<min)
        {
            min=temps[i];
        }
    }
    return min;
}
void output(float max,float min)
{
    printf("highest temperature:%.2f\n",max);
    printf("lowest temperature:%.2f\n",min);

}
int main()
{
    int n;
    printf("enter the number of days:");
    scanf("%d",&n);
float temps[n];
inputTemperatures(n,temps);
float max=findHighest(n,temps);
float min=findLowest(n,temps);
output(max,min);
return 0;
}