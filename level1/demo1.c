#include<stdio.h>
typedef struct{
    float l,w,a;
}rectangle;
void input(int,rectangle[]);
void calculate_area(int,rectangle[]);
int findLargestArea(int,rectangle[]);
void output(int,rectangle[]);
int main(){
    int n;
    printf("Enter number of rectangles: ");
    scanf("%d",&n);
    rectangle rects[n];
    input(n,rects);
    calculate_area(n,rects);
    int largestIndex=findLargestArea(n,rects);
    output(largestIndex,rects);
    return 0;
}
void input(int a,rectangle r[a]){
    for(int i=0;i<a;i++){
        printf("Enter length and width of rectangle %d: ",i+1);
        scanf("%f%f",&r[i].l,&r[i].w);
    }
}
void calculate_area(int x,rectangle r[x]){
    for(int i=0;i<x;i++){
        r[i].a=r[i].l * r[i].w;
    }
}
int findLargestArea(int x,rectangle r[x]){
    int index=0;
    for(int i=1;i<x;i++){
        if(r[i].a>r[index].a){
            index=i;
        }
    }
    return index;
}
void output(int x,rectangle arr[]){
    printf("Length of largest rectangle= %.2f\n",arr[x].l);
    printf("Breadth of largest rectangle= %.2f\n",arr[x].w);
    printf("Area of largest rectangle= %.2f\n",arr[x].a);
}



