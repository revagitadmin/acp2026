/*Accept the number of rectangles. For each rectangle, accept its length and width. Calculate and display the area of each rectangle. Determine and display the rectangle with the largest area.
typedef struct {
    float length;
    float width;
    float area;
} Rectangle;

void input(int n, Rectangle rects[n]);
void calculate_area(int n, Rectangle rects[n]);
int findLargestArea(int n, Rectangle rects[n]);
void output(int largestIndex, Rectangle rects[]);
*/
 #include <stdio.h>
 typedef struct {
    float length;
    float width;
    float area;
} Rectangle;

void input(int n, Rectangle rects[n]);
void calculate_area(int n, Rectangle rects[n]);
int findLargestArea(int n, Rectangle rects[n]);
void output(int largestIndex, Rectangle rects[]);
 
 int main() {
    int n;
    printf("enter the number of rectangles:\n");
    scanf("%d",&n);
    Rectangle rects[n];]
    input(n,rects);
    calculate_area(n,rects);
    int largest_index=findLargestArea(n,rects);
    output(largest_index,rects);

    
    
    
    return 0;
 }
 void input(int n,Rectangle rects[n]){
    for(int i=0;i<n;i++){
        printf("enter the length and breadth of rectangle %d:\n",i+1);
        scanf("%f%f",&rects[i].length,&rects[i].width);

    }
 }
 void calculate_area(int n,Rectangle rects[n]){
    for(int i=0;i<n;i++){
        rects[i].area=rects[i].length*rects[i].width;
    }

 }
 int findLargestArea(int n,Rectangle rects[n]){
    int largest_index=0;
    for(int i=1;i<n;i++){
        if(rects[i].area>rects[largest_index].area){
            largest_index=i;
        }

    }
    return largest_index;
 }
 void output(int largest_index,Rectangle rects[]){
    printf("the rectangle with the largest area is rectangle %d with area %.2f\n",largest_index+1,rects[largest_index].area);
 }