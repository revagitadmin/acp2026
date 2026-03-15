#include<stdio.h>

struct rectangle{
    float length;
    float width;
    float area;
};

typedef struct rectangle Rectangle;

void input(int n, Rectangle rects[n])
{
    for(int i=1;i<=n;i++){
    printf("Enter the length and width of Rectangle %d: ",i);
    scanf("%f%f",&rects[i].length,&rects[i].width);
    }
}

void calculate_area(int n, Rectangle rects[n])
{
    for(int i=1;i<=n;i++){
    rects[i].area=rects[i].length*rects[i].width;
    }
}

int find_largest_index(int n, Rectangle rects[n])
{
    int largest_index=0;
    for(int i=1;i<=n;i++){
        if(rects[i].area>rects[largest_index].area){
            largest_index=i;
        }
    }
    return largest_index;
}

void output(int largest_index, Rectangle rects[])
{
    printf("The rectangle with the largest area is at index %d with area %.2f",largest_index,rects[largest_index].area);
}

int main()
{
    int n;
    printf("Enter the number of rectangles: ");
    scanf("%d",&n);
    
    Rectangle rects[n];
    input(n,rects);
    calculate_area(n,rects);

    int largest_index=find_largest_index(n,rects);
    output(largest_index,rects);
    return 0;
}