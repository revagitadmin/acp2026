/*Write a C program to compare areas of three rectangles and find the largest using functions and structure. (else-if ladder)
typedef struct {
    	char name[50];
    	float length;
    	float width;
    	float area;
} Rectangle;
Function prototype:
Rectangle input();
float calculate_area(Rectangle rect);
void compare_areas(Rectangle r1, Rectangle r2, Rectangle r3);
*/
#include <stdio.h>
#include <string.h>
typedef struct{
	char name[50];
	float length;
	float width;
	float area;
}Rectangle;
Rectangle input();
float calculate_area(Rectangle rect);
void compare_areas(Rectangle r1,Rectangle r2,Rectangle r3);
int main(){
	Rectangle r1,r2,r3;
	r1=input();
	r2=input();
	r3=input();
	r1.area=calculate_area(r1);
	r2.area=calculate_area(r2);
	r3.area=calculate_area(r3);
	compare_areas(r1,r2,r3);
	return 0;

}
Rectangle input(){
	Rectangle rect;
	printf("enter the name for the rectangle:");
	scanf("%s",rect.name);
	printf("enter the length for the rectangle:");
	scanf("%f",&rect.length);
	printf("enter the width for the rectangle:");
	scanf("%f",&rect.width);
	return rect;
}
float calculate_area(Rectangle rect){
	return rect.length*rect.width;
}
void compare_areas(Rectangle r1,Rectangle r2,Rectangle r3)
{
	if(r1.area>r2.area && r1.area>r3.area)
	{
		printf("the largest area is of rectangle %s with area %.2f",r1.name,r1.area);
	}
	else if(r2.area>r1.area && r2.area>r3.area)
	{
		printf("the largest area is of rectangle %s with area %.2f",r2.name,r2.area);
	}
	else
	{
		printf("the largest area is of rectangle %s with area %.2f",r3.name,r3.area);
	}
}