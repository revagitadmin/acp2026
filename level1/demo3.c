#include<stdio.h>
typedef struct {
    	float length;
    	float width;
    	float area;
} Rectangle;
void input(int n, Rectangle rect[n])
{
    for(int i = 0; i < n; i++)
    {
        printf("\nRectangle %d\n", i + 1);
        printf("Enter length: ");
        scanf("%f", &rect[i].length);
        printf("Enter width: ");
        scanf("%f", &rect[i].width);
    }
}
void calculate_area(int n, Rectangle rect[n])
{
    for(int i = 0; i < n; i++)
    {
        rect[i].area=rect[i].length*rect[i].width;
    }
}
int findLargestArea(int n, Rectangle rect[n])
{
    int largest=0;
    for(int i = 1; i < n; i++)
    {
        if(rect[i].area > rect[largest].area)
        {
            largest=i;
        }
    }
    return largest;
}
void output(int largestIndex, Rectangle rect[])
{
    printf("AREAS OF RECTANGLE\n");
    for(int i = 0; i <= largestIndex; i++)
    {
        printf("Rectangle %d Area = %.2f\n", i + 1, rect[i].area);
    }
    printf("AREA OF LARGEST RECTANGLE\n");
    printf("Length = %.2f\n", rect[largestIndex].length);
    printf("Width = %.2f\n", rect[largestIndex].width);
    printf("Area = %.2f\n", rect[largestIndex].area);
}
int main()
{
    int n, largestIndex;
    printf("Enter number of rectangles: ");
    scanf("%d", &n);
    Rectangle rect[n];
    input(n,rect);
    calculate_area(n,rect);
    largestIndex=findLargestArea(n,rect);
    output(largestIndex,rect);
    return 0;
}


