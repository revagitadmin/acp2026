/*
Write a C program using array of structures and functions to:
i.	Accept the number of rectangles.
ii.	For each rectangle, accept its length and width.
iii.	Calculate and display the area of each rectangle.
iv.	Determine and display the rectangle with the largest area. (array of structures, for loop, if statement)
typedef struct {
    	float length;
    	float width;
    	float area;
} Rectangle;
Function prototype:
*/

#include<stdio.h>

typedef struct {
    float length;
    float width;
    float area;
} Rectangle;

void input(Rectangle arr[], int n);
void calculate_area(Rectangle arr[], int n);
void display(Rectangle arr[], int n);
int  find_largest(Rectangle arr[], int n);

int main(void)
{
    int n;
    printf("Enter the no of rectangles: ");
    scanf("%d",&n);
    Rectangle arr[n];
    input(arr, n);
    calculate_area(arr, n);
    display(arr, n);
    int max_rec = find_largest(arr, n);
    printf("The Rectangle %d of Length: %f and  width: %f has largest area: %f\n",
           max_rec + 1, arr[max_rec].length, arr[max_rec].width, arr[max_rec].area);
    return 0;
}

void input(Rectangle arr[], int n){
    for (int i=0; i<n;i++){
        printf("entre the length of rectangle %d ", i+1);
        scanf("%f",&arr[i].length);
        printf("entre the width of rectangle %d ", i+1);
        scanf("%f",&arr[i].width);
    }
}

void calculate_area(Rectangle arr[],int n){
    for (int i=0;i<n;i++){
        arr[i].area =arr[i].length * arr[i].width;
    }
}

void display (Rectangle arr[],int n){
    for(int i=0;i<n;i++){
        printf("The area of rectangle %d is %f\n",i+1,arr[i].area);
    }
}

int  find_largest(Rectangle arr[], int n)
{
    int max_rec =0;
    for (int i=0;i<n;i++){
        if(arr [i].area > arr[max_rec].area){
            max_rec =i;
        }
    }
    return max_rec;
}
