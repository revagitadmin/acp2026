#include <stdio.h>
#include <string.h>
 
typedef struct {
    char name[50];
    float length;
    float width;
    float area;
} Rectangle;
 
Rectangle input();
float calculate_area(Rectangle rect);
void compare_areas(Rectangle r1, Rectangle r2, Rectangle r3);

int main(void)
{
    Rectangle r1 = input();
    Rectangle r2 = input();
    Rectangle r3 = input();
    r1.area = calculate_area(r1);
    r2.area = calculate_area(r2);
    r3.area = calculate_area(r3);
    compare_areas(r1, r2, r3);
    return 0;
}

Rectangle input()
{
    Rectangle r;
    printf("Enter rectangle name: ");
    scanf("%s", r.name);
    printf("Enter length of %s: ", r.name);
    scanf("%f", &r.length);
    printf("Enter width of %s: ", r.name);
    scanf("%f", &r.width);
    r.area = 0;
    return r;
}

float calculate_area(Rectangle rect)
{
    return rect.length * rect.width;
}

void compare_areas(Rectangle r1, Rectangle r2, Rectangle r3)
{
    printf("%s: %.2f\n", r1.name, r1.area);
    printf("%s: %.2f\n", r2.name, r2.area);
    printf("%s: %.2f\n", r3.name, r3.area);
    if (r1.area > r2.area && r1.area > r3.area)
    {
        printf("%s has the largest area: %.2f\n", r1.name, r1.area);
    }
    else if (r2.area > r1.area && r2.area > r3.area)
    {
        printf("%s has the largest area: %.2f\n", r2.name, r2.area);
    }
    else if (r3.area > r1.area && r3.area > r2.area)
    {
        printf("%s has the largest area: %.2f\n", r3.name, r3.area);
    }
    else
    {
        printf("Two or more rectangles have equal largest area: %.2f\n", r1.area);
    }
}