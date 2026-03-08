/*Write a C program to compare areas of three rectangles and find the largest 
using functions and structure. (else-if ladder)
typedef struct {
    	char name[50];
    	float length;
    	float width;
    	float area;
} Rectangle;
Function prototype:
Rectangle input();
float calculate_area(Rectangle rect);
void compare_areas(Rectangle r1, Rectangle r2, Rectangle r3);*/
#include<stdio.h>
typedef struct{
    char name[50];
	float length;
	float width;
	float area;
}Rectangle;
Rectangle input(void);
float calculate_area(Rectangle r);
void compare_areas(Rectangle x,Rectangle y,Rectangle z);
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
Rectangle input(void){
	Rectangle r4;
	printf("Enter name of rectangle: ");
	scanf("%s",r4.name);
	printf("Enter length of rectangle: ");
	scanf("%f",&r4.length);
	printf("Enter width of rectangle: ");
	scanf("%f",&r4.width);
	return r4;
}
float calculate_area(Rectangle r){
	r.area=r.length*r.width;
	return r.area;
}
void compare_areas(Rectangle x,Rectangle y,Rectangle z){
	if((x.area>y.area)&&(x.area>z.area)){
		printf("%s has largest area = %.2f\n",x.name,x.area);
	}
	else if((y.area>x.area)&&(y.area>z.area)){
		printf("%s has largest area = %.2f\n",y.name,y.area);
	}
	else if((z.area>x.area)&&(z.area>y.area)){
		printf("%s has largest area = %.2f\n",z.name,z.area);
	}
	else{
		printf("Areas are equal\n");
	}
}






























