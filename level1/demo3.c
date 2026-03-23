#include <stdio.h>

typedef struct {
    float length;
    float width;
    float area;
} Rectangle;
Rectangle input()
{
    Rectangle rect;
    printf("Enter length: ");
    scanf("%f", &rect.length);
    printf("Enter width: ");
    scanf("%f", &rect.width);
    return rect;
}
void inputMany(int n, Rectangle rect[])
{
    for(int i = 0; i < n; i++)
    {
        printf("\nRectangle %d\n", i + 1);
        rect[i] = input();   
    }
}
void calculate_area(int n, Rectangle rect[])
{
    for(int i = 0; i < n; i++)
    {
        rect[i].area = rect[i].length * rect[i].width;
    }
}
int findLargestArea(int n, Rectangle rect[])
{
    int largest = 0;
    for(int i = 1; i < n; i++)
    {
        if(rect[i].area > rect[largest].area)
        {
            largest = i;
        }
    }
    return largest;
}


void output(int n, int largestIndex, Rectangle rect[])
{
    printf("\nAREAS OF RECTANGLES\n");
    for(int i = 0; i < n; i++)
    {
        printf("Rectangle %d Area = %.2f\n", i + 1, rect[i].area);
    }

    printf("\nLARGEST RECTANGLE\n");
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

    inputMany(n, rect);
    calculate_area(n, rect);

    largestIndex = findLargestArea(n, rect);

    output(n, largestIndex, rect);

    return 0;
}