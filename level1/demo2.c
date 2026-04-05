#include<stdio.h>
typedef struct {
    	char name[50];
    	float length;
    	float width;
    	float area;
} Rectangle;
Rectangle input()
{
    Rectangle rect;
    printf("Enter the name of rectangle:");
    scanf("%s",rect.name);
    printf("Enter the length of rectangle:");
    scanf("%f",&rect.length);
    printf("Enter the width of rectangle:");
    scanf("%f",&rect.width);
    return rect;
}
float calculate_area(Rectangle rect)
{
    return rect.length*rect.width;
}
void compare_areas(Rectangle r1, Rectangle r2, Rectangle r3)
{
    if(r1.area > r2.area && r1.area > r3.area)
    {
        printf("\nRectangle with largest area: %s", r1.name);
        printf("\nArea = %.2f\n", r1.area);
    }
    else if(r2.area > r1.area && r2.area > r3.area)
    {
        printf("\nRectangle with largest area: %s", r2.name);
        printf("\nArea = %.2f\n", r2.area);
    }
    else
    {
        printf("\nRectangle with largest area: %s", r3.name);
        printf("\nArea = %.2f\n", r3.area);
    }
}
int main()
{
    Rectangle r1, r2, r3;

    printf("Enter details for Rectangle 1\n");
    r1 = input();
    r1.area = calculate_area(r1);

    printf("\nEnter details for Rectangle 2\n");
    r2 = input();
    r2.area = calculate_area(r2);

    printf("\nEnter details for Rectangle 3\n");
    r3 = input();
    r3.area = calculate_area(r3);

    compare_areas(r1, r2, r3);

    return 0;
}