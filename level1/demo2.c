#include<stdio.h>

struct rectangle{
    char name[50];
    float length;
    float width;
    float area;
};

typedef struct rectangle Rectangle;

Rectangle input(int rectNum)
{
    Rectangle rect;
    printf("Enter the name for the rectangle %d: ",rectNum);
    scanf("%s",rect.name);
    printf("Enter the length and width of rectangle %s: ",rect.name);
    scanf("%f%f",&rect.length,&rect.width);
    return rect;
}   

float calculate_area(Rectangle rect)
{
    return(rect.length*rect.width);
}

void compare_areas(Rectangle r1, Rectangle r2, Rectangle r3)
{
    if(r1.area>r2.area && r1.area>r3.area)
    {
        printf("Area of rectangle 1 which is %.2f is the largest.",r1.area);
    }
    else if(r2.area>r3.area)
    {
        printf("Area of rectangle 2 whcih is %.2f is the largest.",r2.area);
    }
    else
    {
        printf("Area of rectangle 3 which is %.2f is the largest.",r3.area);
    }
}

int main()
{
    Rectangle r1=input(1);
    Rectangle r2=input(2);
    Rectangle r3=input(3);
    r1.area=calculate_area(r1);
    r2.area=calculate_area(r2);
    r3.area=calculate_area(r3);
    compare_areas(r1,r2,r3);
}