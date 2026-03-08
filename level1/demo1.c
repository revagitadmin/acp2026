/*Write a modular C program to read n float values from the user, 
store them in an array and find the maximum value and its index. (array, passing arrays to functions, 
for loop, if statement)
Function prototype:
void input(int n, float arr[n]);
int find_max_index(int n, float arr[n]);
void output(float arr[ ], int max_index);*/
#include<stdio.h>
void input(int,float *);
int find_max_index(int,float *);
void output(int,float *);
int main(){
    int n,l;
    printf("Enter number of values: ");
    scanf("%d",&n);
    float arr[n];
    input(n,arr);
    l=find_max_index(n,arr);
    output(l,arr);
    return 0;
}
void input(int x,float *a){
    for(int i=0;i<x;i++){
        printf("Enter element %d: ",i+1);
        scanf("%f",&a[i]);
    }
}
int find_max_index(int x,float *a){
    int max_index=0;
    for(int i=1;i<x;i++){
        if(a[i]>a[max_index]){
            max_index=i;
        }
    }
    return max_index;
}
void output(int x,float *a){
    printf("Maximum value in the array is %.2f at index %d\n",a[x],x);
}
