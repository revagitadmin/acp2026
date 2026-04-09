/*
The sports department requires a digital system to track player performance for various matches
 where the team size varies dynamically. Design and implement a modular C program that utilizes 
 Dynamic Memory Allocation to manage these scores efficiently. The program must demonstrate clean
 coding principles by separating concerns into independent functions for memory reservation, data entry,
 mathematical processing, and output display. Specifically, the system must prompt the user for the number 
 of players, allocate the exact required memory, validate the allocation, read the scores, display the scores, 
 compute the total team score, and finally implement a safe deallocation strategy that prevents dangling pointers 
 by resetting the memory address to NULL after freeing.
  Function Prototypes:
•	int* allocate_scores(int n);
•	void read_scores(int *arr, int n);
•	int calculate_total(int *arr, int n);
•	void display_scores(int *arr, int n);
•	void delete_scores(int **arr);
*/

#include<stdio.h>
#include<stdlib.h>

int* allocate_scores(int n);
void read_scores(int *arr, int n);
int calculate_total(int *arr, int n);
void display_scores(int *arr, int n);
void delete_scores(int **arr);

int main()
{
    int n;

    printf("Entre number of playesr\n");
    scanf("%d",&n);

    int *scores = allocate_scores(n);
    if(scores == NULL) return 1;

    read_scores(scores,n);

    display_scores(scores, n);

    int total_scores = calculate_total(scores, n);
    printf("\nTotal score is %d\n",total_scores);

    delete_scores(&scores);

    if(scores==NULL)
    {
        printf("\nPointer is set to NULL.");
    }

    return 0;
    
}

int * allocate_scores(int n)
{
    int *arr = malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return arr;
}

void read_scores(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Entre score of player %d : ",i+1);
        scanf("%d",&arr[i]);
    }
}

void display_scores(int *arr,int n)
{
    printf("\n---player---scores---\n");
    for(int i=0;i<n;i++)
    {
        printf("Player %d : %d\n",i+1,arr[i]);
    }
}

int calculate_total(int *arr, int n)
{
    int total=0;
    for(int i=0;i<n;i++)
    {
        total=total+arr[i];
    }
    return total;
}

void delete_scores(int **arr)
{
    free(*arr);
    *arr = NULL;
}


